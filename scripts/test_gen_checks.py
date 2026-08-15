#!/usr/bin/env python3
"""gen_checks.py 单元测试。运行：python3 scripts/test_gen_checks.py"""

import unittest

from gen_checks import cpp_literal, extract_outputs, generate, strip_tags


def gen(md, cases, content=""):
    return generate(md, cases, extract_outputs(content), strip_tags(content))


class TestCppLiteral(unittest.TestCase):
    def test_scalars(self):
        self.assertEqual(cpp_literal("integer", "9"), "9")
        self.assertEqual(cpp_literal("boolean", "true"), "true")
        self.assertEqual(cpp_literal("double", "2.5"), "2.5")

    def test_string_keeps_or_adds_quotes(self):
        self.assertEqual(cpp_literal("string", '"III"'), '"III"')
        self.assertEqual(cpp_literal("string", "abc"), '"abc"')

    def test_character(self):
        self.assertEqual(cpp_literal("character", '"a"'), "'a'")

    def test_vector_suffixes(self):
        self.assertEqual(cpp_literal("integer[]", "[1,2]"), '"[1,2]"_vi')
        self.assertEqual(cpp_literal("list<list<integer>>", "[[1]]"), '"[[1]]"_vvi')
        self.assertEqual(cpp_literal("TreeNode", "[1,null,2]"), '"[1,null,2]"_tree')
        self.assertEqual(cpp_literal("ListNode", "[1,2]"), '"[1,2]"_list')

    def test_string_vector_uses_raw_string(self):
        self.assertEqual(cpp_literal("string[]", '["a","b"]'), 'R"(["a","b"])"_vs')

    def test_unknown_type(self):
        self.assertIsNone(cpp_literal("character[]", '["a"]'))


class TestExtractOutputs(unittest.TestCase):
    def test_cn_pre_blocks(self):
        content = (
            "<p>题面</p><pre>\n<strong>输入：</strong>nums = [2,7], target = 9\n"
            "<strong>输出：</strong>[0,1]\n<strong>解释：</strong>xx\n</pre>"
            "<pre>\n<strong>输入：</strong>nums = [3,3]\n<strong>输出：</strong>[1,2]\n</pre>"
        )
        self.assertEqual(extract_outputs(content), ["[0,1]", "[1,2]"])

    def test_en_and_halfwidth_colon(self):
        content = "<pre>\nInput: s = 'a'\nOutput: true\n</pre>"
        self.assertEqual(extract_outputs(content), ["true"])

    def test_pre_without_output_skipped(self):
        self.assertEqual(extract_outputs("<pre>只是格式说明</pre>"), [])


class TestGenerate(unittest.TestCase):
    TWO_SUM_MD = {
        "name": "twoSum",
        "params": [
            {"name": "nums", "type": "integer[]"},
            {"name": "target", "type": "integer"},
        ],
        "return": {"type": "integer[]"},
    }

    def test_standard_question(self):
        content = (
            "<p>你可以按任意顺序返回答案。</p>"
            "<pre>\n<strong>输出：</strong>[0,1]\n</pre>"
            "<pre>\n<strong>输出：</strong>[1,2]\n</pre>"
        )
        lines = gen(self.TWO_SUM_MD, ["[2,7,11,15]\n9", "[3,2,4]\n6"], content)
        self.assertIn("  Solution s;", lines)
        self.assertIn('  CHECK(s.twoSum("[2,7,11,15]"_vi, 9), "[0,1]"_vi);', lines)
        self.assertIn('  CHECK(s.twoSum("[3,2,4]"_vi, 6), "[1,2]"_vi);', lines)
        self.assertTrue(any("CHECK_ANYORDER" in l for l in lines))

    def test_output_count_mismatch_degrades_to_todo(self):
        content = "<pre>\n<strong>输出：</strong>[0,1]\n</pre>"
        lines = gen(self.TWO_SUM_MD, ["[2,7]\n9", "[3,3]\n6"], content)
        self.assertTrue(all("/* TODO */" in l for l in lines if "CHECK(" in l))
        self.assertTrue(any("请手动核对" in l for l in lines))

    def test_void_inplace(self):
        md = {
            "name": "moveZeroes",
            "params": [{"name": "nums", "type": "integer[]"}],
            "return": {"type": "void"},
        }
        content = "<pre>\n<strong>输出：</strong>[1,3,12,0,0]\n</pre>"
        lines = gen(md, ["[0,1,0,3,12]"], content)
        self.assertIn('  auto a1 = "[0,1,0,3,12]"_vi;', lines)
        self.assertIn(
            '  CHECK_INPLACE(s.moveZeroes(a1), a1, "[1,3,12,0,0]"_vi);', lines
        )

    def test_design_question_fallback(self):
        md = {"classname": "MinStack", "constructor": {"params": []}}
        case = '["MinStack","push","getMin"]\n[[],[-2],[]]'
        content = "<pre>\n<strong>输出：</strong>[null,null,-2]\n</pre>"
        lines = gen(md, [case], content)
        self.assertIn("  MinStack obj;", lines)
        self.assertTrue(any('["MinStack","push","getMin"]' in l for l in lines))
        self.assertTrue(any("[null,null,-2]" in l for l in lines))
        self.assertTrue(all(l.startswith("  //") for l in lines[1:]))

    def test_unknown_param_type_becomes_todo_arg(self):
        md = {
            "name": "reverseString",
            "params": [{"name": "s", "type": "character[]"}],
            "return": {"type": "void"},
        }
        lines = gen(md, ['["h","i"]'], "")
        self.assertTrue(any("/* TODO s = " in l for l in lines))

    def test_param_line_count_mismatch_degrades(self):
        lines = gen(self.TWO_SUM_MD, ["[2,7]"], "")  # 少了 target 一行
        self.assertTrue(any(l.startswith("  // 样例 1 输入:") for l in lines))
        self.assertFalse(any("CHECK(" in l for l in lines))

    def test_empty_metadata_lists_cases_as_comments(self):
        lines = gen({}, ["[1,2]\n3"], "")
        self.assertEqual(lines[0], "  Solution s;")
        self.assertTrue(any("样例 1" in l for l in lines))


if __name__ == "__main__":
    unittest.main()
