// @leet imports start
// Created: 2026-08-20 23:17:34

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<vector<int>> ans;
    vector<int> temp;
    auto dfs = [&](this auto &&self, int start) -> void {
      ans.push_back(temp);
      for (int i = start; i < size; i++) {
        if (i > start && nums[i] == nums[i - 1]) {
          continue;
        }
        temp.push_back(nums[i]);
        self(i + 1);
        temp.pop_back();
      }
    };
    dfs(0);
    return ans;
  }
};
// @leet end

// @alt 二进制
class SolutionBinary {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<vector<int>> ans;
    for (unsigned i = 0; i < (1 << size); i++) {
      vector<int> temp;
      for (unsigned m = i; m; m &= m - 1) {
        int idx = __builtin_ctz(m);
        if (idx && (i >> (idx - 1) & 1) == 0 && nums[idx] == nums[idx - 1]) {
          goto out;
        }
        temp.push_back(nums[idx]);
      }
      ans.push_back(temp);
    out:
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  // 题面允许任意顺序，必要时改用 CHECK_ANYORDER
  CHECK(s.subsetsWithDup("[1,2,2]"_vi), "[[],[1],[1,2],[1,2,2],[2],[2,2]]"_vvi);
  CHECK(s.subsetsWithDup("[0]"_vi), "[[],[0]]"_vvi);
  return 0;
}
