// @leet imports start
// Created: 2026-09-08 22:03:59

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
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
        return true;
      }
      if (rank[rx] > rank[ry]) {
        swap(rx, ry);
      }
      parent[rx] = ry;
      if (rank[rx] == rank[ry]) {
        rank[ry]++;
      }
      return false;
    };
    for (auto &edge : edges) {
      if (unite(edge[0] - 1, edge[1] - 1)) {
        return edge;
      }
    }
    __builtin_unreachable();
  }
};
// @leet end

// @card idea 并查集
// 冗余边在合并的时候，两边已经在同一个连通分量了。

int main() {
  Solution s;
  CHECK(s.findRedundantConnection("[[1,2],[1,3],[2,3]]"_vvi), "[2,3]"_vi);
  CHECK(s.findRedundantConnection("[[1,2],[2,3],[3,4],[1,4],[1,5]]"_vvi),
        "[1,4]"_vi);
  return 0;
}
