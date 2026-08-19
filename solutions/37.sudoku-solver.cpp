// @leet imports start
// Created: 2026-08-22 17:06:31

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) {
    unsigned row[10] = {0};
    unsigned col[10] = {0};
    unsigned square[10] = {0};
    vector<pair<int, int>> todo;
    auto place = [&](int y, int x) {
      int n = 1 << (board[y][x] - '1');
      row[y] ^= n;
      col[x] ^= n;
      square[3 * (y / 3) + x / 3] ^= n;
    };
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          place(i, j);
        } else {
          todo.emplace_back(i, j);
        }
      }
    }
    auto dfs = [&](this auto &&self, int i) -> bool {
      if (i == todo.size()) {
        return true;
      }
      auto [y, x] = todo[i];
      for (auto m = ((1 << 9) - 1) &
                    ~(row[y] | col[x] | square[3 * (y / 3) + x / 3]);
           m; m &= m - 1) {
        auto lb = m & -m;
        board[y][x] = '1' + __builtin_ctz(lb);
        place(y, x);
        if (self(i + 1)) {
          return true;
        }
        place(y, x);
        board[y][x] = '.';
      }
      return false;
    };
    dfs(0);
  }
};
// @leet end

// @card idea
// 可以在初始化状态的时候同时准备一个待填坐标列表，这样可以直接在列表中遍历，而不用靠坐标完成后再判断是否正确填充完成。

// @card hint
// 如何解包？（初始代码有用）

// @card note
// 可以使用 `auto [x, y] = p` 解包（复制值），引用则用 `auto& [x, y] = p`。

int main() {
  Solution s;
  auto a1 =
      R"([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]])"_vvc;
  CHECK_INPLACE(
      s.solveSudoku(a1), a1,
      R"([["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]])"_vvc);
  return 0;
}
