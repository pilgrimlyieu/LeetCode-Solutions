// @leet imports start
// Created: 2025-09-27 15:00:08

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      int num = nums[mid];
      if (num == target) {
        return mid;
      } else if (num > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};
// @leet end

// @card idea
// 注意二分后移动边界，避免出现区间不缩小的情况。

// @card note
// 还有 `(left + right) / 2` 的防溢出写法 `(right - left) / 2 + left`。

int main(void) {
  Solution s;
  vector<int> v1 = {2, 5};
  vector<int> v2 = {-1, 0, 3, 5, 9, 12};
  cout << s.search(v1, 5) << endl; // 1
  cout << s.search(v2, 9) << endl; // 4
  cout << s.search(v2, 2) << endl; // -1
  return 0;
}
