// @leet imports start
// Created: 2026-09-07 13:13:49

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length(), maxLen = 0, start = 0;
    vector<int> dp(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 1 : min(dp[l + r - i], r - i + 1); // 奇数长度至少是 1
      while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
        k++;
      }
      dp[i] = k--;
      if (2 * k + 1 > maxLen) {
        start = i - k;
        maxLen = 2 * k + 1;
      }
      if (i + k > r) {
        l = i - k;
        r = i + k;
      }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 0 : min(dp[l + r - i + 1], r - i + 1); // 注意这里是 0
      while (i - 1 - k >= 0 && i + k < n && s[i - 1 - k] == s[i + k]) {
        k++;
      }
      dp[i] = k--;
      if (2 * k + 2 > maxLen) {
        start = i - 1 - k;
        maxLen = 2 * k + 2;
      }
      if (i + k > r) {
        l = i - 1 - k;
        r = i + k;
      }
    }
    return s.substr(start, maxLen);
  }
};
// @leet end

// @card idea Manacher
// 需要注意（更新后的）`k` 与 `dp[i]` 的含义：
// 1. `k` 用以标识边界，但要注意 `k = 0` 时其实已经有初始串了，对奇数串是 1，对偶数串是 2；
// 2. `R = dp[i]` 是有效半径长（包含中心），因此对奇数长度，子串长度为 `2R-1`，对偶数长度，字串长度为 `2R`；
// 3. 也可以直接观察两种情形左右边界分别是 `[i-k, i+k]` 与 `[i-1-k,i+k]`，长度分别是 `2k+1`, `2k+2`。

// @alt 中心扩展法
class SolutionCenter {
public:
  string longestPalindrome(string s) {
    int n = s.length(), maxLen = 0, start = 0;
    for (int center = 0; center < 2 * n - 1; center++) {
      int left = center / 2;
      int right = left + (center % 2);
      if (s[left] != s[right]) {
        continue;
      }
      int len = 1 + center % 2;
      while (left >= 0 && right < n && s[left] == s[right]) {
        if (len > maxLen) {
          maxLen = len;
          start = left;
        }
        left--;
        right++;
        len += 2;
      }
    }
    return s.substr(start, maxLen);
  }
};
// @alt end

// @card note
// 取 `min` 是因为这部分是有效的对称区域。

int main() {
  Solution s;
  CHECK(s.longestPalindrome("babad"), "bab");
  CHECK(s.longestPalindrome("cbbd"), "bb");
  return 0;
}
