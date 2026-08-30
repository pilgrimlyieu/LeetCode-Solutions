// @leet imports start
// Created: 2026-08-30 14:57:38

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    int ans = 1, curr = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        curr++;
        ans = max(ans, curr);
      } else {
        curr = 1;
      }
    }
    return ans;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.findLengthOfLCIS("[1,3,5,4,7]"_vi), 3);
  CHECK(s.findLengthOfLCIS("[2,2,2,2,2]"_vi), 1);
  return 0;
}
