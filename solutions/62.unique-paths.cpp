// @leet imports start
// Created: 2026-08-27 20:44:45

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[j] += dp[j - 1];
      }
    }
    return dp[n - 1];
  }
};
// @leet end

// @alt 数学
// 移动 $m+n-2$ 次，答案即 $\dbinom{m+n-2}{m-1} = \dfrac{n \times \dots \times (m+n-2)}{(m-1)!}$。
//
// 下面的式子一定能整除，因为有 $\dbinom{x+1}{y+1} = \dbinom{x}{y} \dfrac{x+1}{y+1}$，或者想相邻 $n$ 个数之积一定能被 $n!$ 整除。
class SolutionMath {
public:
  int uniquePaths(int m, int n) {
    long long ans = 1;
    for (int a = n, b = 1; b < m; a++, b++) {
      ans = ans * a / b;
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  // 注: 题面解析到 4 个输出但有 2 个样例，期望值请手动核对
  CHECK(s.uniquePaths(3, 7), 28);
  CHECK(s.uniquePaths(3, 2), 3);
  return 0;
}
