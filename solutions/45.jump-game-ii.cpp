// @leet imports start
// Created: 2026-08-23 22:27:45

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size(), far = 0, end = 0, t = 0;
    for (int i = 0; i < n - 1; i++) {
      if (far >= i) {
        far = max(far, i + nums[i]);
        if (i == end) {
          end = far;
          t++;
        }
      }
    }
    return t;
  }
};
// @leet end

// @card idea 贪心
// 在当前位置，挑选下一步可以到最远位置的一步。
//
// 具体而言维护 `far` 为可达的最远下标，而 `end` 为这一步的终点。抵达终点时更新终点并新增一步（在跳跃开始时增加）。
//
// 避免迭代最后一个位置，防止多出额外一步。

int main() {
  Solution s;
  CHECK(s.jump("[0]"_vi), 0);
  CHECK(s.jump("[2,0,1]"_vi), 1);
  CHECK(s.jump("[2,3,1,1,4]"_vi), 2);
  CHECK(s.jump("[2,3,0,1,4]"_vi), 2);
  CHECK(s.jump("[1,2,3]"_vi), 2);
  CHECK(s.jump("[3,2,1]"_vi), 1);
  CHECK(s.jump("[2,1]"_vi), 1);
  return 0;
}
