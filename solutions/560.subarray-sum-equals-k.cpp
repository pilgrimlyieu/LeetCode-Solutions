// @leet imports start
// Created: 2026-09-07 16:21:14

#include "../utils.h"
#include <unordered_map>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> prefixCount;
    int ans = 0, prefixSum = 0;
    for (auto num : nums) {
      prefixCount[prefixSum]++;
      prefixSum += num;
      if (prefixCount.contains(prefixSum - k)) {
        ans += prefixCount[prefixSum - k];
      }
    }
    return ans;
  }
};
// @leet end

// @card idea 前缀和 + 哈希表
// `[i, j]` 子数组和为 `prefixSum[j] - prefixSum[i-1] = k`。
//
// 固定一个 `j`，要寻找前面前缀和为 `k - prefixSum[j]` 的次数。

// @card note
// 还是检查一下是否存在为宜（`find` 或 C++20 的`contains`），不存在的情况会插入浪费大量时间与空间。

// @alt 暴力枚举
class SolutionEnumeration {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size(), ans = 0;
    for (int start = 0; start < n; start++) {
      int sum = 0;
      for (int end = start; end < n; end++) {
        sum += nums[end]; // sum = sum(nums[start..=end])
        if (sum == k) {
          ans++;
        }
      }
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.subarraySum("[1,1,1]"_vi, 2), 2);
  CHECK(s.subarraySum("[1,2,3]"_vi, 3), 2);
  CHECK(s.subarraySum("[6,4,3,1]"_vi, 10), 1);
  return 0;
}
