// @leet imports start
// Created: 2026-08-18 21:13:51

#include "../utils.h"
#include <algorithm>
#include <ranges>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    auto valid = [&](int k) -> bool {
      return ranges::fold_left(piles | views::transform([&](auto a) {
                                 return (a + k - 1) / k;
                               }),
                               0L, plus<>()) <= h;
    };
    int left = max(accumulate(piles.begin(), piles.end(), 0L) / h, 1L),
        right = *max_element(piles.begin(), piles.end()) + 1;
    while (left < right) {
      auto mid = (left + right) / 2;
      if (!valid(mid)) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
// @leet end

// @card hint
// 另外思考向上取整 `ceil(int a, int b)` 的写法。

// @card idea
// 本质上是二分，没啥奇思妙想的算法。

// @card note
// 1. `ceil(int a, int b)` 可以写成 `(a + b - 1) / b`。
// 2. 注意溢出问题，求和的地方使用 `long`，同时初值或常数参数用 `0L` 等匹配模板类型约束。
// 3. 注意 `left` 初值可能为 0 的除零问题。
// 4. 试用了一些 ranges 语法，不过 API 用着难受，实际上自己写也花不了多少时间。

int main() {
  Solution s;
  CHECK(s.minEatingSpeed("[3,6,7,11]"_vi, 8), 4);
  CHECK(s.minEatingSpeed("[30,11,23,4,20]"_vi, 5), 30);
  CHECK(s.minEatingSpeed("[30,11,23,4,20]"_vi, 6), 23);
  CHECK(
      s.minEatingSpeed(
          "[332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184]"_vi,
          823855818),
      14);
  CHECK(s.minEatingSpeed("[312884470]"_vi, 968709470), 1);
  return 0;
}
