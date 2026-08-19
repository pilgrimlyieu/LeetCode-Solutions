// @leet imports start
// Created: 2026-08-19 17:10:26

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] > nums.back()) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};
// @leet end

// @card idea
// 找第一个小于最后一个值的值（使用 lower bound。

int main() {
  Solution s;
  CHECK(s.findMin("[3,4,5,1,2]"_vi), 1);
  CHECK(s.findMin("[4,5,6,7,0,1,2]"_vi), 0);
  CHECK(s.findMin("[11,13,15,17]"_vi), 11);
  CHECK(s.findMin("[2,1]"_vi), 1);
  return 0;
}
