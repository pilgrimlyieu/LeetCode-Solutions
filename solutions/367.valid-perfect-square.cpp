// @leet imports start
// Created: 2026-08-18 20:38:23

#include "../utils.h"
#include <bit>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool isPerfectSquare(int num) {
    unsigned upper = 1 << (bit_width((unsigned)num) + 1) / 2,
             lower = upper >> 1;
    while (lower < upper) {
      auto mid = (lower + upper) >> 1;
      if (mid * mid <= num) {
        lower = mid + 1;
      } else {
        upper = mid;
      }
    }
    return (lower - 1) * (lower - 1) == num;
  }
};
// @leet end

// @card hint
// 什么 bound？

int main() {
  Solution s;
  CHECK(s.isPerfectSquare(16), true);
  CHECK(s.isPerfectSquare(14), false);
  return 0;
}
