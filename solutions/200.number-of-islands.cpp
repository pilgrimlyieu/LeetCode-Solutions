// @leet imports start
// Created: 2026-09-08 14:13:03

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    auto dfs = [&](this auto &&self, int i, int j) {
      if (i < 0 || j < 0 || i == m || j == n || grid[i][j] != '1') {
        return;
      }
      grid[i][j] = '0';
      self(i - 1, j);
      self(i + 1, j);
      self(i, j - 1);
      self(i, j + 1);
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          ans++;
          dfs(i, j);
        }
      }
    }
    return ans;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(
      s.numIslands(
          R"([["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]])"_vvc),
      1);
  CHECK(
      s.numIslands(
          R"([["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]])"_vvc),
      3);
  return 0;
}
