// @leet imports start
// Created: 2026-09-08 17:47:12

#include "../utils.h"
#include <deque>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> indegrees(numCourses);
    for (auto &edge : prerequisites) {
      edges[edge[1]].push_back(edge[0]);
      indegrees[edge[0]]++;
    }
    deque<int> q;
    for (int u = 0; u < numCourses; u++) {
      if (indegrees[u] == 0) {
        q.push_back(u);
      }
    }
    vector<int> ans;
    while (!q.empty()) {
      int u = q.front();
      q.pop_front();
      ans.push_back(u);
      for (auto v : edges[u]) {
        indegrees[v]--;
        if (indegrees[v] == 0) {
          q.push_back(v);
        }
      }
    }
    if (ans.size() < numCourses) {
      ans.clear();
    }
    return ans;
  }
};
// @leet end

// @alt DFS
class SolutionDFS {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> visited(numCourses, 0), ans(numCourses);
    int idx = numCourses;
    for (auto &edge : prerequisites) {
      edges[edge[1]].push_back(edge[0]);
    }
    auto dfs = [&](this auto &&self, int u) -> bool {
      visited[u] = 1;
      for (auto v : edges[u]) {
        if (visited[v] == 1 || visited[v] == 0 && !self(v)) {
          return false;
        }
      }
      visited[u] = 2;
      ans[--idx] = u; // 也可以空 `ans` 直接 `push_back`，最后 `reverse`。
      return true;
    };
    for (int u = 0; u < numCourses; u++) {
      if (visited[u] == 0) {
        if (!dfs(u)) {
          return {};
        }
      }
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.findOrder(2, "[[1,0]]"_vvi), "[0,1]"_vi);
  CHECK(s.findOrder(4, "[[1,0],[2,0],[3,1],[3,2]]"_vvi), "[0,2,1,3]"_vi);
  CHECK(s.findOrder(1, "[]"_vvi), "[0]"_vi);
  return 0;
}
