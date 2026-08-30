// @leet imports start
// Created: 2026-08-30 19:26:55

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    return i == s.size();
  }
};
// @leet end

// @card hint
// 思考进阶的做法。

// @alt 动态规划
// 双指针的做法本质上在 `t` 中寻找下一个匹配字符，这与 `s` 无关，可以预处理。设 $\mathrm{dp}[i][j]$ 是 `t` 从 $i$ 开始后字符 $j$ 第一次出现的位置，则
// $$
// \mathrm{dp}[i][j] = \begin{cases}
//     i & \text{if } t[i] = j, \\
//     \mathrm{dp}[i+1][j] & \text{if } t[i] \ne j, \\
//     \mathrm{tlen} & \text{if } i = \mathrm{tlen}.
// \end{cases}
// $$
//
// $\mathrm{tlen}$ 值代表无法跳转，最后检查的时候应该是检查是否能跳转而非检查下标值是否超过，后者会有一个时间差错位。
class SolutionDP {
public:
  bool isSubsequence(string s, string t) {
    int slen = s.size(), tlen = t.size();
    vector<vector<int>> dp(tlen + 1, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
      dp[tlen][i] = tlen;
    }
    for (int i = tlen - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        dp[i][j] = (t[i] == 'a' + j) ? i : dp[i + 1][j];
      }
    }
    for (int i = 0; auto c : s) {
      if (dp[i][c - 'a'] == tlen) {
        return false;
      }
      i = dp[i][c - 'a'] + 1;
    }
    return true;
  }
};
// @alt end

int main() {
  SolutionDP s;
  CHECK(s.isSubsequence("abc", "ahbgdc"), true);
  CHECK(s.isSubsequence("a", "bbb"), false);
  CHECK(s.isSubsequence("axc", "ahbgdc"), false);
  return 0;
}
