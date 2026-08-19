// @leet imports start
// Created: 2026-08-22 15:47:16

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> temp;
    vector<int> column(n);
    vector<int> diag1(2 * n + 1);
    vector<int> diag2(2 * n + 1);
    auto affect = [&](int x, int y, int val) {
      column[x] += val;
      diag1[n + x - y] += val;
      diag2[x + y] += val;
    };
    auto affected = [&](int x, int y) {
      return column[x] || diag1[n + x - y] || diag2[x + y];
    };
    auto dfs = [&](this auto &&self, int idx) {
      if (idx == n) {
        ans.push_back(temp);
        return;
      }
      for (int i = 0; i < n; i++) {
        if (affected(i, idx)) {
          continue;
        }
        affect(i, idx, 1);
        temp.push_back(string(i, '.') + 'Q' + string(n - 1 - i, '.'));
        self(idx + 1);
        affect(i, idx, -1);
        temp.pop_back();
      }
    };
    dfs(0);
    return ans;
  }
};
// @leet end

// @card hint
// 调试过程中，状态压缩的无符号整数如何显示？

// @card idea
// 注意到正斜线上坐标之差恒定，而反斜线上坐标之和恒定，因此只需要三个数组（不需要考虑行，因为本身就在按行迭代了）或 `unordered_set`，而无需表示整个棋盘。
//
// 此外这种方式还可以不需要计数判断某块位置被多个皇后影响的情况，每种行、列、斜线都只可能会被一个皇后控制，因此只需要一个布尔值判断即可，于是可以使用位运算状态压缩：

// @alt 位运算
// 此外再进行了优化，可以不用每行所有位置都尝试，既然有了 `columns` 可以直接用剩下的继续。而区分了两种对角线，可以直接用一行的情况推出下一行（因此两种解法对角线表示的含义不同）。
class SolutionBinary {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> temp;
    auto dfs = [&](this auto &&self, int idx, unsigned col, unsigned diag1,
                   unsigned diag2) {
      if (idx == n) {
        ans.push_back(temp);
        return;
      }
      for (auto m = ((1 << n) - 1) & ~(col | diag1 | diag2); m; m &= m - 1) {
        int i = __builtin_ctz(m);
        unsigned lb = m & -m;
        temp.push_back(string(i, '.') + 'Q' + string(n - 1 - i, '.'));
        self(idx + 1, col | lb, (diag1 | lb) >> 1, (diag2 | lb) << 1);
        temp.pop_back();
      }
    };
    dfs(0, 0, 0, 0);
    return ans;
  }
};
// @alt end

// @card note
// 可以使用 `bitset<N>(number)` 来打印，如本题就可用 `bitset<4>(m)` 测试四位的情况。

int main() {
  Solution s;
  SolutionBinary s2;
  CHECK(s.solveNQueens(4),
        R"([[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]])"_vvs);
  CHECK(s.solveNQueens(1), R"([["Q"]])"_vvs);
  CHECK(s2.solveNQueens(4),
        R"([[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]])"_vvs);
  CHECK(s2.solveNQueens(1), R"([["Q"]])"_vvs);
  return 0;
}
