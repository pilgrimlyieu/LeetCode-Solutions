// @leet imports start
// Created: 2026-08-19 15:39:44

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int size = nums.size(), left = 0, right = size - 1;
    auto get = [&](int i) -> long {
      if (i < 0 || i >= size) {
        return LONG_MIN;
      }
      return nums[i];
    };
    if (get(left) > get(left + 1)) {
      return left;
    } else if (get(right) > get(right - 1)) {
      return right;
    }
    while (left <= right) {
      int mid = (left + right) / 2;
      if (get(mid) > get(mid - 1) && get(mid) > get(mid + 1)) {
        return mid;
      } else if (get(mid) < get(mid - 1)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
// @leet end

// @card idea
// 使用一个封装好的 `get` 函数避免处理复杂的边界问题。如果是 ACM 风格，可以在处理数据的时候就额外添加哨兵值。

// @alt 爬坡法
// 一开始是上坡，因此其实就是二分找下坡点。
class SolutionClimbing {
public:
  int findPeakElement(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] < nums[mid + 1]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
// @alt end

// @card note
// 由于可能出现 `INT_MIN`，要么就是
//
// ```cpp
// auto get = [&](int i) -> pair<int, int> {
//   if (i < 0 || i >= size) {
//     return {0, 0};
//   }
//   return {1, nums[i]};
// };
// ````

int main() {
  Solution s;
  CHECK(s.findPeakElement("[1,2,3,1]"_vi), 2);
  CHECK(s.findPeakElement("[1]"_vi), 0);
  CHECK(s.findPeakElement("[1,2,1,3,5,6,4]"_vi), 5); // 1 或 5
  CHECK(s.findPeakElement("[1,2,1,3,2]"_vi), 1);
  CHECK(s.findPeakElement("[1,2,3,4,3]"_vi), 3);
  return 0;
}
