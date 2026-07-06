// @leet imports start
// Created: 2025-09-12 23:26:55

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int swap_zero(vector<int> &nums, int idx1, int idx2) {
    int temp = nums[idx2];
    nums[idx2] = nums[idx1];
    nums[idx1] = temp;
    return temp;
  }

  void moveZeroes(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
      if (nums[i] != 0) {
        continue;
      }
      int index = i + 1;
      for (; index < len; index++) {
        if (nums[index] != 0) {
          break;
        }
      }
      if (index == len) { // if this happens, the task has been done before.
        return;
      }
      swap_zero(nums, i, index);
    }
  }
};
// @leet end

int main(void) {
  Solution s;
  vector<int> v = {0, 1, 0, 3, 12};
  s.moveZeroes(v);
  return 0;
}
