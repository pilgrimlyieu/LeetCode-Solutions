// @leet imports start
// Created: 2026-08-24 13:43:42

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total = 0, curr = 0, start = 0;
    for (int i = 0; i < gas.size(); i++) {
      int diff = gas[i] - cost[i];
      total += diff;
      curr += diff;
      if (curr < 0) {
        start = i + 1;
        curr = 0;
      }
    }
    return (total >= 0) ? start : -1;
  }
};
// @leet end

// @card idea 贪心
// 若从 `x` 出发到 `y` 时负油量，则这段路中间任一点出发都不可能抵达 `y`，因为在此之前有剩余油量的情况下都无法抵达。
//
// 因此可以一遍遍历，若这一趟在中途出现负油量则这一段路都不可能作为出发点，改变出发点。
//
// 与此同时统计粽油量，若总油量非负则一定可以成功。等价于总和非负的数组总能找到一个下标进行循环遍历使得任意前缀和非负，考虑前缀和的变化图，取其最小值所处下标 +1 即可。

int main() {
  Solution s;
  CHECK(s.canCompleteCircuit("[1,-2,3,-4,2]"_vi, "[0,0,0,0,0]"_vi), 4);
  CHECK(s.canCompleteCircuit("[1,2,3,4,5]"_vi, "[3,4,5,1,2]"_vi), 3);
  CHECK(s.canCompleteCircuit("[2,3,4]"_vi, "[3,4,3]"_vi), -1);
  CHECK(s.canCompleteCircuit("[5]"_vi, "[4]"_vi), 0);
  CHECK(s.canCompleteCircuit("[1,1,0,0,-3,1]"_vi, "[0,0,0,0,0,0]"_vi), 5);
  return 0;
}
