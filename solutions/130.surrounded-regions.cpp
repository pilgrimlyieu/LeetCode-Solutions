// @leet imports start
// Created: 2026-09-08 15:32:33

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  void solve(vector<vector<char>> &board) {
    int m = board.size(), n = board[0].size();
    auto dfs = [&](this auto &&self, int x, int y) {
      if (x < 0 || y < 0 || x == m || y == n || board[x][y] != 'O') {
        return;
      }
      board[x][y] = 'T';
      const int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
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
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == 'T') {
          board[i][j] = 'O';
        }
      }
    }
  }
};
// @leet end

int main() {
  Solution s;
  // auto a1 =
  //     R"([["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]])"_vvc;
  // CHECK_INPLACE(
  //     s.solve(a1), a1,
  //     R"([['X','X','X','X'],['X','X','X','X'],['X','X','X','X'],['X','O','X','X']])");
  // auto a2 = R"([["X"]])"_vvc;
  // CHECK_INPLACE(s.solve(a2), a2, R"([['X']])");
  auto a3 = R"([["O","O"],["O","O"]])"_vvc;
  s.solve(a3);
  return 0;
}
