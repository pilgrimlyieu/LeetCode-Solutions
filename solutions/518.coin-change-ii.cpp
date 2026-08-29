// @leet imports start
// Created: 2026-08-29 13:03:39

#include "../utils.h"
#include <limits>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto coin : coins) {
      for (int i = coin; i <= amount; i++) {
        if (dp[i] <= INT_MAX - dp[i - coin]) { // 防溢出
          dp[i] += dp[i - coin];
        }
      }
    }
    return dp.back();
  }
};
// @leet end

// @card idea 动态规划
// 定义 `dp[i][j]` 为使用前 `j` 枚硬币凑成金额 `i` 的方案数，则有 `dp[i][j] = dp[i][j-1] + dp[i-coin][j]`，仅与 `j-1` 列相关，可以用滚动数组优化成一维数组。

// @card note
// 迭代顺序是先硬币再数额，因为所求是**组合数**，相当于先按硬币金额把连着的堆放在一起。
//
// 若是求**排列数**，则是先数额再硬币，每个位置都可以用任意一种硬币。

int main() {
  Solution s;
  CHECK(s.change(5, "[1,2,5]"_vi), 4);
  CHECK(s.change(3, "[2]"_vi), 0);
  CHECK(s.change(10, "[10]"_vi), 1);
  return 0;
}
