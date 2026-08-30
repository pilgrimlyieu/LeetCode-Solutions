// @leet imports start
// Created: 2026-08-30 14:03:16

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> tails;
    for (auto num : nums) {
      auto it = lower_bound(tails.begin(), tails.end(), num);
      if (it == tails.end()) {
        tails.push_back(num);
      } else {
        *it = num;
      }
    }
    return tails.size();
  }
};
// @leet end

// @card idea 贪心 + 二分
// 希望每个长度的递增子序列的末尾元素尽可能小，这样后续的元素更容易接在后面，从而可能形成更长的子序列。
//
// 维护一个数组 `tails`，其中 `tails[k]` 表示长度为 `k+1` 的所有递增子序列中，末尾元素可能的最小值。显然其满足严格递增条件。
//
// 需要注意 `tails` 本身 不一定是真实的 LIS 序列，它只是记录了每个长度的最小尾元素。

// @alt 动态规划
class SolutionDP {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size(), ans = 1;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      dp[i] = 1;
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
          ans = max(ans, dp[i]);
        }
      }
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.lengthOfLIS("[10,9,2,5,3,7,101,18]"_vi), 4);
  CHECK(s.lengthOfLIS("[0,1,0,3,2,3]"_vi), 4);
  CHECK(s.lengthOfLIS("[7,7,7,7,7,7,7]"_vi), 1);
  return 0;
}
