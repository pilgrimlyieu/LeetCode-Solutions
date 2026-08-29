// @leet imports start
// Created: 2026-08-29 13:58:05

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
      for (auto n : nums) {
        if (i >= n && dp[i] <= INT_MAX - dp[i - n]) {
          dp[i] += dp[i - n];
        }
      }
    }
    return dp.back();
  }
};
// @leet end

// @card idea 动态规划
// 求的是排列数。

int main() {
  Solution s;
  CHECK(s.combinationSum4("[1,2,3]"_vi, 4), 7);
  CHECK(s.combinationSum4("[9]"_vi, 3), 0);
  return 0;
}
