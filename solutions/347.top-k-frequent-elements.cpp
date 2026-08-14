// @leet imports start
// Created: 2025-10-22 10:44:29

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    vector<int> ans;
    ans.reserve(k);
    for (auto num : nums) {
      freq[num]++;
    }
    using P = pair<int, int>;
    auto cmp = [](P a, P b) { return a.first > b.first; };
    priority_queue<P, vector<P>, decltype(cmp)> pq(cmp); // 小根堆
    for (auto p : freq) {
      pq.emplace(p.second, p.first);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    while (!pq.empty()) {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    return ans;
  }
};
// @leet end

/// 桶排序，理论更优
vector<int> topKFrequent(vector<int> &nums, int k) {
  int n = nums.size();
  unordered_map<int, int> freq;
  vector<int> ans;
  ans.reserve(k);
  for (auto num : nums) {
    freq[num]++;
  }
  vector<vector<int>> bkt(n + 1);
  for (auto p : freq) {
    bkt[p.second].push_back(p.first);
  }
  for (int i = n; i >= 1; i--) {
    for (auto v : bkt[i]) {
      ans.push_back(v);
      if (ans.size() == k) {
        return ans;
      }
    }
  }
  return ans; // __builtin_unreachable();
}

int main(void) {
  Solution s;
  CHECK_ANYORDER(s.topKFrequent("[1,1,2,3,4,5,5]"_vi, 2), "[1,5]"_vi);
  return 0;
}
