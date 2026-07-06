// @leet imports start
// Created: 2025-09-19 22:32:34

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> res;
    res.reserve(m * n);
    int h = m - 1;
    int w = n - 1;
    int x = 0;
    int y = 0;
    while (h >= 0 && w >= 0) {
      res.push_back(matrix[y][x]);
      for (int i = 0; i < w; i++) {
        res.push_back(matrix[y][++x]);
      }
      for (int i = 0; i < h; i++) {
        res.push_back(matrix[++y][x]);
      }
      for (int i = 0; h && i < w; i++) {
        res.push_back(matrix[y][--x]);
      }
      for (int i = 0; w && i < h - 1; i++) {
        res.push_back(matrix[--y][x]);
      }
      x++;
      h -= 2;
      w -= 2;
    }
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  vector<vector<int>> v1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> v2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  // cout << s.spiralOrder(v1) << endl;
  cout << s.spiralOrder(v2) << endl;
  return 0;
}
