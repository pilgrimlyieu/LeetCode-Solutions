// @leet imports start
// Created: 2026-09-08 15:51:44

#include "../utils.h"
#include <deque>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    auto dfs = [&](this auto &&self, int x, int y,
                   vector<vector<bool>> &ocean) {
      const int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      if (ocean[x][y]) {
        return;
      }
      ocean[x][y] = true;
      for (auto &d : dirs) {
        int tx = x + d[0], ty = y + d[1];
        if (tx >= 0 && ty >= 0 && tx < m && ty < n &&
            heights[tx][ty] >= heights[x][y]) { // 邻居要更高
          self(tx, ty, ocean);
        }
      }
    };
    for (int i = 0; i < m; i++) {
      dfs(i, 0, pacific);      // 左边界
      dfs(i, n - 1, atlantic); // 右边界
    }
    for (int j = 0; j < n; j++) {
      dfs(0, j, pacific);      // 上边界
      dfs(m - 1, j, atlantic); // 下边界
    }
    vector<vector<int>> ans;
    for (int x = 0; x < m; x++) {
      for (int y = 0; y < n; y++) {
        if (pacific[x][y] && atlantic[x][y]) {
          ans.push_back({x, y});
        }
      }
    }
    return ans;
  }
};
// @leet end

// @card note
// 逆向思维，从边界出发反向寻找能流向的格子，然后取交集。

// @alt BFS
class SolutionBFS {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    auto bfs = [&](this auto &&self, deque<pair<int, int>> &q,
                   vector<vector<bool>> &ocean) {
      const int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        for (auto &d : dirs) {
          int tx = x + d[0], ty = y + d[1];
          if (tx >= 0 && ty >= 0 && tx < m && ty < n &&
              heights[tx][ty] >= heights[x][y] &&
              !ocean[tx][ty]) { // 未访问在这
            ocean[tx][ty] = true;
            q.emplace_back(tx, ty);
          }
        }
      }
    };
    deque<pair<int, int>> pacificQueue;
    deque<pair<int, int>> atlanticQueue;
    for (int i = 0; i < m; i++) {
      pacific[i][0] = true;
      pacificQueue.emplace_back(i, 0);
      atlantic[i][n - 1] = true;
      atlanticQueue.emplace_back(i, n - 1);
    }
    for (int j = 0; j < n; j++) {
      pacific[0][j] = true;
      pacificQueue.emplace_back(0, j);
      atlantic[m - 1][j] = true;
      atlanticQueue.emplace_back(m - 1, j);
    }
    bfs(pacificQueue, pacific);
    bfs(atlanticQueue, atlantic);
    vector<vector<int>> ans;
    for (int x = 0; x < m; x++) {
      for (int y = 0; y < n; y++) {
        if (pacific[x][y] && atlantic[x][y]) {
          ans.push_back({x, y});
        }
      }
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(
      s.pacificAtlantic(
          "[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]"_vvi),
      "[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]"_vvi);
  CHECK(s.pacificAtlantic("[[1]]"_vvi), "[[0,0],[0,1],[1,0],[1,1]]"_vvi);
  return 0;
}
