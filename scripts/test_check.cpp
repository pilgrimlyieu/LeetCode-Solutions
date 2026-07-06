// utils.h（lc/ 五头文件）回归测试。用法：just test-utils
#include "../utils.h"

int main() {
  /* --- parse.h：UDL 字面量 --- */
  CHECK("[1,3,-1]"_vi, std::vector<int>{1, 3, -1});
  CHECK("[[1,2],[3],[]]"_vvi, std::vector<std::vector<int>>{{1, 2}, {3}, {}});
  CHECK(R"(["ab","c"])"_vs, std::vector<std::string>{"ab", "c"});
  CHECK("[1.5,2]"_vd, std::vector<double>{1.5, 2.0});
  CHECK("[true,false]"_vb, std::vector<bool>{true, false});
  CHECK("[]"_vi, std::vector<int>{});
  CHECK("abc"_vc, std::vector<char>{'a', 'b', 'c'});

  /* --- 链表/树：构造与打印一致性 --- */
  CHECK("[1,2,3]"_list, "[1,2,3]"_list);
  CHECK("[]"_list == nullptr,
        true); // 空链表语义：nullptr（修复旧 [0] 单节点 bug）
  CHECK("[1,null,2,3]"_tree, "[1,null,2,3]"_tree);
  CHECK("[]"_tree == nullptr, true);
  // 树序列化尾部 null 裁剪
  CHECK(lc_check::stringify("[1,2,null]"_tree), "[1, 2]");

  /* --- print.h：泛型容器 --- */
  CHECK(lc_check::stringify(std::deque<int>{1, 2}), "[1, 2]");
  CHECK(lc_check::stringify(std::map<int, int>{{1, 2}}), "[(1, 2)]");
  CHECK(lc_check::stringify(std::make_tuple(1, 'a')), "(1, a)");
  CHECK(lc_check::stringify(std::optional<int>{}), "null");
  // 浮点：标量走 1e-5 数值容差（含 int/double 混用），容器内走 %.5f 序列化
  CHECK(0.1 + 0.2, 0.3);
  CHECK(1024.0, 1024); // 混用整型不因序列化格式差异误报
  CHECK(lc_check::stringify(2.0), "2.00000");

  /* --- check.h：标签 / anyorder / inplace / firstk --- */
  CHECK("labeled case", 1 + 1, 2);
  CHECK_ANYORDER(std::vector<int>{3, 1, 2}, "[1,2,3]"_vi);
  CHECK_ANYORDER("anyorder labeled", std::vector<int>{2, 1}, "[1,2]"_vi);

  auto v = "[0,1,0,3,12]"_vi;
  auto move_zeroes = [](std::vector<int> &nums) {
    std::stable_partition(nums.begin(), nums.end(),
                          [](int x) { return x != 0; });
  };
  CHECK_INPLACE(move_zeroes(v), v, "[1,3,12,0,0]"_vi);

  auto v2 = "[3,2,2,3]"_vi;
  auto remove_val = [](std::vector<int> &nums, int val) {
    return static_cast<int>(std::remove(nums.begin(), nums.end(), val) -
                            nums.begin());
  };
  CHECK_FIRSTK(remove_val(v2, 3), v2, "[2,2]"_vi);

  /* --- dbg.h：冒烟（stderr 输出，不参与断言，编译运行即视为通过） --- */
  auto nums = "[1,2]"_vi;
  DBG(nums, nums.size() + 1, std::make_pair(1, 2));

  /* --- S2V/V2S --- */
  CHECK(V2S(S2V("abc")), "abc");

  // 故意失败的用例，默认不编译：g++ -DCHECK_FAIL_DEMO 观察 FAIL
  // 输出与非零退出码
#ifdef CHECK_FAIL_DEMO
  CHECK(1, 2);
  CHECK("fail with label", "[1,2]"_vi, "[1,3]"_vi);
  CHECK_ANYORDER(std::vector<int>{1, 1}, "[1,2]"_vi);
#endif
  return 0;
}
