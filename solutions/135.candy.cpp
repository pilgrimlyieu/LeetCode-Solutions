// @leet imports start
// Created: 2026-08-24 14:41:19

#include "../utils.h"
#include <queue>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }
    }
    int sum = candies[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        candies[i] = max(candies[i], candies[i + 1] + 1);
      }
      sum += candies[i];
    }
    return sum;
  }
};
// @leet end

// @card idea 两次遍历
// 1. 第一次遍历的时候，让每个元素符合左规则，即若评分比左邻元素高，则多发一个糖果；
// 2. 第二次遍历的时候，再让每个元素符合右规则，同时收集糖果总数。

// @alt 常数空间遍历
// 上升的时候，额外比上一个多给一颗即可。下降的时候记录下降序列长度，并每次给序列中所有多发一颗。需要额外记录峰值，若下降序列长度已经等于峰值了，说明峰值也应该一起抬升，一同算入下降序列。
//
// 也可以将 `down` 的语义限制在不包含峰值的下降序列长度，这样需要 `if (down >= peak) sum++;`。上面的写法 `peak` 必须初值为 `1`，否则序列一开始就下降的时候并不会触发补偿。而这种写法则会，并可以把 `peak` 初值设置为 `0`。
class SolutionAdvanced {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    int down = 0, up = 0, peak = 1, sum = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) { // 上升段
        up++;
        down = 0;
        peak = up + 1;
        sum += up + 1;
      } else if (ratings[i] < ratings[i - 1]) { // 下降段
        down++;
        up = 0;
        if (down == peak) { // 将峰值也算入下降段一起抬升
          down++;
        }
        sum += down;
      } else {
        up = down = 0;
        peak = 1;
        sum++;
      }
    }
    return sum;
  }
};
// @alt end

int main() {
  SolutionAdvanced s;
  CHECK(s.candy("[2]"_vi), 1);
  CHECK(s.candy("[1,2,5,4,3,2,2,1]"_vi), 16);
  CHECK(s.candy("[1,4,3,2,2,1]"_vi), 10);
  CHECK(s.candy("[1,0,2]"_vi), 5);
  CHECK(s.candy("[1,2,2]"_vi), 4);
  CHECK(s.candy("[1,2,4,4,3]"_vi), 9);
  CHECK(s.candy("[1,2,3,2,1]"_vi), 9);
  CHECK(s.candy("[1,6,10,8,7,3,2]"_vi), 18);
  CHECK(s.candy("[1,2,3,5,4,3,2,1,4,3,2,1]"_vi), 31);
  CHECK(s.candy("[1,2,3,5,4,3,2,1,4,3,2,1,3,2,1,1,2,3,4]"_vi), 47);
  return 0;
}
