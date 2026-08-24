// @leet imports start
// Created: 2026-08-24 17:29:00

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    int n = people.size();
    vector<vector<int>> ans(n);
    sort(people.begin(), people.end(), [](auto a, auto b) {
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    for (auto p : people) {
      int spaces = p[1], idx = 0;
      while (spaces) { // 确保前面有高者符合个数
        if (ans[idx].empty()) {
          spaces--;
        }
        idx++;
      }
      while (!ans[idx].empty()) { // 确保占据的是空位
        idx++;
      }
      ans[idx] = p;
    }
    return ans;
  }
};
// @leet end

// @card idea 贪心
// 每次选择最矮的进行排序，已经排序过的都是更矮的（或相等），可以忽视或特殊处理。
//
// 对于相同高度的，可以记录连续相同高度的数目然后 `spaces` 进行处理，也可以在排序阶段，优先排序队列后面的，即 `k_i` 更大先排。
//
// 时间复杂度是 $O(n^2)$，可以用更复杂的数据结构如树状数组、线段树优化，不过这里没有这个必要。

int main() {
  Solution s;
  CHECK(s.reconstructQueue("[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]"_vvi),
        "[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]"_vvi);
  CHECK(s.reconstructQueue("[[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]"_vvi),
        "[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]"_vvi);
  return 0;
}
