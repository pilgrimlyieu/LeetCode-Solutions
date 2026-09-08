// @leet imports start
// Created: 2026-09-08 20:06:55

#include "../utils.h"
#include <deque>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    int n = wordList.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      mp[wordList[i]] = i;
    }
    if (!mp.contains(endWord)) {
      return 0;
    }
    deque<int> dqBegin, dqEnd;
    dqBegin.push_back(-1);
    dqEnd.push_back(mp[endWord]);
    vector<bool> beginVisited(n), endVisted(n);
    endVisted[mp[endWord]] = true; // 记得初始化
    int step = 1;
    while (!dqBegin.empty() && !dqEnd.empty()) {
      if (dqBegin.size() > dqEnd.size()) {
        swap(dqBegin, dqEnd);
        swap(beginVisited, endVisted);
      }
      int size = dqBegin.size();
      while (size--) {
        auto idx = dqBegin.front();
        dqBegin.pop_front();
        string &curr = idx == -1 ? beginWord : wordList[idx];
        if (mp.contains(curr) && endVisted[mp[curr]]) { // 要避免额外插入
          return step;
        }
        for (int i = 0; i < curr.size(); i++) {
          auto originalChar = curr[i];
          for (auto c = 'a'; c <= 'z'; c++) {
            if (c == originalChar) {
              continue;
            }
            curr[i] = c;
            if (mp.contains(curr) && !beginVisited[mp[curr]]) {
              dqBegin.push_back(mp[curr]);
              beginVisited[mp[curr]] = true;
            }
          }
          curr[i] = originalChar;
        }
      }
      step++;
    }
    return 0;
  }
};
// @leet end

// @card idea 双向 BFS
// 选择节点少的一侧扩展。

// @alt 单向 BFS
class SolutionOneWayBFS {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    int n = wordList.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      mp[wordList[i]] = i;
    }
    if (!mp.contains(endWord)) {
      return 0;
    }
    deque<int> q;
    q.push_back(-1);
    vector<bool> visited(n);
    int step = 1;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto idx = q.front();
        q.pop_front();
        string &curr = idx == -1 ? beginWord : wordList[idx];
        if (curr == endWord) {
          return step;
        }
        for (int i = 0; i < curr.size(); i++) {
          auto originalChar = curr[i];
          for (char c = 'a'; c <= 'z'; c++) {
            if (c == originalChar) {
              continue;
            }
            curr[i] = c;
            if (mp.contains(curr) && !visited[mp[curr]]) {
              q.push_back(mp[curr]);
              visited[mp[curr]] = true;
            }
          }
          curr[i] = originalChar;
        }
      }
      step++;
    }
    return 0;
  }
};
// @alt end

// @card note
// 老老实实把 `beginWord` 加进词典吧，不然还要特判 -1。

int main() {
  Solution s;
  CHECK(s.ladderLength("hit", "cog",
                       R"(["hot","dot","dog","lot","log","cog"])"_vs),
        5);
  CHECK(s.ladderLength("hit", "cog", R"(["hot","dot","dog","lot","log"])"_vs),
        0);
  CHECK(s.ladderLength("a", "c", R"(["b","c","d"])"_vs), 2);
  return 0;
}
