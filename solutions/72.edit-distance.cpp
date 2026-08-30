// @leet imports start
// Created: 2026-08-30 19:50:34

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size(), len2 = word2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; i++) {
      dp[i][0] = i;
    }
    iota(dp[0].begin(), dp[0].end(), 0);
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
        }
      }
    }
    return dp.back().back();
  }
};
// @leet end

// @card idea 动态规划
// 定义 $\mathrm{dp}[i][j]$ 为将 $\mathrm{word}_1[0..i]$ 转换成 $\mathrm{word}_2[0..j]$ 所需最少操作数，则有：
// $$
// \mathrm{dp}[i][j] = \begin{cases}
//     \mathrm{dp}[i-1][j-1], & \text{if } \mathrm{word}_1[i-1] = \mathrm{word}_2[j-1] \\
//     1 + \max \begin{cases}
//         \mathrm{dp}[i-1][j-1], & \text{替换操作} \\
//         \mathrm{dp}[i-1][j], & \text{删除操作} \\
//         \mathrm{dp}[i][j-1], & \text{插入操作}
//     \end{cases} & \text{if } \mathrm{word}_1[i-1] \ne \mathrm{word}_2[j-1]
// \end{cases}
// $$

// @alt 滚动数组优化
// $\mathrm{dp}[i]$ 同时需要旧值和新值，因此用 `prev` 保存旧值（注意 0 列的初值），同时递增遍历确保可以获取新值。
//
// 开始遍历的时候虽然 `j = 0`（已换成 1-base 更清晰），但实际上第 0 行是 `iota` 的值，实际上在计算 `j` 行（思考 $\mathrm{dp}[i][j]$），因此 `prev = dp[0]` 作为初值。
class SolutionRolling {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size(), len2 = word2.size();
    vector<int> dp(len1 + 1);
    iota(dp.begin(), dp.end(), 0);
    for (int j = 1; j <= len2; j++) {
      int prev = dp[0];
      dp[0]++;
      for (int i = 1; i <= len1; i++) {
        int temp = dp[i];
        if (word1[i - 1] == word2[j - 1]) {
          dp[i] = prev;
        } else {
          dp[i] = 1 + min({prev, dp[i], dp[i - 1]});
        }
        prev = temp;
      }
    }
    return dp.back();
  }
};
// @alt end

// @card note
// 对一个字符进行删除操作，等价于对另一个字符进行插入操作。
//
// 还需要注意 0 行/列初值，将空字符串转换为另一个字符串需要后者长度次操作。

int main() {
  Solution s;
  CHECK(s.minDistance("horse", "ros"), 3);
  CHECK(s.minDistance("intention", "execution"), 5);
  return 0;
}
