// @leet imports start
// Created: 2026-08-30 15:01:18

#include "../utils.h"
#include <algorithm>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size(), len2 = nums2.size(), ans = 0;
    auto max_len = [&](int idx1, int idx2) {
      int curr = 0, max_len = 0;
      while (idx1 < len1 && idx2 < len2) {
        if (nums1[idx1++] == nums2[idx2++]) {
          curr++;
        } else {
          curr = 0;
        }
        max_len = max(max_len, curr);
      }
      return max_len;
    };
    for (int i = 0; i < len1; i++) {
      ans = max(ans, max_len(i, 0));
    }
    for (int i = 0; i < len2; i++) {
      ans = max(ans, max_len(0, i));
    }
    return ans;
  }
};
// @leet end

// @card idea 滑动窗口
// 不断对齐，并统计此时重合的情况即可。时间复杂度 $O((m + n) \times \min(m, n))$，空间复杂度 $O(1)$。

// @alt 动态规划
// 考虑 `dp[i][j]` 为 `A[i..]` 与 `B[j..]` 最长公共前缀长度，并使用滑动数组优化。时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。
class SolutionDP {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size(), len2 = nums2.size(), ans = 0;
    vector<int> dp(len2 + 1);
    for (int i = len1 - 1; i >= 0; i--) {
      for (int j = 0; j < len2; j++) {
        dp[j] = (nums1[i] == nums2[j]) ? dp[j + 1] + 1 : 0;
        ans = max(ans, dp[j]);
      }
    }
    return ans;
  }
};
// @alt end

// @alt 哈希 + 二分搜索
class SolutionHash {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    return 0; // TODO:
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.findLength("[1,2,3,2,1]"_vi, "[3,2,1,4,7]"_vi), 3);
  CHECK(s.findLength("[0,0,0,0,0]"_vi, "[0,0,0,0,0]"_vi), 5);
  return 0;
}
