// @leet imports start
// Created: 2026-09-08 21:43:22

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size(), ans = n;
    vector<int> parent(n), rank(n);
    iota(parent.begin(), parent.end(), 0);
    auto find = [&](this auto &&self, int x) -> int {
      if (parent[x] != x) {
        parent[x] = self(parent[x]);
      }
      return parent[x];
    };
    auto unite = [&](int x, int y) {
      int rx = find(x), ry = find(y);
      if (rx == ry) {
        return;
      }
      ans--; // 合并时集合总数减一
      if (rank[rx] > rank[ry]) {
        swap(rx, ry);
      }
      parent[rx] = ry; // 按秩合并
      if (rank[rx] == rank[ry]) {
        rank[ry]++; // 高度相同时变高
      }
    };
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (isConnected[i][j]) {
          unite(i, j);
        }
      }
    }
    return ans;
  }
};
// @leet end

// @card note
// 也可以 DFS/BFS，标记是否访问过，若未访问则继续 DFS/BFS。

int main() {
  Solution s;
  CHECK(s.findCircleNum("[[1,1,0],[1,1,0],[0,0,1]]"_vvi), 2);
  CHECK(s.findCircleNum("[[1,0,0],[0,1,0],[0,0,1]]"_vvi), 3);
  return 0;
}
