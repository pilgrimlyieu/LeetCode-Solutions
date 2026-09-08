// @leet imports start
// Created: 2026-09-08 17:17:34

#include "../utils.h"
#include <deque>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> visited(numCourses, 0);
    for (auto &edge : prerequisites) {
      edges[edge[1]].push_back(edge[0]);
    }
    auto dfs = [&](this auto &&self, int u) -> bool {
      visited[u] = 1; // 正在访问
      for (auto v : edges[u]) {
        if (visited[v] == 1 || visited[v] == 0 && !self(v)) { // 发现环
          return false;
        }
      }
      visited[u] = 2; // 已访问
      return true;
    };
    for (int i = 0; i < numCourses; i++) {
      if (visited[i] == 0) {
        if (!dfs(i)) {
          return false;
        }
      }
    }
    return true;
  }
};
// @leet end

// @card idea DFS
// 利用深度优先搜索的后序遍历（即先访问完所有后继，再访问当前顶点），最后将后序序列反转，即可得到拓扑排序。
//
// 为了避免重复访问以及检测环，使用三种状态标记顶点：`0` 未访问、`1` 访问中（正在递归栈中）、`2` 已访问完毕。

// @alt Kahn
// 不断移除入度为 0 的顶点（即没有前置依赖），并将其加入结果序列；移除该顶点后，更新其邻接点的入度（减 1），若新的入度为 0，则加入队列。重复直到队列为空。
class SolutionKahn {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto &edge : prerequisites) {
      edges[edge[1]].push_back(edge[0]);
      indegree[edge[0]]++;
    }
    deque<int> q; // 所有入度为 0 的顶点
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        q.push_back(i);
      }
    }
    int count = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop_front();
      count++;
      for (auto v : edges[u]) {
        indegree[v]--;
        if (indegree[v] == 0) {
          q.push_back(v);
        }
      }
    }
    return count == numCourses;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.canFinish(2, "[[1,0]]"_vvi), true);
  CHECK(s.canFinish(2, "[[1,0],[0,1]]"_vvi), false);
  return 0;
}
