// @leet imports start
// Created: 2026-09-08 14:27:03

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size(), maxArea = 0;
    auto dfs = [&](this auto &&self, int i, int j) {
      if (i < 0 || j < 0 || i == m || j == n || grid[i][j] != 1) {
        return 0;
      }
      grid[i][j] = 0;
      return 1 + self(i - 1, j) + self(i + 1, j) + self(i, j - 1) +
             self(i, j + 1);
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        maxArea = max(maxArea, dfs(i, j));
      }
    }
    return maxArea;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(
      s.maxAreaOfIsland(
          "[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]"_vvi),
      6);
  CHECK(s.maxAreaOfIsland("[[0,0,0,0,0,0,0,0]]"_vvi), 0);
  return 0;
}
