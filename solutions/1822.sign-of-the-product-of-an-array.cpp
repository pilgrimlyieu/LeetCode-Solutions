// @leet imports start
// Created: 2025-09-14 11:06:37

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int signFunc(int x) {
    if (x > 0) {
      return 1;
    } else {
      return -1;
    }
  }
  int arraySign(vector<int> &nums) {
    int result = 1;
    for (int n : nums) {
      if (n == 0) {
        return 0;
      } else {
        result *= signFunc(n);
      }
    }
    return result;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
