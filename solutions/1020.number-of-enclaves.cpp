// @leet imports start
// Created: 2026-09-08 15:00:55

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int numEnclaves(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    const int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto dfs = [&](this auto &&self, int x, int y) {
      if (x < 0 || y < 0 || x == m || y == n || grid[x][y] == 0) {
        return;
      }
      grid[x][y] = 0;
      for (auto &dir : dirs) {
        self(x + dir[0], y + dir[1]);
      }
    };
    for (int i = 0; i < m; i++) {
      dfs(i, 0);
      dfs(i, n - 1);
    }
    for (int j = 1; j < n - 1; j++) {
      dfs(0, j);
      dfs(m - 1, j);
    }
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (grid[i][j]) {
          ans++;
        }
      }
    }
    return ans;
  }
};
// @leet end

// @card idea DFS
// 从边界开始 DFS 并清除。

int main() {
  Solution s;
  CHECK(s.numEnclaves("[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]"_vvi), 3);
  CHECK(s.numEnclaves("[[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]"_vvi), 0);
  return 0;
}
