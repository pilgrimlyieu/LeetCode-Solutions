// @leet imports start
// Created: 2026-08-20 22:39:39

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> set;
    auto dfs = [&](this auto &&self, int i) {
      if (i == nums.size()) {
        ans.push_back(set);
        return;
      }
      self(i + 1);
      set.push_back(nums[i]);
      self(i + 1);
      set.pop_back();
    };
    dfs(0);
    return ans;
  }
};
// @leet end

// @alt 二进制
class SolutionBinary {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    for (unsigned i = 0; i < (1 << nums.size()); i++) {
      vector<int> set;
      for (unsigned m = i; m; m &= m - 1) {
        set.push_back(nums[__builtin_ctz(m)]);
      }
      ans.push_back(set);
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  // 题面允许任意顺序，必要时改用 CHECK_ANYORDER
  CHECK_ANYORDER(s.subsets("[1,2,3]"_vi),
                 "[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]"_vvi);
  CHECK_ANYORDER(s.subsets("[0]"_vi), "[[],[0]]"_vvi);
  return 0;
}
