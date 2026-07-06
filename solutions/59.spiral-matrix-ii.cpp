// @leet imports start
// Created: 2025-10-01 10:12:58

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    int h = n;
    int w = n;
    int idx = 1;
    int x = 0;
    int y = 0;
    while (h > 0 && w > 0) {
      mat[x][y] = idx++;
      for (int i = 0; i < w - 1; i++) {
        mat[y][++x] = idx++;
      }
      for (int i = 0; i < h - 1; i++) {
        mat[++y][x] = idx++;
      }
      for (int i = 0; i < w - 1; i++) {
        mat[y][--x] = idx++;
      }
      for (int i = 0; i < w - 2; i++) {
        mat[--y][x] = idx++;
      }
      x++;
      h -= 2;
      w -= 2;
    }
    return mat;
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.generateMatrix(1) << endl;
  cout << s.generateMatrix(2) << endl;
  cout << s.generateMatrix(3) << endl;
  cout << s.generateMatrix(4) << endl;
  return 0;
}
