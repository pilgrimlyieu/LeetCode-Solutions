#!/usr/bin/env python3
"""根据题目元数据与样例生成 main() 中的 CHECK 行。

由 leetcode.lua 的 question_enter hook 调用：stdin 收 JSON
（meta_data / testcase_list / translated_content / content），stdout 输出
替换 `// @TESTAUTOGEN` 标记行的 C++ 代码（含两空格缩进）。

样例输入来自 exampleTestcaseList（每参数一行，机器可读）；期望输出 API
不单独提供，从题面 HTML 的 <pre> 样例块解析「输出：」行。任何无法生成
的位置降级为注释提示，整体永远输出可用内容并以 0 退出。

本地调试：python3 scripts/gen_checks.py < fixture.json
"""

import html
import json
import re
import sys

INDENT = "  "

# 类型 → lc/parse.h 的 UDL 后缀（两处必须保持同步）。
# character[] 无对应后缀（_vc 是裸字符语义，解析不了 ["a","b"]），故不收录。
SUFFIX = {
    "integer[]": "_vi",
    "list<integer>": "_vi",
    "integer[][]": "_vvi",
    "list<list<integer>>": "_vvi",
    "string[]": "_vs",
    "list<string>": "_vs",
    "string[][]": "_vvs",
    "list<list<string>>": "_vvs",
    "character[][]": "_vvc",
    "list<list<character>>": "_vvc",
    "double[]": "_vd",
    "list<double>": "_vd",
    "boolean[]": "_vb",
    "list<boolean>": "_vb",
    "TreeNode": "_tree",
    "ListNode": "_list",
}
RAW_STRING_SUFFIX = {"_vs", "_vvs", "_vvc"}  # 字面量内含引号，需要 R"(...)"
SCALARS = {"integer", "long", "double", "boolean"}


def cpp_literal(typ: str, raw: str) -> str | None:
    """样例文本 → C++ 实参表达式；映射不了返回 None（调用方降级）。"""
    raw = raw.strip()
    if typ in SCALARS:
        return raw
    if typ == "string":
        # testcase_list 里自带引号；题面输出偶尔不带，补上
        return raw if raw.startswith('"') else f'"{raw}"'
    if typ == "character":
        return "'{}'".format(raw.strip('"'))
    suffix = SUFFIX.get(typ)
    if suffix is None:
        return None
    if suffix in RAW_STRING_SUFFIX:
        return f'R"({raw})"{suffix}'
    return f'"{raw}"{suffix}'


def expected_expr(typ: str, out: str | None) -> str:
    if out is None:
        return "/* TODO */"
    lit = cpp_literal(typ, out)
    return lit if lit is not None else f"/* TODO 输出: {out} */"


def strip_tags(fragment: str) -> str:
    return re.sub(r"<[^>]+>", "", fragment)


def extract_outputs(content: str) -> list[str]:
    """从题面 HTML 的 <pre> 样例块中按序提取「输出：」行。"""
    outputs = []
    for pre in re.findall(r"<pre[^>]*>(.*?)</pre>", content, re.DOTALL):
        m = re.search(
            r"^\s*(?:输出|Output)\s*[：:]\s*(.*)$", strip_tags(pre), re.MULTILINE
        )
        if m:
            outputs.append(m.group(1).strip())
    return outputs


def case_comments(
    idx: int, case: str, params: list[dict], out: str | None
) -> list[str]:
    """单个样例的注释提示（生成失败时的降级形态）。"""
    vals = case.split("\n")
    names = [p.get("name", "?") for p in params]
    if names and len(names) == len(vals):
        joined = ", ".join(f"{n} = {v}" for n, v in zip(names, vals))
    else:
        joined = "; ".join(vals)
    return [
        f"{INDENT}// 样例 {idx} 输入: {joined}",
        f"{INDENT}// 样例 {idx} 输出: {out if out is not None else '(未解析)'}",
    ]


def generate(md: dict, cases: list[str], outputs: list[str], plain: str) -> list[str]:
    lines = []

    def out_at(i: int) -> str | None:  # i 为 1-based 样例序号
        return outputs[i - 1] if i <= len(outputs) else None

    # 设计题：调用序列生成暂未支持，给出实例与样例注释
    if "classname" in md:
        lines.append(f"{INDENT}{md['classname']} obj;")
        for i, case in enumerate(cases, 1):
            lines.extend(case_comments(i, case, [], out_at(i)))
        return lines

    name = md.get("name")
    params = md.get("params") or []
    ret_type = (md.get("return") or {}).get("type", "")

    lines.append(f"{INDENT}Solution s;")
    if not name or not params:
        for i, case in enumerate(cases, 1):
            lines.extend(case_comments(i, case, [], out_at(i)))
        return lines

    # 输出与样例数量不一致时全部按未解析处理，避免错配
    if len(outputs) != len(cases):
        if outputs:
            lines.append(
                f"{INDENT}// 注: 题面解析到 {len(outputs)} 个输出但有"
                f" {len(cases)} 个样例，期望值请手动核对"
            )
        outputs = []

    if "任意顺序" in plain or "any order" in plain.lower():
        lines.append(f"{INDENT}// 题面允许任意顺序，必要时改用 CHECK_ANYORDER")

    # void 返回：猜测第一个容器参数为被原地修改者，生成 CHECK_INPLACE
    inplace_i = None
    if ret_type == "void":
        inplace_i = next(
            (i for i, p in enumerate(params) if p.get("type") in SUFFIX), None
        )

    for i, case in enumerate(cases, 1):
        vals = case.split("\n")
        if len(vals) != len(params):
            lines.extend(case_comments(i, case, params, out_at(i)))
            continue
        out = out_at(i)
        args = []
        for p, v in zip(params, vals):
            lit = cpp_literal(p.get("type", ""), v)
            args.append(lit if lit is not None else f"/* TODO {p.get('name')} = {v} */")

        if ret_type == "void" and inplace_i is not None:
            var = f"a{i}"
            mod_type = params[inplace_i].get("type", "")
            call_args = list(args)
            call_args[inplace_i] = var
            lines.append(f"{INDENT}auto {var} = {args[inplace_i]};")
            lines.append(
                f"{INDENT}CHECK_INPLACE(s.{name}({', '.join(call_args)}), {var},"
                f" {expected_expr(mod_type, out)});"
            )
        elif ret_type == "void":
            tail = f" // 输出: {out}" if out is not None else ""
            lines.append(f"{INDENT}s.{name}({', '.join(args)});{tail}")
        else:
            lines.append(
                f"{INDENT}CHECK(s.{name}({', '.join(args)}),"
                f" {expected_expr(ret_type, out)});"
            )
    return lines


def main() -> int:
    try:
        data = json.load(sys.stdin)
    except json.JSONDecodeError as e:
        print(f"gen_checks: invalid JSON input: {e}", file=sys.stderr)
        return 2

    md = data.get("meta_data")
    if not isinstance(md, dict):
        md = {}
    cases = [c for c in (data.get("testcase_list") or []) if isinstance(c, str)]
    content = data.get("translated_content") or data.get("content") or ""
    if not isinstance(content, str):
        content = ""
    content = html.unescape(content).replace("\xa0", " ").replace("\r", "")

    lines = generate(md, cases, extract_outputs(content), strip_tags(content))
    print("\n".join(lines))
    return 0


if __name__ == "__main__":
    sys.exit(main())
