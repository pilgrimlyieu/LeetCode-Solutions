// @leet imports start
// Created: 2026-08-29 15:40:57

#include "../utils.h"
#include <initializer_list>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int rob(vector<int> &nums) {
    int prev = 0, curr = 0;
    for (auto num : nums) {
      int next = max(curr, prev + num);
      prev = curr;
      curr = next;
    }
    return curr;
  }
};
// @leet end

// @card idea 动态规划
// 定义 $\mathrm{dp}[i]$ 为前 $i$ 间最多得到的金额，状态转移方程：
// $$
// \mathrm{dp}[i] = \max(\mathrm{dp}[i-1], \mathrm{dp}[i-2]+\mathrm{nums}[i])
// $$
//
// 不用考虑前面两间偷没偷过，考虑 $i$ 处的两种决策，不偷时最大值就是前 $i-1$ 间最多得到的金额，偷时 $i-1$ 不能偷，考虑前 $i-2$ 间。
//
// 可以从 2 开始遍历，初值手动计算；也可以不用特判，初始化两个为 0。

int main() {
  Solution s;
  CHECK(s.rob("[2,1,1,2]"_vi), 4);
  CHECK(s.rob("[1,2,3,1]"_vi), 4);
  CHECK(s.rob("[2,7,9,3,1]"_vi), 12);
  return 0;
}
