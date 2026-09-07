// @leet imports start
// Created: 2026-09-07 18:45:36

#include "../utils.h"
#include <queue>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    srand(time(nullptr));
    auto quickSort = [&](this auto &&self, int left, int right) {
      if (left >= right) {
        return;
      }
      int randIdx = left + rand() % (right - left + 1);
      swap(nums[left], nums[randIdx]); // 随机选择 pivot 并交换到最左
      int pivot = nums[left];
      int lt = left, gt = right, i = left + 1;
      while (i <= gt) {
        if (nums[i] < pivot) { // nums[left+1..lt] < pivot
          swap(nums[i++], nums[lt++ + 1]);
        } else if (nums[i] > pivot) { // nums[gt..right] > pivot
          swap(nums[i], nums[gt--]);
        } else {
          i++;
        }
      }
      swap(nums[left], nums[lt]); // pivot 放到中间
      self(left, lt - 1);
      self(gt + 1, right);
    };
    quickSort(0, nums.size() - 1);
    return nums;
  }
};
// @leet end

// @card idea 三路快排
// 避免大量重复元素时的性能倒退。

// @alt 归并排序
class SolutionMerge {
public:
  vector<int> sortArray(vector<int> &nums) {
    vector<int> tmp(nums.size()); // 排序局部时的临时数组
    auto mergeSort = [&](this auto &&self, int left, int right) {
      if (left >= right) {
        return;
      }
      int mid = (left + right) / 2;
      self(left, mid);
      self(mid + 1, right);
      int i = left, j = mid + 1, k = left; // MERGE
      while (i <= mid && j <= right) {
        tmp[k++] = (nums[i] <= nums[j]) ? nums[i++] : nums[j++];
      }
      while (i <= mid) {
        tmp[k++] = nums[i++];
      }
      while (j <= right) {
        tmp[k++] = nums[j++];
      }
      for (int idx = left; idx <= right; idx++) {
        nums[idx] = tmp[idx];
      }
    };
    mergeSort(0, nums.size() - 1);
    return nums;
  }
};
// @alt end

// @alt 堆排序
class SolutionHeap {
public:
  vector<int> sortArray(vector<int> &nums) {
    auto heapify = [&](this auto &&self, int size, int idx) -> void {
      int largest = idx;
      int left = (idx << 1) + 1;
      int right = left + 1;
      if (left < size && nums[left] > nums[largest]) {
        largest = left;
      }
      if (right < size && nums[right] > nums[largest]) {
        largest = right;
      }
      if (largest != idx) {
        swap(nums[idx], nums[largest]);
        self(size, largest);
      }
    };
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--) { // 构建最大堆
      heapify(n, i);
    }
    for (int i = n - 1; i > 0; i--) { // 逐个提取最大元素
      swap(nums[0], nums[i]);
      heapify(i, 0);
    }
    return nums;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.sortArray("[5,2,3,1]"_vi), "[1,2,3,5]"_vi);
  CHECK(s.sortArray("[5,1,1,2,0,0]"_vi), "[0,0,1,1,2,5]"_vi);
  return 0;
}
