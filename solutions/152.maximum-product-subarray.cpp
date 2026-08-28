// @leet imports start
// Created: 2026-08-28 13:36:37

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int maxProd = nums.front(), prevMax = maxProd, prevMin = maxProd;
    for (int i = 1; i < nums.size(); i++) {
      int prod1 = nums[i] * prevMin, prod2 = nums[i] * prevMax;
      prevMin = min({nums[i], prod1, prod2});
      prevMax = max({nums[i], prod1, prod2});
      maxProd = max(maxProd, prevMax);
    }
    return maxProd;
  }
};
// @leet end

// @card idea 动态规划
// 因为可能因为负数而反转，因此同时需要记录最小值。

// @card note
// 还有一种一遍遍历的思考：
// 1. 最大子数组两边不可能是正整数，否则可以纳入；
// 2. 最大子数组两边不可能同为负数，否则也可以纳入抵消负号。
//
// 因此最大子数组一定有一端是 0 或者数组端点，不断遍历，遇到 0 更新即可。当然还是 DP 写起来简单点。

int main() {
  Solution s;
  CHECK(s.maxProduct("[2,3,-2,4]"_vi), 6);
  CHECK(s.maxProduct("[-2,0,-1]"_vi), 0);
  return 0;
}
