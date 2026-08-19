// @leet imports start
// Created: 2026-08-23 21:51:28

#include "../utils.h"
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    priority_queue pq(greater<>(), nums);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    while (k--) {
      int top = pq.top();
      sum -= 2 * top;
      pq.pop();
      pq.push(-top);
    }
    return sum;
  }
};
// @leet end

// @card hint
// 优先队列怎么写？

// @card note
// 还有一种思路：
// 1. `k` 小于等于负数个数：将负数全部取反；
// 2. `k` 大于负数个数，先将所有负数取反，然后根据剩下次数奇偶性：
//     1. 偶数：直接输出当前和即可，全为正，将某数取反两次变回去；
//     2. 奇数：取反最小的数。
//
// 具体操作可以一开始排序，也可以桶排序（数据量级不大），然后更新的时候记录是否有新的最小正数出现。

int main() {
  Solution s;
  CHECK(s.largestSumAfterKNegations("[4,2,3]"_vi, 1), 5);
  CHECK(s.largestSumAfterKNegations("[3,-1,0,2]"_vi, 3), 6);
  CHECK(s.largestSumAfterKNegations("[2,-3,-1,5,-4]"_vi, 2), 13);
  return 0;
}
