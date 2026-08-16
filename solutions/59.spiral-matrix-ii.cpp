// @leet imports start
// Created: 2025-10-01 10:12:58

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    int t = 0, b = n - 1, l = 0, r = n - 1, idx = 1;
    while (idx <= n * n) {
      for (int i = l; i <= r; i++) {
        res[t][i] = idx++;
      }
      t++;
      for (int j = t; j <= b; j++) {
        res[j][r] = idx++;
      }
      r--;
      for (int i = r; i >= l; i--) {
        res[b][i] = idx++;
      }
      b--;
      for (int j = b; j >= t; j--) {
        res[j][l] = idx++;
      }
      l++;
    }
    return res;
  }
};
// @leet end

// @card idea
// 使用 `t`(top), `b`(bottom), `l`(left), `r`(right) 四个变量追踪边界。

int main(void) {
  Solution s;
  CHECK(s.generateMatrix(1), "[[1]]"_vvi);
  CHECK(s.generateMatrix(2), "[[1, 2], [4, 3]]"_vvi);
  CHECK(s.generateMatrix(3), "[[1, 2, 3], [8, 9, 4], [7, 6, 5]]"_vvi);
  CHECK(s.generateMatrix(4),
        "[[1, 2, 3, 4], [12, 13, 14, 5], [11, 16, 15, 6], [10, 9, 8, 7]]"_vvi);
  return 0;
}
