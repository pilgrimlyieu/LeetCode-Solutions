// @leet imports start
// Created: 2025-10-08 10:49:17

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool isHappy(int n) {
    int res = n;
    while (res >= 10) {
      int out = 0;
      while (res != 0) {
        out += (res % 10) * (res % 10);
        res /= 10;
      }
      res = out;
    }
    return res == 1 || res == 7;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
