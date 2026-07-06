// @leet imports start
// Created: 2025-09-17 20:19:20

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  string tictactoe(vector<vector<int>> &moves) {
    bool end = moves.size() == 9;
    vector<vector<int>> m = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int p = 1;
    for (auto move : moves) {
      m[move[0]][move[1]] = p;
      p = (p == 1) ? -1 : 1;
    }
    int r0 = m[0][0] + m[0][1] + m[0][2];
    if (r0 == 3) {
      return "A";
    }
    if (r0 == -3) {
      return "B";
    }
    int r1 = m[1][0] + m[1][1] + m[1][2];
    if (r1 == 3) {
      return "A";
    }
    if (r1 == -3) {
      return "B";
    }
    int r2 = m[2][0] + m[2][1] + m[2][2];
    if (r2 == 3) {
      return "A";
    }
    if (r2 == -3) {
      return "B";
    }
    int l0 = m[0][0] + m[1][0] + m[2][0];
    if (l0 == 3) {
      return "A";
    }
    if (l0 == -3) {
      return "B";
    }
    int l1 = m[0][1] + m[1][1] + m[2][1];
    if (l1 == 3) {
      return "A";
    }
    if (l1 == -3) {
      return "B";
    }
    int l2 = m[0][2] + m[1][2] + m[2][2];
    if (l2 == 3) {
      return "A";
    }
    if (l2 == -3) {
      return "B";
    }
    int d0 = m[0][0] + m[1][1] + m[2][2];
    if (d0 == 3) {
      return "A";
    }
    if (d0 == -3) {
      return "B";
    }
    int d1 = m[0][2] + m[1][1] + m[2][0];
    if (d1 == 3) {
      return "A";
    }
    if (d1 == -3) {
      return "B";
    }
    return end ? "Draw" : "Pending";
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
