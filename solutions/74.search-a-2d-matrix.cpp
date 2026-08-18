// @leet imports start
// Created: 2026-08-18 20:43:24

#include "../utils.h"
#include <algorithm>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size(), left = 0, right = m * n;
    while (left < right) {
      int mid = (left + right) / 2;
      int val = matrix[mid / n][mid % n];
      if (val == target) {
        return true;
      } else if (val < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return false;
  }
};
// @leet end

// @card hint
// 第二种解法使用标准库算法。

// @alt 标准库函数
// 学习使用标准库
class SolutionSLF {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    auto row = upper_bound(matrix.begin(), matrix.end(), target,
                           [](int a, auto b) { return a < b.front(); });
    if (row == matrix.begin()) {
      return false;
    }
    row--;
    return binary_search(row->begin(), row->end(), target);
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.searchMatrix("[[1,3,5,7],[10,11,16,20],[23,30,34,60]]"_vvi, 3), true);
  CHECK(s.searchMatrix("[[1,3,5,7],[10,11,16,20],[23,30,34,60]]"_vvi, 13),
        false);
  CHECK(s.searchMatrix("[[1,3,5,7],[10,11,16,20],[23,30,34,60]]"_vvi, 61),
        false);
  return 0;
}
