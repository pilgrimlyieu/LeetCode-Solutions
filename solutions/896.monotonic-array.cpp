// @leet imports start
// Created: 2025-09-14 11:26:14

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool isMonotonic(vector<int> &nums) {
    int len = nums.size();
    int idx = 0;
    for (; idx < len - 1; idx++) {
      if (nums[idx] != nums[idx + 1]) {
        goto cont;
      }
    }
    return true;
  cont:
    bool isPos = nums[idx + 1] > nums[idx];
    for (int i = idx + 1; i < len - 1; i++) {
      if ((isPos && nums[i + 1] < nums[i]) ||
          (!isPos && nums[i + 1] > nums[i])) {
        return false;
      }
    }
    return true;
  }
};
// @leet end

int main(void) {
  Solution s;
  vector<int> n1 = {1, 1, 0};
  vector<int> n2 = {2, 2, 2, 1, 4, 5};
  cout << s.isMonotonic(n1);
  cout << s.isMonotonic(n2);
  return 0;
}
