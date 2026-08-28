// @leet imports start
// Created: 2026-08-28 20:26:45

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector(n + 1, 0));
    for (auto &s : strs) {
      int zeros = count(s.begin(), s.end(), '0'), ones = s.size() - zeros;
      for (int i = m; i >= zeros; i--) {
        for (int j = n; j >= ones; j--) {
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
// @leet end

// @card idea 动态规划
// 类似背包问题：
// 1. `dp[i][j]` 的含义是容量限制为 `(i, j)` 时最多的字符串个数；
//     - 若用「恰好」的含义，需要控制更新，且必须记录答案值，无法直接返回 `dp[m][n]`。
// 2. 要注意更新内容，有一个 `max`，避免覆盖；
// 3. 可以直接 `for (zeros <- m) for (ones <- n)` 倒序遍历，不需要对角线遍历。

// @card note
// 其他优化思路：
// 1. 可以将二维数组压平成一维数组，手动计算下标，缓存局部性更好（不过实测无差别）；
// 2. 这里因数据规模小而直接扩展 `dp` 数组，若 `m`, `n` 非常大则会造成浪费。若数据规模较大，可以预先统计个数，再行设定大小；
// 3. 在 2. 的基础上，若二者均比较大可以提前剪枝。
//
// 其他注意点：
// 1. 可以用 `count` 函数进行统计。

int main() {
  Solution s;
  CHECK(s.findMaxForm(R"(["10","0001","111001","1","0"])"_vs, 5, 3), 4);
  CHECK(s.findMaxForm(R"(["10","0","1"])"_vs, 1, 1), 2);
  CHECK(s.findMaxForm(R"(["10001110","11000","111110"])"_vs, 6, 6), 1);
  CHECK(
      s.findMaxForm(
          R"(["0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"])"_vs,
          9, 80),
      17);
  CHECK(s.findMaxForm(R"(["1","0","10","0"])"_vs, 2, 1), 3);
  return 0;
}
