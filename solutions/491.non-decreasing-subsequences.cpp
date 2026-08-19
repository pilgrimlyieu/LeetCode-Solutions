// @leet imports start
// Created: 2026-08-20 23:31:03

#include "../utils.h"
#include <unordered_map>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> ans;
    vector<int> temp;
    function<void(int)> dfs = [&](int idx) {
      if (idx == size) {
        if (temp.size() > 1) {
          ans.push_back(temp);
        }
        return;
      }
      if (temp.empty() || nums[idx] >= temp.back()) {
        temp.push_back(nums[idx]);
        dfs(idx + 1);
        temp.pop_back();
      }
      if (temp.empty() || nums[idx] != temp.back()) {
        dfs(idx + 1);
      }
    };
    dfs(0);
    return ans;
  }
};
// @leet end

// @card idea
// 一旦当前已选序列末尾是 `x`，后面再遇到 `x`，就不能跳过。跟包含重复元素集合中选组合类似，将相同的组合在前面连续的时候就去掉了。
//
// 我最初的想法是「如果前面有相同的数没选，就不能选当前这个数」。但是这样要求一定得从最开始就选，从而会漏掉一些情形（如 `[2,1,2]` 只会输出 `[2,2]`，`[1,2]` 的第二个 `2` 因为第一个 `2` 没有被选择而无法选择）。

// @card note
// 可以使用 `function<void(int)>` 避免递归的 `this` 参数。不过可能内联效果没 lambda 那么好？

int main() {
  Solution s;
  // 题面允许任意顺序，必要时改用 CHECK_ANYORDER
  CHECK_ANYORDER(
      s.findSubsequences("[4,6,7,7]"_vi),
      "[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]"_vvi);
  CHECK_ANYORDER(s.findSubsequences("[4,4,3,2,1]"_vi), "[[4,4]]"_vvi);
  CHECK_ANYORDER(s.findSubsequences("[1,2,1,1]"_vi),
                 "[[1,1],[1,1,1],[1,2]]"_vvi);
  CHECK_ANYORDER(s.findSubsequences("[2,1,2]"_vi), "[[2,2],[1,2]]"_vvi);
  // CHECK_ANYORDER(s.findSubsequences("[100,90,80,70,60,50,60,70,80,90,100]"_vi),
  //                "[[4,4]]"_vvi);
  return 0;
}
