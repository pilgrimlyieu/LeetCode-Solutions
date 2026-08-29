// @leet imports start
// Created: 2026-08-29 14:40:28

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (auto coin : coins) {
        if (i >= coin) {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp.back() <= amount ? dp.back() : -1;
  }
};
// @leet end

// @card idea 动态规划
// 初值全设为 `amount + 1` 是考虑到按极端情况（硬币是 1）也不可能用 `amount` 以上数目，因此也可以用极大数如 `INT_MAX`。
//
// 也可以用 `-1`，这样可以直接返回。但 `min` 那里就得判断是否有一个值为 `-1`。

int main() {
  Solution s;
  CHECK(s.coinChange("[1,2,5]"_vi, 11), 3);
  CHECK(s.coinChange("[2]"_vi, 3), -1);
  CHECK(s.coinChange("[1]"_vi, 0), 0);
  return 0;
}
