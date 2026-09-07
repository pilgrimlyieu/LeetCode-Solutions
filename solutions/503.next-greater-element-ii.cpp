// @leet imports start
// Created: 2026-09-07 14:35:36

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, -1), stk;
    for (int i = 0; i < 2 * n - 1; i++) {
      int idx = i % n;
      while (!stk.empty() && nums[idx] > nums[stk.back()]) {
        ans[stk.back()] = nums[idx];
        stk.pop_back();
      }
      stk.push_back(idx);
    }
    return ans;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.nextGreaterElements("[1,2,1]"_vi), "[2,-1,2]"_vi);
  CHECK(s.nextGreaterElements("[1,2,3,4,3]"_vi), "[2,3,4,-1,4]"_vi);
  return 0;
}
