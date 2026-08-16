// @leet imports start
// Created: 2025-09-27 15:53:58

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int len = nums.size();
    int left = 0, sum = 0, res = len + 1;
    for (int right = 0; right < len; right++) {
      sum += nums[right];
      while (sum >= target) {
        res = min(res, right - left + 1);
        sum -= nums[left++];
      }
    }
    return res > len ? 0 : res;
  }
};
// @leet end

// @card idea
// 滑动窗口弹性伸缩，窗口先往右扩展，达到目标后再尝试缩减左边界。

int main(void) {
  Solution s;
  CHECK(s.minSubArrayLen(7, "[2, 3, 1, 2, 4, 3]"_vi), 2);
  CHECK(s.minSubArrayLen(4, "[1, 4, 4]"_vi), 1);
  CHECK(s.minSubArrayLen(11, "[1, 1, 1, 1]"_vi), 0);
  return 0;
}
