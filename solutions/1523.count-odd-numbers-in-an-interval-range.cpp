// @leet imports start
// Created: 2025-09-19 23:02:23

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int countOdds(int low, int high) {
    // vector<int> res;
    // res.reserve((high - low) / 2 + 1);
    // if (low % 2 = 0) {
    //     low++;
    // }
    // for (int i = low; i <= high; i += 2) {
    //     res.push_back(i);
    // }
    // // 看错题目了……
    if (low % 2 == 0 && high % 2 == 0) {
      return (high - low) / 2;
    } else {
      return (high - low) / 2 + 1;
    }
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
