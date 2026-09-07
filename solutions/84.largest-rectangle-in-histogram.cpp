// @leet imports start
// Created: 2026-09-07 15:03:59

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size(), ans = 0;
    vector<int> left(n), right(n, n), stk;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && heights[i] < heights[stk.back()]) {
        right[stk.back()] = i;
        stk.pop_back();
      }
      left[i] = stk.empty() ? -1 : stk.back();
      stk.push_back(i);
    }
    for (int i = 0; i < n; i++) {
      ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    return ans;
  }
};
// @leet end

// @card hint
// 一次遍历双边单调栈？

// @card note
// 我最初的想法是只维护一个单调栈，表示右侧第一个更矮的下标。然后遍历的时候反复递减，这一条链就都会计算过，后面可以跳过。

// @alt 单栈
// 维护高度严格递增的单调栈，当有一个新柱子 `i` 比栈顶矮，则：
// 1. 栈顶柱子的右边界就是 `i`；
// 2. 栈顶柱子的左边界就是弹出它后的新栈顶（单调栈的性质）；
// 3. 以其为高度核心可计算面积。
//
// 使用一个哨兵节点，确保栈最后清空，避免处理额外情况。
class Solution1Stack {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size(), ans = 0;
    heights.push_back(0);
    vector<int> stk;
    for (int i = 0; i <= n; i++) { // 要包括 0 哨兵，避免额外处理
      while (!stk.empty() && heights[i] < heights[stk.back()]) {
        int height = heights[stk.back()];
        stk.pop_back();
        int left = stk.empty() ? -1 : stk.back();
        int width = i - left - 1;
        ans = max(ans, height * width);
      }
      stk.push_back(i);
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.largestRectangleArea("[2,1,5,6,2,3]"_vi), 10);
  CHECK(s.largestRectangleArea("[2,4]"_vi), 4);
  return 0;
}
