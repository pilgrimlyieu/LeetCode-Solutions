// @leet imports start
// Created: 2026-08-30 23:04:33

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size(), ans = 0;
    for (int center = 0; center < 2 * n - 1; center++) {
      int left = left = center / 2;
      int right = left + (center % 2);
      while (left >= 0 && right < n && s[left] == s[right]) {
        ans++;
        left--;
        right++;
      }
    }
    return ans;
  }
};
// @leet end

// @card idea 中心扩展法
// 回文串一定是关于某个中心对称的，一共有 $2n-1$ 个可能的中心（$n$ 个字符和 $n-1$ 个间隙）。对每个中心向两边扩展，相等时继续扩展，每扩展一步就得到一个更长的回文子串。`

// @alt 动态规划
class SolutionDP {
public:
  int countSubstrings(string s) {
    int n = s.size(), ans = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          ans++;
        }
      }
    }
    return ans;
  }
};
// @alt end

// @alt Manacher 算法
// 维护已经计算出的回文信息，最终答案即这两个数组之和（半径定义为从中心到边界的字符数，包含中心）：
// 1. `dp1[i]` 代表以 `i` 为中心的奇数长度回文半径；
// 2. `dp2[i]` 代表以 `i-1` 和 `i` 之间为中心的偶数长度回文半径。
//
// 算法维护当前最右回文边界 `[l, r]` 与其中心 `c`。计算 `i` 的半径时：
// 1. `i > r`：暴力扩展；
// 2. `i <= r`：利用对称点 `mirror = l + r - i` 的已知半径初始化减少扩展次数。
class SolutionManacher {
public:
  int countSubstrings(string s) {
    int n = s.size(), ans = 0;
    vector<int> dp1(n), dp2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {            // 奇数长度
      int k = (i > r) ? 1 : min(dp1[l + r - i], r - i + 1); // 初始半径为 1
      while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
        k++;
      }
      dp1[i] = k--;
      ans += dp1[i];
      if (i + k > r) {
        l = i - k;
        r = i + k;
      }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {                // 偶数长度
      int k = (i > r) ? 0 : min(dp2[l + r - i + 1], r - i + 1); // 初始半径为 0
      while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
      }
      dp2[i] = k--;
      ans += dp2[i];
      if (i + k > r) {
        l = i - k - 1;
        r = i + k;
      }
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.countSubstrings("abc"), 3);
  CHECK(s.countSubstrings("aaa"), 6);
  return 0;
}
