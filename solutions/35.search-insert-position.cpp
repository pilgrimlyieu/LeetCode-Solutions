// @leet imports start
// Created: 2026-08-18 17:35:27

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
// @leet end

// @card note
// `right >= mid`，连 `nums[mid]` 都大于 `target` 了，可以放心收缩区间。具体可以参考 34. 题的表格。

int main() {
  Solution s;
  CHECK(s.searchInsert("[1,3,5,6]"_vi, 5), 2);
  CHECK(s.searchInsert("[1,3,5,6]"_vi, 2), 1);
  CHECK(s.searchInsert("[1,3,5,6]"_vi, 7), 4);
  CHECK(s.searchInsert("[1,3,5,6]"_vi, 0), 0);
  CHECK(s.searchInsert("[1]"_vi, 1), 0);
  CHECK(s.searchInsert("[1,3]"_vi, 1), 0);
  return 0;
}
