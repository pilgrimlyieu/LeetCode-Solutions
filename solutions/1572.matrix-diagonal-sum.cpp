// @leet imports start
// Created: 2025-09-17 21:20:35

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int diagonalSum(vector<vector<int>> &mat) {
    int len = mat.size();
    int result = 0;
    for (int i = 0; i < len; i++) {
      result += mat[i][i] + mat[i][len - 1 - i];
    }
    if (len % 2 == 1) {
      result -= mat[len / 2][len / 2];
    }
    return result;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
