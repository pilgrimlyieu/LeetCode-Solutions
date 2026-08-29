// @leet imports start
// Created: 2026-08-29 17:23:51

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    for (int minPrice = INT_MAX; auto price : prices) {
      minPrice = min(minPrice, price);
      ans = max(ans, price - minPrice);
    }
    return ans;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.maxProfit("[7,1,5,3,6,4]"_vi), 5);
  CHECK(s.maxProfit("[7,6,4,3,1]"_vi), 0);
  return 0;
}
