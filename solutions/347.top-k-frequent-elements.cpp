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

// @card hint
// 学习如何获取类型，以及优先队列写法。

// @card idea 小根堆
// 堆顶部是要淘汰的元素，因此使用小根堆，必须给出第二个泛型参数即底层存储数据类型 `vector<P>`，与第三个泛型参数比较函数（`cmp(a, b)` 为 `true` 代表 `a` 应在 `b` 前）。
//
// 时间复杂度为 $O(n \log k)$，空间复杂度为 $O(m + k)$，其中 $m$ 为不同元素个数。

// @alt 桶排序
// 考虑到频率不超过 $n$，可以使用桶排序，理论复杂度更优。平均时间复杂度 $O(n)$，空间复杂度 $O(n)$。
class SolutionBucket {
public:
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
};
// @alt end

int main(void) {
  Solution s;
  SolutionBucket s2;
  CHECK_ANYORDER(s.topKFrequent("[1,1,2,3,4,5,5]"_vi, 2), "[1,5]"_vi);
  CHECK_ANYORDER(s2.topKFrequent("[1,1,2,3,4,5,5]"_vi, 2), "[1,5]"_vi);
  return 0;
}
