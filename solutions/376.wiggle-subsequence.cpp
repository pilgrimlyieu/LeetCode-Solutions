// @leet imports start
// Created: 2026-08-22 22:30:26

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
      return n;
    }
    int preDiff = nums[1] - nums[0];
    int count = (preDiff != 0) ? 2 : 1;
    for (int i = 2; i < n; i++) {
      int diff = nums[i] - nums[i - 1];
      if ((diff > 0 && preDiff <= 0) || (diff < 0 && preDiff >= 0)) {
        count++;
        preDiff = diff;
      }
    }
    return count;
  }
};
// @leet end

// @card idea 贪心
// 本质上就是保留原数组中的所有拐点（波峰/谷），即可以忽略掉单调坡中间的点。

// @alt 动态规划
// 定义 `up`, `down` 分别为到当前位置最后一步是上升/下降的最长摆动子序列长度。遍历数组可以得到：
// 1. 如果 `nums[i] > nums[i - 1]`，说明当前是上升，可以接在当前下降结尾的序列后面；
// 2. 如果 `nums[i] < nums[i - 1]`，说明当前是下降，可以接在一个上升结尾的序列后面。
class SolutionDP {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int n = nums.size();
    int up = 1, down = 1;
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        up = down + 1;
      } else if (nums[i] < nums[i - 1]) {
        down = up + 1;
      }
    }
    return max(up, down);
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.wiggleMaxLength("[1]"_vi), 1);
  CHECK(s.wiggleMaxLength("[1,1]"_vi), 1);
  CHECK(s.wiggleMaxLength("[1,2]"_vi), 2);
  CHECK(s.wiggleMaxLength("[1,7,4,9,2,5]"_vi), 6);
  CHECK(s.wiggleMaxLength("[1,17,5,10,13,15,10,5,16,8]"_vi), 7);
  CHECK(s.wiggleMaxLength("[1,2,3,4,5,6,7,8,9]"_vi), 2);
  CHECK(s.wiggleMaxLength("[3,3,3,2,5]"_vi), 3);
  CHECK(
      s.wiggleMaxLength(
          "[33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60]"_vi),
      46);
  return 0;
}
