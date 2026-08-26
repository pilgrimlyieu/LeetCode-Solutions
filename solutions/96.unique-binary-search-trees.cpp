// @leet imports start
// Created: 2026-08-27 22:59:29

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= i - 1; j++) {
        dp[i] += dp[j] * dp[i - 1 - j];
      }
    }
    return dp.back();
  }
};
// @leet end

// @card idea 动态规划
// 新插入的节点可以将旧的 BST 拆成两部分。

// @card note
// 该数列是**卡特兰数 $h(n)$**，满足：
// $$
// h(n) = \sum_{i=0}^{n-1} h(i)h(n-1-i)
// $$
//
// 还有递推式与递推关系解：
// $$
// h(n) = \dfrac{2(2n-1)}{n+1} h(n-1) = \dfrac{\binom{2n}{n}}{n+1}
// $$

int main() {
  Solution s;
  CHECK(s.numTrees(4), 14);
  CHECK(s.numTrees(3), 5);
  CHECK(s.numTrees(2), 2);
  CHECK(s.numTrees(1), 1);
  for (int i = 1; i <= 10; i++) {
    DBG(i, s.numTrees(i));
  }
  return 0;
}
