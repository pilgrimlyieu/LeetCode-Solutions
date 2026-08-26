// @leet imports start
// Created: 2026-08-27 16:02:22

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a[1] < b[1]; });
    int cnt = 0, pos = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < pos) {
        cnt++;
      } else {
        pos = intervals[i][1];
      }
    }
    return cnt;
  }
};
// @leet end

// @card note
// 写 lambda 用 `auto` 的时候注意传值还是传引用！
//
// 例如说本例如果是 `[](auto a, auto b)` 类型推导会是 `vector<int>`，即按值传递，会造成大量拷贝。应当用 `auto &`。
//
// 当然规范写法应该是 `[](const auto &a, const auto &b)` 同时避免修改。

int main() {
  Solution s;
  CHECK(s.eraseOverlapIntervals("[[1,2],[2,3],[3,4],[1,3]]"_vvi), 1);
  CHECK(s.eraseOverlapIntervals("[[1,2],[1,2],[1,2]]"_vvi), 2);
  CHECK(s.eraseOverlapIntervals("[[1,2],[2,3]]"_vvi), 0);
  return 0;
}
