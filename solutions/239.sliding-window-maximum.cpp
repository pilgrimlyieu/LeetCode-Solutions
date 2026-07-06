// @leet imports start
// Created: 2025-10-19 11:34:53

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int len = nums.size();
    vector<int> r;
    r.reserve(len - k + 1);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++) {
      pq.emplace(nums[i], i);
    }
    r.emplace_back(pq.top().first);
    for (int i = k; i < len; i++) {
      pq.emplace(nums[i], i);
      while (pq.top().second <= i - k) {
        pq.pop();
      }
      r.emplace_back(pq.top().first);
    }
    return r;
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.maxSlidingWindow("[1,3,-1,-3,5,3,6,7]"_vi, 3)
       << endl; // 3, 3, 5, 5, 6, 7
  cout << s.maxSlidingWindow("[7,6,3,5,-3,-1,3,1]"_vi, 3)
       << endl; // 7, 6, 5, 5, 3, 3
  cout << s.maxSlidingWindow("[1,2,3,4,5,6]"_vi, 1) << endl;
  cout << s.maxSlidingWindow("[6,5,4,3,2,1]"_vi, 1) << endl;
  cout << s.maxSlidingWindow("[1]"_vi, 1) << endl; // 1
  return 0;
}
