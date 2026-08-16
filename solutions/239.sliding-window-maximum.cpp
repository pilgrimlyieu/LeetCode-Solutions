// @leet imports start
// Created: 2025-10-19 11:34:53

#include "../utils.h"
#include <algorithm>
#include <deque>
#include <iterator>
#include <queue>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    deque<int> dq;
    for (int i = 0; i < k; i++) {
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }
    vector<int> ans = {nums[dq.front()]};
    ans.reserve(n - k + 1);
    for (int i = k; i < n; i++) {
      if (dq.front() == i - k) {
        dq.pop_front();
      }
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      ans.push_back(nums[dq.front()]);
    }
    return ans;
  }
};
// @leet end

// @card idea 单调队列
// 当右侧有新元素进入滑动窗口时，左侧所有比它小的元素就不再需要保存，因为后面的滑动窗口不再可能成为最大值。
//
// 因此考虑队列，加入右侧新元素的时候，从队尾开始淘汰更小的元素，这样可以确保队列从首到尾的索引递增，且大小递减。
//
// 若从队首开始淘汰则无法保证中间更小的元素被淘汰（因为可能被队首更大的元素「保护」了）。

// @alt 优先队列（惰性删除）
// 大根堆存 `(值, 下标)`，取最大前先弹掉滑出窗口的堆顶。
class SolutionPQ {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++) {
      pq.emplace(nums[i], i); // 需用 emplace，push {nums[i], i} 会有 lint
    }
    vector<int> ans = {pq.top().first};
    ans.reserve(n - k + 1);
    for (int i = k; i < n; i++) {
      while (!pq.empty() && pq.top().second <= i - k) {
        pq.pop();
      }
      pq.emplace(nums[i], i);
      ans.push_back(pq.top().first);
    }
    return ans;
  }
};
// @alt end

int main(void) {
  Solution s;
  SolutionPQ s2;
  CHECK(s.maxSlidingWindow("[1,3,-1,-3,5,3,6,7]"_vi, 3), "[3,3,5,5,6,7]"_vi);
  CHECK(s.maxSlidingWindow("[7,6,3,5,-3,-1,3,1]"_vi, 3), "[7,6,5,5,3,3]"_vi);
  CHECK(s.maxSlidingWindow("[1,2,3,4,5,6]"_vi, 1), "[1,2,3,4,5,6]"_vi);
  CHECK(s.maxSlidingWindow("[6,5,4,3,2,1]"_vi, 1), "[6,5,4,3,2,1]"_vi);
  CHECK(s.maxSlidingWindow("[1]"_vi, 1), "[1]"_vi);
  CHECK(s2.maxSlidingWindow("[1,3,-1,-3,5,3,6,7]"_vi, 3), "[3,3,5,5,6,7]"_vi);
  CHECK(s2.maxSlidingWindow("[7,6,3,5,-3,-1,3,1]"_vi, 3), "[7,6,5,5,3,3]"_vi);
  return 0;
}
