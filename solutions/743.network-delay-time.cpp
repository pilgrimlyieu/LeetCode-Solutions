// @leet imports start
// Created: 2026-09-08 22:34:29

#include "../utils.h"
#include <functional>
#include <queue>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1); // adj[u] = {v, w}
    for (auto &e : times) {
      adj[e[0]].emplace_back(e[1], e[2]);
    }
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, k); // {当前距离, 节点}
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[u]) {
        continue;
      }
      for (auto &[v, w] : adj[u]) {
        if (dist[u] < dist[v] - w) { // 防溢出
          dist[v] = dist[u] + w;
          pq.emplace(dist[v], v);
        }
      }
    }
    int ans = *max_element(dist.begin() + 1, dist.end()); // 注意排除 0 的哑节点
    return ans != INT_MAX ? ans : -1;
  }
};
// @leet end

// @card note
// 对稠密图的情形，也可以不使用小根堆，而是用一个 `visited` 数组枚举。

int main() {
  Solution s;
  CHECK(s.networkDelayTime("[[2,1,1],[2,3,1],[3,4,1]]"_vvi, 4, 2), 2);
  CHECK(s.networkDelayTime("[[1,2,1]]"_vvi, 2, 1), 1);
  CHECK(s.networkDelayTime("[[1,2,1]]"_vvi, 2, 2), -1);
  return 0;
}
