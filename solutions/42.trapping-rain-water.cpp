// @leet imports start
// Created: 2026-09-07 14:41:52

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size(), ans = 0;
    vector<int> left(n), right(n);
    for (int i = 1; i < n; i++) {
      left[i] = max(left[i - 1], height[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
      right[i] = max(right[i + 1], height[i + 1]);
    }
    for (int i = 0; i < n; i++) {
      ans += max(0, min(left[i], right[i]) - height[i]);
    }
    return ans;
  }
};
// @leet end

// @alt 双指针
// 左右两个指针，同时维护左右两边最大值，并计算左右指针地势较低处能接的高度并推进。
class SolutionLR {
public:
  int trap(vector<int> &height) {
    int ans = 0, left = 0, right = height.size() - 1, leftMax = 0, rightMax = 0;
    while (left < right) {
      leftMax = max(leftMax, height[left]);
      rightMax = max(rightMax, height[right]);
      if (height[left] < height[right]) {
        ans += leftMax - height[left++];
      } else {
        ans += rightMax - height[right--];
      }
    }
    return ans;
  }
};
// @alt end

// @alt 单调栈
class SolutionMonoStack {
public:
  int trap(vector<int> &height) {
    return 0; // TODO:
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.trap("[0,1,0,2,1,0,1,3,2,1,2,1]"_vi), 6);
  CHECK(s.trap("[4,2,0,3,2,5]"_vi), 9);
  return 0;
}
