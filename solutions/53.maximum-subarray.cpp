// @leet imports start
// Created: 2026-08-23 20:27:35

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size(), prevSum = nums.front(), maxSum = nums.front();
    for (int i = 1; i < n; i++) {
      prevSum = max(nums[i], prevSum + nums[i]);
      maxSum = max(maxSum, prevSum);
    }
    return maxSum;
  }
};
// @leet end

// @card idea 动态规划
// 记录以当前元素作为结尾的连续子数组的最大和，等于：
// 1. 当前元素单独作为子数组，因为前面最大和都是负数；
// 2. 连上前一个元素的最大和子数组。

// @alt 分治
// 使用四个状态参数 `lSum`, `rSum`, `mSum`, `iSum` 分别标记区间左/右起连续子数组最大和、区间内连续子数组最大和及区间和，然后可以进行分治。
//
// 虽然空间复杂度由于递归稍差，但该做法可用来构建「线段树」，解决任意子区间的查询问题。
class SolutionDAC {
public:
  int maxSubArray(vector<int> &nums) {
    struct status {
      int lSum, rSum, mSum, iSum;
    };
    auto get = [&](this auto &&self, int l, int r) -> status {
      if (r - l == 1) {
        return {nums[l], nums[l], nums[l], nums[l]};
      }
      int m = (l + r) / 2;
      auto lSta = self(l, m), rSta = self(m, r);
      return {max(lSta.lSum, lSta.iSum + rSta.lSum),
              max(rSta.rSum, lSta.rSum + rSta.iSum),
              max({lSta.mSum, rSta.mSum, lSta.rSum + rSta.lSum}),
              lSta.iSum + rSta.iSum};
    };
    return get(0, nums.size()).mSum;
  }
};
// @alt end

int main() {
  SolutionDAC s;
  CHECK(s.maxSubArray("[-2,1,-3,4,-1,2,1,-5,4]"_vi), 6);
  CHECK(s.maxSubArray("[1]"_vi), 1);
  CHECK(s.maxSubArray("[5,4,-1,7,8]"_vi), 23);
  return 0;
}
