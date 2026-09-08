// @leet imports start
// Created: 2026-09-08 14:31:47

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    auto dfs = [&](this auto &&self, int x, int y) {
      const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
      if (x < 0 || y < 0 || x == m || y == n || grid[x][y] == 0) {
        return 1;
      }
      if (grid[x][y] == 2) {
        return 0;
      }
      grid[x][y] = 2;
      int res = 0;
      for (int i = 0; i < 4; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        res += self(tx, ty);
      }
      return res;
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          return dfs(i, j);
        }
      }
    }
    return 0;
  }
};
// @leet end

// @alt 迭代
class SolutionIter {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    for (int x = 0; x < m; x++) {
      for (int y = 0; y < n; y++) {
        if (grid[x][y]) {
          for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || ty < 0 || tx == m || ty == n || grid[tx][ty] == 0) {
              ans++;
            }
          }
        }
      }
    }
    return ans;
  }
};
// @alt end

// @card note
// 陆地格子边界被算作周长当且仅当其为边界或邻格为水域。

int main() {
  Solution s;
  CHECK(s.islandPerimeter("[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]"_vvi), 16);
  CHECK(s.islandPerimeter("[[1]]"_vvi), 4);
  CHECK(s.islandPerimeter("[[1,0]]"_vvi), 4);
  return 0;
}
