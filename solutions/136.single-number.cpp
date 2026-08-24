// @leet imports start
// Created: 2026-08-24 15:40:25

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int val = 0;
    for (auto n : nums) {
      val ^= n;
    }
    return val;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.singleNumber("[2,2,1]"_vi), 1);
  CHECK(s.singleNumber("[4,1,2,1,2]"_vi), 4);
  CHECK(s.singleNumber("[1]"_vi), 1);
  return 0;
}
