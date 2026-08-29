// @leet imports start
// Created: 2026-08-23 21:11:02

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int p = 0;
    for (int i = 1; i < prices.size(); i++) {
      p += max(0, prices[i] - prices[i - 1]);
    }
    return p;
  }
};
// @leet end

// @card idea 贪心
// 买入后立刻卖出和卖出后立刻买入不贡献利润，因此其实只需要统计相邻元素的递增总和即可。

// @alt 动态规划
// `p1` 代表当时不持有任何股票时的最大收益，`p2` 代表当时持有一股时的最大收益。
class SolutionDP {
public:
  int maxProfit(vector<int> &prices) {
    int p1 = 0, p2 = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
      int p1_next = max(p1, p2 + prices[i]);
      int p2_next = max(p2, p1 - prices[i]);
      p1 = p1_next;
      p2 = p2_next;
    }
    return p1;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.maxProfit("[7,1,5,3,6,4]"_vi), 7);
  CHECK(s.maxProfit("[1,2,3,4,5]"_vi), 4);
  CHECK(s.maxProfit("[7,6,4,3,1]"_vi), 0);
  return 0;
}
