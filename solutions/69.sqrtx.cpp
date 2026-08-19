// @leet imports start
// Created: 2026-08-18 19:58:05

#include "../utils.h"
#include <bit>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int mySqrt(int x) {
    unsigned upper = 1 << (bit_width((unsigned)x) + 1) / 2, lower = upper >> 1;
    while (lower < upper) {
      auto mid = (lower + upper) / 2;
      if (mid * mid <= x) {
        lower = mid + 1;
      } else {
        upper = mid;
      }
    }
    return lower - 1;
  }
};
// @leet end

// @card hint
// which bound?

// @card note
// 本质上是考二分或牛顿迭代法。二分上下界直接用 `[0, x]` 即可，这里只是利用位运算给了一个更精细的初始界。
//
// 最终答案是 `upper_bound - 1`，即最小的平方严格超过的数的前驱。

int main() {
  Solution s;
  CHECK(s.mySqrt(0), 0);
  CHECK(s.mySqrt(1), 1);
  CHECK(s.mySqrt(2), 1);
  CHECK(s.mySqrt(3), 1);
  CHECK(s.mySqrt(4), 2);
  CHECK(s.mySqrt(8), 2);
  CHECK(s.mySqrt(25), 5);
  CHECK(s.mySqrt(1024), 32);
  CHECK(s.mySqrt(2048), 45);
  CHECK(s.mySqrt((INT_MAX >> 1) + 1), 1 << 15);
  return 0;
}
