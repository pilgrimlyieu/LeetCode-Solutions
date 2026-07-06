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
    int res = len + 1;
    int sum = 0;
    int left = 0;
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

int main(void) {
  Solution s;
  vector<int> v1 = {2, 3, 1, 2, 4, 3};
  cout << s.minSubArrayLen(7, v1) << endl; // 2
  vector<int> v2 = {1, 4, 4};
  cout << s.minSubArrayLen(4, v2) << endl; // 1
  vector<int> v3 = {1, 1, 1, 1};
  cout << s.minSubArrayLen(11, v3) << endl; // 0
  return 0;
}
