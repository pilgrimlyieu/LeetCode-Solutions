// @leet imports start
// Created: 2026-08-19 16:34:21

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int boundary = nums.front(), left = 0, right = nums.size();
    bool isLeft = target >= boundary;
    while (left < right) {
      int mid = (left + right) / 2, val = nums[mid];
      if (val == target) {
        return mid;
      } else if ((isLeft && val >= boundary && val < target) ||
                 (!isLeft && !(val > target && val < boundary))) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return -1;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.search("[4,5,6,7,0,1,2]"_vi, 0), 4);
  CHECK(s.search("[4,5,6,7,0,1,2]"_vi, 3), -1);
  CHECK(s.search("[1]"_vi, 0), -1);
  return 0;
}
