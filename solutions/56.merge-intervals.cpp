// @leet imports start
// Created: 2026-08-27 17:31:55

#include "../utils.h"
#include <initializer_list>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int start = intervals[0][0], end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] > end) {
        ans.emplace_back(initializer_list{start, end});
        start = intervals[i][0];
      }
      end = max(end, intervals[i][1]);
    }
    ans.emplace_back(initializer_list{start, end});
    return ans;
  }
};
// @leet end

// @card note
// 注意这里常用的 `emplace_back(a, b)` 会有意料之外的结果，调用的是 `vector<int>` 的圆括号构造函数，将两个参数分别视为个数和值。
//
// 即便加 `{}` 也无效，因为其没有类型。要么使用 `push_back`，要么用 `emplace_back(initializer_list{a, b})`。不过这里可以直接用 `push_back`，因为 `vector` 的移动构造是 $O(1)$ 的，只会交换内部指针，成本极低。

int main() {
  Solution s;
  CHECK(s.merge("[[1,3],[2,6],[8,10],[15,18]]"_vvi),
        "[[1,6],[8,10],[15,18]]"_vvi);
  CHECK(s.merge("[[1,4],[4,5]]"_vvi), "[[1,5]]"_vvi);
  CHECK(s.merge("[[4,7],[1,4]]"_vvi), "[[1,7]]"_vvi);
  return 0;
}
