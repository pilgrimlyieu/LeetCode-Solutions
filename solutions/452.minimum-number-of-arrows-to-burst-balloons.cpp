// @leet imports start
// Created: 2026-08-27 14:48:18

#include "../utils.h"
#include <unordered_map>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end());
    int cnt = 1, pos = points[0][1];
    for (int i = 1; i < points.size(); i++) {
      if (points[i][0] > pos) {
        cnt++;
        pos = points[i][1]; // 未重叠，更新右边界
      } else {
        pos = min(pos, points[i][1]); // 重叠，取交集
      }
    }
    return cnt;
  }
};
// @leet end

// @card idea 区间合并
// 若当前区间与上一个区间有重叠，则说明这一箭可以同时覆盖当前区间，再取交集（即缩减右边界）。

// @alt 贪心
// 另一种思路，直接按右边界进行排序。
//
// 核心思想：右端点是当前气球能覆盖到的最右位置，选择它不会减少覆盖后面气球的机会。
class SolutionGreedy {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(),
         [](auto &a, auto &b) { return a[1] < b[1]; });
    int cnt = 1, pos = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > pos) {
        cnt++;
        pos = points[i][1];
      }
    }
    return cnt;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.findMinArrowShots("[[10,16],[2,8],[1,6],[7,12]]"_vvi), 2);
  CHECK(s.findMinArrowShots("[[1,2],[3,4],[5,6],[7,8]]"_vvi), 4);
  CHECK(s.findMinArrowShots("[[1,2],[2,3],[3,4],[4,5]]"_vvi), 2);
  CHECK(s.findMinArrowShots(
            "[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]"_vvi),
        2);
  CHECK(
      s.findMinArrowShots(
          "[[7,15],[6,14],[8,12],[3,4],[4,13],[6,14],[9,11],[6,12],[4,13]]"_vvi),
      2);
  return 0;
}
