// @leet imports start
// Created: 2026-09-08 22:22:54

#include "../utils.h"
#include <deque>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    int m = edges.size();
    vector<int> parent(n), rank(n);
    iota(parent.begin(), parent.end(), 0);
    auto find = [&](this auto &&self, int x) {
      if (x == parent[x]) {
        return x;
      }
      parent[x] = self(parent[x]);
      return parent[x];
    };
    auto unite = [&](int x, int y) {
      int rx = find(x), ry = find(y);
      if (rx == ry) {
        return;
      }
      if (rank[rx] > rank[ry]) {
        swap(rx, ry);
      }
      parent[rx] = ry;
      if (rank[rx] == rank[ry]) {
        rank[ry]++;
      }
    };
    for (auto &edge : edges) {
      unite(edge[0], edge[1]);
    }
    return find(source) == find(destination);
  }
};
// @leet end

// @card idea 并查集
// 检查 `source` 与 `destination` 是否在一个连通分量即可。

// @card note
// 也可以从 `source` 开始用 BFS/DFS 遍历完一个连通分量。

int main() {
  Solution s;
  CHECK(s.validPath(3, "[[0,1],[1,2],[2,0]]"_vvi, 0, 2), true);
  CHECK(s.validPath(6, "[[0,1],[0,2],[3,5],[5,4],[4,3]]"_vvi, 0, 5), false);
  return 0;
}
