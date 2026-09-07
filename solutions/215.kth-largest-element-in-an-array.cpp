// @leet imports start
// Created: 2026-09-07 19:32:25

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    srand(time(nullptr));
    auto findKth = [&](this auto &&self, int left, int right, int k) -> int {
      if (left == right) {
        return nums[left];
      }
      int pivot = nums[left + rand() % (right - left + 1)];
      int i = left, j = right;
      while (i <= j) {
        while (nums[i] > pivot) {
          i++;
        }
        while (nums[j] < pivot) {
          j--;
        }
        if (i <= j) {
          swap(nums[i++], nums[j--]);
        }
      }
      if (j - left + 1 >= k) { // [left, j] >= pivot
        return self(left, j, k);
      } else { // [i, right] <= pivot
        return self(j + 1, right, k);
      }
    };
    return findKth(0, nums.size() - 1, k);
  }
};
// @leet end

// @card idea Hoare 划分
// Hoare 划分双指针，交换次数比 Lomuto 划分少，$O(n)$ 时间复杂度也没必要用三路划分。

int main() {
  Solution s;
  CHECK(s.findKthLargest("[3,2,1,5,6,4]"_vi, 2), 5);
  CHECK(s.findKthLargest("[3,2,3,1,2,4,5,5,6]"_vi, 4), 4);
  return 0;
}
