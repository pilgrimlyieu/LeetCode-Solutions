// @leet imports start
// Created: 2026-09-07 21:36:13

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int candidate, count = 0;
    for (auto num : nums) {
      if (count == 0) {
        candidate = num;
      }
      if (candidate == num) {
        count++;
      } else {
        count--;
      }
    }
    return candidate;
  }
};
// @leet end

// @card hint Boyer-Moore 投票算法
// 每次从序列中抵消任意两个不同的数字，绝对多数最终会剩下来。

// @alt k-th
// 注意 Hoare 划分后 `i` 在第一个 `<= pivot` 的位置，`j` 在第一个 `>= pivot` 的位置（lower bound）。
//
// 划分可以用 `[left, i-1] + [i, right]` 或 `[left, j] + [j+1, right]`，但一定要匹配。
class SolutionKth {
public:
  int majorityElement(vector<int> &nums) {
    int n = nums.size();
    srand(time(nullptr));
    auto findKth = [&](this auto &&self, int left, int right, int k) {
      if (left == right) {
        return nums[left];
      }
      int pivot = nums[left + rand() % (right - left + 1)];
      int i = left, j = right;
      while (i <= j) {
        while (nums[i] < pivot) {
          i++;
        }
        while (nums[j] > pivot) {
          j--;
        }
        if (i <= j) {
          swap(nums[i++], nums[j--]);
        }
      }
      if (i - left >= k) {
        return self(left, i - 1, k);
      } else {
        return self(i, right, k - i + left);
      }
    };
    return findKth(0, n - 1, n / 2 + 1);
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.majorityElement("[3,2,3]"_vi), 3);
  CHECK(s.majorityElement("[2,2,1,1,1,2,2]"_vi), 2);
  return 0;
}
