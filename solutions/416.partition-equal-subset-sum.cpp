// @leet imports start
// Created: 2026-08-28 13:52:16

#include "../utils.h"
#include <unordered_map>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size(), sum = reduce(nums.begin(), nums.end());
    if (sum % 2) {
      return false;
    }
    bitset<10001> dp;
    dp.set(0);
    for (auto x : nums) {
      dp |= dp << x;
    }
    return dp.test(sum / 2);
  }
};
// @leet end

// @card idea bitset
// `accumulate` 顺序求和，`reduce`（C++17）允许任意顺序计算，支持并行。

// @alt 非 bitset
class SolutionVector {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size(), sum = reduce(nums.begin(), nums.end());
    if (sum % 2) {
      return false;
    }
    sum /= 2;
    vector<int> dp(sum + 1);
    dp[0] = true;
    for (auto x : nums) {
      // 也可以计算前 i 个数的前缀和，维护 s = min(s + x, sum) 减小内层循环次数
      for (int i = sum; i >= x; i--) {
        dp[i] |= dp[i - x];
      }
    }
    return dp.back();
  }
};
// @alt end

// @card note
// 0-1 背包问题（NP-完全），没有多项式时间解法。考虑两个维度的动态规划 $\mathrm{dp}(i, j)$ 代表是否能从 $\mathrm{nums}[0..i]$ 中选出和为 $j$ 的子序列，则有：
// $$
// \mathrm{dp}(i, j) = \begin{cases}
//     \mathrm{dp}(i-1, j) &\text{如果 } j < \mathrm{nums}[i] \\
//     \mathrm{dp}(i-1, j) \lor \mathrm{dp}(i-1, j - \mathrm{nums}[i]) &\text{如果 } j \geq \mathrm{nums}[i]
// \end{cases}
// $$
//
// 由于第 $i$ 层的状态只依赖于第 $i-1$ 层的状态，因此可以使用滚动数组优化空间复杂度，此时 $\mathrm{dp}(j) = \mathrm{dp}(j) \lor \mathrm{dp}(j - \mathrm{nums}[i])$。
//
// > 不过注意实际上用的是上一层的信息（用了 $\mathrm{dp}(i-1, j - \mathrm{nums}[i])$），所以在更新时应当从大到小遍历 $j$，以避免覆盖掉还未使用的状态。解法 1 使用 bitset 优化空间与简便写法，将原来的左移 $x$ 位即将原先所有值 $+x$，一批全部完成就不用考虑顺序了。
int main() {
  Solution s;
  CHECK(s.canPartition("[1,5,11,5]"_vi), true);
  CHECK(s.canPartition("[1,2,3,5]"_vi), false);
  return 0;
}
