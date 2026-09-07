// @leet imports start
// Created: 2026-09-07 18:36:07

#include "../utils.h"
#include <numeric>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefix(n), suffix(n);
    for (int i = 0; i < n - 1; i++) {
      prefix[i + 1] = prefix[i] + nums[i];
      suffix[n - 2 - i] = suffix[n - 1 - i] + nums[n - 1 - i];
    }
    for (int i = 0; i < n; i++) {
      if (prefix[i] == suffix[i]) {
        return i;
      }
    }
    return -1;
  }
};
// @leet end

// @alt 无额外空间
class SolutionSpaceOptimized {
public:
  int pivotIndex(vector<int> &nums) {
    int total = reduce(nums.begin(), nums.end());
    for (int i = 0, sum = 0; i < nums.size(); i++) {
      if (2 * sum + nums[i] == total) {
        return i;
      }
      sum += nums[i];
    }
    return -1;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.pivotIndex("[1,7,3,6,5,6]"_vi), 3);
  CHECK(s.pivotIndex("[1,2,3]"_vi), -1);
  CHECK(s.pivotIndex("[2,1,-1]"_vi), 0);
  return 0;
}
