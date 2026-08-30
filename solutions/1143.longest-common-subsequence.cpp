// @leet imports start
// Created: 2026-08-30 16:37:20

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length(), len2 = text2.length();
    vector<int> dp(len1 + 1);
    for (auto c : text2) {
      for (int i = 1, prev = 0; i <= len1; i++) {
        int temp = dp[i];
        dp[i] = (text1[i - 1] == c) ? prev + 1 : max(dp[i], dp[i - 1]);
        prev = temp;
      }
    }
    return dp.back();
  }
};
// @leet end

// @card idea 动态规划
// 定义 $\mathrm{dp}[i][j]$ 表示 $\mathrm{text}_1[0..i], \mathrm{text}_2[0..j]$ 最长公共子序列长度（即前缀长度分别为 $i, j$），对 $\mathrm{dp}[i][j]$，考虑 $\mathrm{text}_1[i-1], \mathrm{text}_2[j-1]$：
// 1. 相等时有 $\mathrm{dp}[i][j]=\mathrm{dp}[i-1][j-1]+1$；
// 2. 不等时考虑两种情况的较大值（类似编辑距离）：
//    - 忽略 $\mathrm{text}_1[i-1]$，则 $\mathrm{dp}[i][j] = \mathrm{dp}[i-1][j]$；
//    - 忽略 $\mathrm{text}_2[j-1]$，则 $\mathrm{dp}[i][j] = \mathrm{dp}[i][j-1]$。
//
// 得到状态转移方程：
// $$
// \mathrm{dp}[i][j] = \begin{cases}
// \mathrm{dp}[i-1][j-1]+1, & \text{if } \mathrm{text}_1[i-1] = \mathrm{text}_2[j-1] \\
// \max(\mathrm{dp}[i-1][j], \mathrm{dp}[i][j-1]), & \text{otherwise}
// \end{cases}
// $$
//
// 可以用滚动数组优化空间复杂度。不过 $\mathrm{dp}[i][j]$ 同时依赖于 $\mathrm{dp}[i-1][j-1], \mathrm{dp}[i-1][j]$，即同时需要 $i-1$ 位置的旧值和新值：
// 1. 必须正向遍历 $i$，才能在更新 $\mathrm{dp}[i]$ 时保证 $\mathrm{dp}[i-1]$ 新值已被计算；
// 2. 因为只需要上一个位置的旧值，用一个变量 `prev` 在更新前保存旧值并传递到下一次即可。

int main() {
  Solution s;
  CHECK(s.longestCommonSubsequence("abcba", "abcbcba"), 5);
  CHECK(s.longestCommonSubsequence("abcde", "ace"), 3);
  CHECK(s.longestCommonSubsequence("abc", "abc"), 3);
  CHECK(s.longestCommonSubsequence("abc", "def"), 0);
  return 0;
}
