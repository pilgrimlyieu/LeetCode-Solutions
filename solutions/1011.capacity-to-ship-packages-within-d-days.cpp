// @leet imports start
// Created: 2026-08-19 14:36:15

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int right = accumulate(weights.begin(), weights.end(), 0),
        left = max(*max_element(weights.begin(), weights.end()), right / days);
    auto valid = [&](int cap) -> bool {
      int day = 0, sum = 0;
      for (auto w : weights) {
        if (sum + w > cap) {
          sum = 0;
          day++;
        }
        sum += w;
      }
      return day < days;
    };
    while (left < right) {
      int mid = (left + right) / 2;
      if (!valid(mid)) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.shipWithinDays("[1,2,3,4,5,6,7,8,9,10]"_vi, 5), 15);
  CHECK(s.shipWithinDays("[3,2,2,4,1,4]"_vi, 3), 6);
  CHECK(s.shipWithinDays("[1,2,3,1,1]"_vi, 4), 3);
  return 0;
}
