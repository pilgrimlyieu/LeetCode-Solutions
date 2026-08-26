// @leet imports start
// Created: 2026-08-27 21:20:57

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j]) {
          dp[j + 1] = 0;
        } else {
          dp[j + 1] += dp[j];
        }
      }
    }
    return dp[n];
  }
};
// @leet end

// @card idea 动态规划
// 依旧是按行的滚动数组。加了一个始终为 0 的哑节点代表 `-1` 列，这样可以避免特判边界。

int main() {
  Solution s;
  CHECK(s.uniquePathsWithObstacles("[[0,0,0],[0,1,0],[0,0,0]]"_vvi), 2);
  CHECK(s.uniquePathsWithObstacles("[[0,1],[0,0]]"_vvi), 1);
  return 0;
}
