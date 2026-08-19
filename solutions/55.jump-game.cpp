// @leet imports start
// Created: 2026-08-23 22:06:34

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size(), far = nums[0];
    for (int i = 0; i < n - 1; i++) {
      if (i > far) {
        break;
      }
      far = max(far, i + nums[i]);
    }
    return far >= n - 1;
  }
};
// @leet end

// @card note
// 遍历过程中如果已经超过最远可达下标，则说明不可达。

int main() {
  Solution s;
  CHECK(s.canJump("[0]"_vi), true);
  CHECK(s.canJump("[2,3,1,1,4]"_vi), true);
  CHECK(s.canJump("[3,2,1,0,4]"_vi), false);
  CHECK(s.canJump("[2,0]"_vi), true);
  CHECK(s.canJump("[0,2,3]"_vi), false);
  CHECK(s.canJump("[1,0,1,0]"_vi), false);
  return 0;
}
