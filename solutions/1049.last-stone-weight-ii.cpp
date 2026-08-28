// @leet imports start
// Created: 2026-08-28 16:29:37

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    bitset<3001> dp;
    dp.set(1500);
    for (auto s : stones) {
      dp = (dp << s) | (dp >> s);
    }
    for (int i = 1500; i <= 3000; i++) {
      if (dp.test(i)) {
        return i - 1500;
      }
    }
    __builtin_unreachable();
  }
};
// @leet end

// @card idea bitset
// 本质上就是给每个数标上一个正负号，求非负数和的最小值。因此 DP 保存前 `i` 个数所有可能的和，包括负数。

// @alt bitset2
// 由上，也可以看成容量为 `sum / 2` 的 0-1 背包问题。
class Solution2 {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = reduce(stones.begin(), stones.end());
    bitset<1501> dp;
    dp.set(0);
    for (auto s : stones) {
      dp |= (dp << s);
    }
    for (int i = sum / 2; i >= 0; i--) {
      if (dp.test(i)) {
        return sum - 2 * i;
      }
    }
    __builtin_unreachable();
  }
};
// @alt end

// @card note
// 解法 1 隐含了一个没有证明的结论，那就是最小非负值对应的正负分配一定可以构造对应的碰撞序列。这不像解法 2 是可以直接从 `dp` 中看出来，需要进行一些思考：
//
// 假设分成了正堆 A 和负堆 B，重量和分别为 $S_A, S_B$，且最终答案为 $S=S_A-S_B\ge 0$。构造方法就是：
// 1. 每次从两堆各取一块石头并进行碰撞，两堆会同时减少相同重量，重量差保持不变；
// 2. 一直到 B 堆清空，A 堆剩余质量就是所求重量差，由此便构造了一个碰撞序列。

int main() {
  Solution2 s;
  CHECK(s.lastStoneWeightII("[2,7,4,1,8,1]"_vi), 1);
  CHECK(s.lastStoneWeightII("[31,26,33,21,40]"_vi), 5);
  return 0;
}
