// @leet imports start
// Created: 2026-09-08 16:45:21

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    const int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = grid.size(), n = grid[0].size(), fresh = 0, t = 0;
    deque<pair<int, int>> q;
    for (int x = 0; x < m; x++) {
      for (int y = 0; y < n; y++) {
        if (grid[x][y] == 2) {
          q.emplace_back(x, y);
        } else if (grid[x][y] == 1) {
          fresh++;
        }
      }
    }
    while (fresh && !q.empty()) {
      int size = q.size();
      while (size--) {
        auto [x, y] = q.front();
        q.pop_front();
        for (auto &d : dirs) {
          int tx = x + d[0], ty = y + d[1];
          if (tx >= 0 && ty >= 0 && tx < m && ty < n && grid[tx][ty] == 1) {
            if (grid[tx][ty] == 1) {
              fresh--;
            }
            grid[tx][ty] = 2;
            q.emplace_back(tx, ty);
          }
        }
      }
      t++;
    }
    return fresh == 0 ? t : -1;
  }
};
// @leet end

// @card note
// 只用向 1 值扩展，2 本身就是已遍历的含义。

int main() {
  Solution s;
  CHECK(s.orangesRotting("[[2,1,1],[1,1,0],[0,1,1]]"_vvi), 4);
  CHECK(s.orangesRotting("[[2,1,1],[0,1,1],[1,0,1]]"_vvi), -1);
  CHECK(s.orangesRotting("[[0,2]]"_vvi), 0);
  return 0;
}
