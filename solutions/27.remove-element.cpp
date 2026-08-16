// @leet imports start
// Created: 2025-09-27 15:15:47

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int k = 0, len = nums.size();
    for (int num : nums) {
      if (num != val) {
        nums[k++] = num;
      }
    }
    return k;
  }
};
// @leet end

// @card idea 快慢指针
// 快慢指针，将快指针遍历的不同元素移动到慢指针上。

// @alt 左右双指针
// 快慢指针可能有冗余移动，改用左右双指针遍历：左指针用于寻找相同元素，与右指针的不同元素进行交换（仅在不同时交换，避免冗余）。
//
// 循环条件使用 `<=`，因为若重合在不同元素，为了返回不同元素个数，还需要继续循环将左指针右移一位，确保左指针停留在最后一个不同元素之后一位。
class SolutionLR {
public:
  int removeElement(vector<int> &nums, int val) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      if (nums[left] != val) {
        left++;
      } else if (nums[right] == val) {
        right--;
      } else {
        nums[left++] = nums[right--];
      }
    }
    return left;
  }
};
// @alt end

int main(void) {
  Solution s;
  SolutionLR s2;
  auto v1 = "[3, 2, 2, 3]"_vi;
  CHECK(s.removeElement(v1, 3), 2);
  CHECK_FIRSTK_ANYORDER(2, v1, "[2, 2]"_vi);
  auto v2 = "[0, 1, 2, 2, 3, 0, 4, 2]"_vi;
  CHECK(s.removeElement(v2, 2), 5);
  CHECK_FIRSTK_ANYORDER(5, v2, "[0, 1, 4, 0, 3]"_vi);
  auto v3 = "[1, 1, 2, 2, 2]"_vi;
  CHECK(s.removeElement(v3, 2), 2);
  CHECK_FIRSTK_ANYORDER(2, v3, "[1, 1]"_vi);
  auto v4 = "[2]"_vi;
  CHECK(s.removeElement(v4, 3), 1);
  CHECK_FIRSTK_ANYORDER(1, v4, "[2]"_vi);
  auto v5 = "[2]"_vi;
  CHECK(s.removeElement(v5, 2), 0);
  CHECK_FIRSTK_ANYORDER(0, v5, "[]"_vi);
  auto v6 = "[3, 3]"_vi;
  CHECK(s.removeElement(v6, 3), 0);
  CHECK_FIRSTK_ANYORDER(0, v6, "[]"_vi);
  auto v7 = "[3, 3]"_vi;
  CHECK(s.removeElement(v7, 5), 2);
  CHECK_FIRSTK_ANYORDER(2, v7, "[3, 3]"_vi);
  auto v8 = "[4, 5]"_vi;
  CHECK(s.removeElement(v8, 4), 1);
  CHECK_FIRSTK_ANYORDER(1, v8, "[5]"_vi);
  auto w1 = "[3, 2, 2, 3]"_vi;
  CHECK(s2.removeElement(w1, 3), 2);
  CHECK_FIRSTK_ANYORDER(2, w1, "[2, 2]"_vi);
  auto w2 = "[0, 1, 2, 2, 3, 0, 4, 2]"_vi;
  CHECK(s2.removeElement(w2, 2), 5);
  CHECK_FIRSTK_ANYORDER(5, w2, "[0, 1, 4, 0, 3]"_vi);
  return 0;
}
