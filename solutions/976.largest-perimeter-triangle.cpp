// @leet imports start
// Created: 2025-09-21 10:02:49

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for (int i = len - 1; i >= 2; i--) {
      if (nums[i] < nums[i - 1] + nums[i - 2]) {
        return nums[i] + nums[i - 1] + nums[i - 2];
      }
    }
    return 0;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
