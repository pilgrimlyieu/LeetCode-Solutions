// @leet imports start
// Created: 2026-08-27 19:45:15

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int climbStairs(int n) {
    if (n < 2) {
      return n;
    }
    int a = 0, b = 1, c = 1;
    for (int i = 1; i <= n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.climbStairs(2), 2);
  CHECK(s.climbStairs(3), 3);
  CHECK(s.climbStairs(10), 89);
  return 0;
}
