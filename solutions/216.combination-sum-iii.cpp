// @leet imports start
// Created: 2026-08-19 19:46:12

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    auto backtrace = [&](this auto &&self, int i) {
      if (temp.size() == k) {
        if (sum == n) {
          ans.push_back(temp);
        }
        return;
      }
      if (10 - i + temp.size() < k) {
        return;
      }
      temp.push_back(i);
      sum += i;
      self(i + 1);
      temp.pop_back();
      sum -= i;
      self(i + 1);
    };
    backtrace(1);
    return ans;
  }
};
// @leet end

// @card hint
// 如何快速枚举所有组合？

// @alt Gosper's Hack
// Gosper’s Hack 可以用来快速求出下一个二进制中 1 的个数相同的整数，因此可以用来枚举 $\binom{n}{k}$ 组合。
//
// 将掩码转换成具体的组合也可以用 `(1 << i) & mask` 获取，这里使用了等价的内建函数 `__builtin_ctz`（Count Trailing Zeros）。
class SolutionGosper {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    temp.reserve(k);
    unsigned mask = (1 << k) - 1; // 最小的连续 k 位 1 数
    unsigned limit = 1 << 9;      // 限制范围
    while (mask < limit) {
      int sum = 0;
      for (unsigned m = mask; m; m &= m - 1) { // m &= m - 1 会清除最后一位的 1
        int i = __builtin_ctz(m) + 1; // 该内建函数会获取最低位连续 0 的个数
        sum += i;
        temp.push_back(i);
      }
      if (sum == n) {
        ans.push_back(temp);
      }
      temp.clear();
      unsigned lb = mask & -mask;          // 最低位的 1
      unsigned r = mask + lb;              // 连续段清零，最高位左移
      mask = r | (((mask ^ r) >> 2) / lb); // 补上剩下的 1
    }
    return ans;
  }
};
// @alt end

// @card note
// Gosper’s Hack 核心思想就是将最低一段连续的 1 的最左一位左移，然后将剩下的 1 移回最右：
// 1. `(1 << k) - 1` 获取最小的有 `k` 位 1 的数，`1 << n` 获取上限；
// 2. `mask & -mask` 获取最低位的 1；
// 3. `mask + lb` 实现将最低连续一段的 1 清零，同时最左位左移；
// 4. `(mask ^ r) / lb` 得到最初的连续段 1 外加左移后的 1，因此多了两位；
// 5. `((mask ^ r) >> 2) / lb` 最后右移两位丢弃掉多余的两位，就补全了初始的 1。
//
// 另外里面有多处与 0 相关的敏感点：
// 1. `k` 不能为零，为零后 `lb` 为零会有除零错误。
// 2. `__builtin_ctz` 对零是未定义的。

int main() {
  Solution s;
  SolutionGosper s2;
  CHECK_ANYORDER(s.combinationSum3(3, 7), "[[1,2,4]]"_vvi);
  CHECK_ANYORDER(s.combinationSum3(3, 9), "[[1,2,6], [1,3,5], [2,3,4]]"_vvi);
  CHECK_ANYORDER(s.combinationSum3(4, 1), "[]"_vvi);
  CHECK_ANYORDER(s.combinationSum3(9, 45), "[[1, 2, 3, 4, 5, 6, 7, 8, 9]]"_vvi);
  CHECK_ANYORDER(s2.combinationSum3(3, 7), "[[1,2,4]]"_vvi);
  CHECK_ANYORDER(s2.combinationSum3(3, 9), "[[1,2,6], [1,3,5], [2,3,4]]"_vvi);
  CHECK_ANYORDER(s2.combinationSum3(4, 1), "[]"_vvi);
  CHECK_ANYORDER(s2.combinationSum3(9, 45),
                 "[[1, 2, 3, 4, 5, 6, 7, 8, 9]]"_vvi);
  return 0;
}
