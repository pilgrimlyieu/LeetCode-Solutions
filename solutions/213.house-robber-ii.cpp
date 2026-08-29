// @leet imports start
// Created: 2026-08-29 16:31:18

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int rob(vector<int> &nums) {
    int prev1 = 0, prev2 = 0, curr1 = nums[0], curr2 = 0;
    for (int i = 1; i < nums.size() - 1; i++) {
      int next1 = max(curr1, prev1 + nums[i]);
      int next2 = max(curr2, prev2 + nums[i]);
      prev1 = curr1, prev2 = curr2;
      curr1 = next1, curr2 = next2;
    }
    return max({curr1, curr2, prev2 + nums.back()});
  }
};
// @leet end

// @card idea 动态规划
// 环形考虑是否偷 0 位即可，即考虑 `0..len-1` 与 `1..len`。在一次遍历中完成：
// 1. `{prev,curr}1` 代表选择 0 位，`{prev,curr}2` 代表不选择 0 位；
// 2. 同时遍历 `1..len-1`，在最后的时候额外计算 `curr2`，因此在三个值之间取最大值。

int main() {
  Solution s;
  CHECK(s.rob("[2,3,2]"_vi), 3);
  CHECK(s.rob("[1,2,3,1]"_vi), 4);
  CHECK(s.rob("[1,2,3]"_vi), 3);
  return 0;
}
