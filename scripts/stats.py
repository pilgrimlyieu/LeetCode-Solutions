#!/usr/bin/env python3
"""扫描 solutions/ 生成 README.md 进度表。用法：just stats"""

import json
import re
import sys
from datetime import date
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CACHE = Path.home() / ".cache/nvim/leetcode/problemlist_cn"

DIFFICULTY = {
    "Easy": "🟢 简单",
    "Medium": "🟡 中等",
    "Hard": "🔴 困难",
}

HEADER = """# LeetCode Solutions

个人 LeetCode 题解（C++，leetcode.cn）。环境：WSL + Neovim + [leetcode.nvim](https://github.com/kawre/leetcode.nvim)，本地工具链见 `justfile`。

- 已完成：**{count}** 题（更新于 {today}）

| # | 题目 | 难度 | 题解 | 笔记 |
|--:|------|------|------|------|
"""


def load_cache() -> dict[str, dict]:
    try:
        data = json.loads(CACHE.read_text(encoding="utf-8"))["data"]
    except (OSError, KeyError, json.JSONDecodeError):
        return {}
    return {str(q["frontend_id"]): q for q in data}


def main() -> int:
    cache = load_cache()
    rows = []
    for f in sorted(
        (ROOT / "solutions").glob("*.cpp"),
        key=lambda p: int(re.match(r"(\d+)", p.name).group(1)),  # type: ignore[union-attr]
    ):
        m = re.match(r"(\d+)\.(.+)\.cpp$", f.name)
        if not m:
            continue
        qid, slug = m.group(1), m.group(2)
        q = cache.get(qid, {})
        title = q.get("title_cn") or q.get("title") or slug
        diff = DIFFICULTY.get(q.get("difficulty", ""), "")
        note = ROOT / "notes" / f"{qid}.{slug}.typ"
        note_cell = f"[笔记](notes/{note.name})" if note.exists() else ""
        rows.append(
            f"| {qid} | [{title}](https://leetcode.cn/problems/{slug}/)"
            f" | {diff} | [代码](solutions/{f.name}) | {note_cell} |"
        )

    readme = HEADER.format(count=len(rows), today=date.today().isoformat())
    readme += "\n".join(rows) + "\n"
    (ROOT / "README.md").write_text(readme, encoding="utf-8")
    print(f"README.md: {len(rows)} solutions")
    return 0


if __name__ == "__main__":
    sys.exit(main())
