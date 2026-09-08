// @leet imports start
// Created: 2026-09-07 17:29:30

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class NumArray {
public:
  vector<int> prefixSum;

  NumArray(vector<int> &nums) {
    prefixSum.reserve(nums.size() + 1);
    prefixSum.push_back(0);
    for (int sum = 0; auto num : nums) {
      sum += num;
      prefixSum.push_back(sum);
    }
  }

  int sumRange(int left, int right) {
    return prefixSum[right + 1] - prefixSum[left];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @leet end

int main() {
  // NumArray obj;
  // 样例 1 输入: ["NumArray","sumRange","sumRange","sumRange"]; [[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]
  // 样例 1 输出: [null, 1, -1, -3]
  return 0;
}
