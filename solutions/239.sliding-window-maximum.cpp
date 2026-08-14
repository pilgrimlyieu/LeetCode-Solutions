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

/// 优先队列解法
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

int main(void) {
  Solution s;
  CHECK(s.maxSlidingWindow("[1,3,-1,-3,5,3,6,7]"_vi, 3), "[3,3,5,5,6,7]"_vi);
  CHECK(s.maxSlidingWindow("[7,6,3,5,-3,-1,3,1]"_vi, 3), "[7,6,5,5,3,3]"_vi);
  CHECK(s.maxSlidingWindow("[1,2,3,4,5,6]"_vi, 1), "[1,2,3,4,5,6]"_vi);
  CHECK(s.maxSlidingWindow("[6,5,4,3,2,1]"_vi, 1), "[6,5,4,3,2,1]"_vi);
  CHECK(s.maxSlidingWindow("[1]"_vi, 1), "[1]"_vi);
  return 0;
}
