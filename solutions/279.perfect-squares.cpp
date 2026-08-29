// @leet imports start
// Created: 2026-08-29 14:52:31

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j * j <= i; j++) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp.back();
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.numSquares(12), 3);
  CHECK(s.numSquares(13), 2);
  return 0;
}
