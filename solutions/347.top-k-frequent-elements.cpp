// @leet imports start
// Created: 2025-10-22 10:44:29

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int idx = 0;
    int len = nums.size();
    vector<int> res;
    res.reserve(k);
    priority_queue<pair<int, int>> pq;
    while (idx < len) {
      int cur = idx;
      while (idx < len && nums[idx] == nums[cur]) {
        idx++;
      }
      pq.emplace(idx - cur, nums[cur]);
    }
    for (int i = 0; i < k; i++) {
      res.emplace_back(pq.top().second);
      pq.pop();
    }
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.topKFrequent("[1,1,2,3,4,5,5]"_vi, 2) << endl;
  return 0;
}
