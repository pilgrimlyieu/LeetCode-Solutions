// @leet imports start
// Created: 2025-09-27 15:15:47

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      if (nums[left] != val) {
        left++;
      } else if (nums[right] == val) {
        right--;
      } else {
        nums[left] = nums[right--];
      }
    }
    return left;
  }
};
// @leet end

int main(void) {
  Solution s;
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
  return 0;
}
