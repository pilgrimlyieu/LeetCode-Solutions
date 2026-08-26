// @leet imports start
// Created: 2026-08-27 20:35:30

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int cost1 = 0, cost2 = 0;
    for (int i = 2; i <= cost.size(); i++) {
      int next = min(cost1 + cost[i - 2], cost2 + cost[i - 1]);
      cost1 = cost2;
      cost2 = next;
    }
    return cost2;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.minCostClimbingStairs("[10,15,20]"_vi), 15);
  CHECK(s.minCostClimbingStairs("[1,100,1,1,1,100,1,1,100,1]"_vi), 6);
  return 0;
}
