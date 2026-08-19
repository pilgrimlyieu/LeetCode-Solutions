// @leet imports start
// Created: 2026-08-22 22:15:59

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < g.size() && j < s.size()) {
      if (g[i] <= s[j]) {
        i++;
      }
      j++;
    }
    return i;
  }
};
// @leet end

// @card idea 贪心
// 排序，从最小开始满足。

int main() {
  Solution s;
  CHECK(s.findContentChildren("[1,2,3]"_vi, "[1,1]"_vi), 1);
  CHECK(s.findContentChildren("[1,2]"_vi, "[1,2,3]"_vi), 2);
  CHECK(s.findContentChildren("[1,2,9,9,10]"_vi, "[1,2,3,10]"_vi), 3);
  CHECK(s.findContentChildren("[10,9,8,7]"_vi, "[5,6,7,8]"_vi), 2);
  return 0;
}
