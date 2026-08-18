// @leet imports start
// Created: 2026-08-18 17:47:50

#include "../utils.h"
#include <algorithm>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int size = nums.size();
    int lowerBound = 0, upperBound = 0, right = size;
    while (lowerBound < right) {
      int mid = (lowerBound + right) / 2;
      if (nums[mid] < target) {
        lowerBound = mid + 1;
      } else {
        right = mid;
      }
    }
    // int lowerBound = ranges::lower_bound(nums, target) - nums.begin();
    upperBound = lowerBound, right = size;
    while (upperBound < right) {
      int mid = (upperBound + right) / 2;
      if (nums[mid] <= target) {
        upperBound = mid + 1;
      } else {
        right = mid;
      }
    }
    // int upperBound =
    //     ranges::upper_bound(nums | views::drop(lowerBound), target) -
    //     nums.begin();
    if (lowerBound < upperBound) {
      return {lowerBound, upperBound - 1};
    }
    return {-1, -1};
  }
};
// @leet end

// @card idea
// `lower_bound` 寻找第一个 `<= target` 的元素，`upper_bound` 寻找第一个 `< target` 的元素。二者的区别就在于里面的缩小区间条件分别是 `<` 和 `<=` 时。

// @card note
// 二分查找：
//
// | 区间类型 | 初值 | while 条件 | 更新方式 |
// | :-- | :-- | :-- | :-- |
// | `[l, r]` | `[0, n-1]` | `l <= r` | `l = mid + 1`, `r = mid - 1` |
// | `[l, r)` | `[0, n)` | `l < r` | `l = mid + 1`, `r = mid` |
//
// 对于半闭半开区间需要注意 `mid` 的求值可能不会发生变化。例如对于 `(l, r]` 的更新方式是 `l = mid`，然而 `mid` 向下取整可能保持不变，因此需要用 `mid = (l + r + 1) / 2`。为了清晰起见还是避免使用这种，只是需要注意可能有这种情况。

int main() {
  Solution s;
  CHECK(s.searchRange("[5,7,7,8,8,10]"_vi, 8), "[3,4]"_vi);
  CHECK(s.searchRange("[5,7,7,8,8,10]"_vi, 7), "[1,2]"_vi);
  CHECK(s.searchRange("[5,7,7,8,8,10]"_vi, 10), "[5,5]"_vi);
  CHECK(s.searchRange("[5,7,7,8,8,10]"_vi, 6), "[-1,-1]"_vi);
  CHECK(s.searchRange("[5,7,7,8,8,10]"_vi, 3), "[-1,-1]"_vi);
  CHECK(s.searchRange("[]"_vi, 0), "[-1,-1]"_vi);
  CHECK(s.searchRange("[1]"_vi, 1), "[0,0]"_vi);
  return 0;
}
