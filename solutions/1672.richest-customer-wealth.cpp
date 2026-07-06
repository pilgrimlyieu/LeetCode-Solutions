// @leet imports start
// Created: 2025-09-17 21:17:53

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int sumVec(vector<int> &vec) {
    int sum = 0;
    for (auto i : vec) {
      sum += i;
    }
    return sum;
  }

  int maximumWealth(vector<vector<int>> &accounts) {
    int max = 0;
    for (auto v : accounts) {
      int now;
      if ((now = sumVec(v)) > max) {
        max = now;
      }
    }
    return max;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
