// @leet imports start
// Created: 2026-08-27 21:40:54

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int integerBreak(int n) {
    if (n <= 3) {
      return n - 1;
    }
    auto pow3 = [](int n) {
      long long res = 1, base = 3;
      while (n > 0) {
        if (n & 1) {
          res *= base;
        }
        base *= base;
        n >>= 1;
      }
      return res;
    };
    switch (n % 3) {
    case 0:
      return pow3(n / 3);
    case 1:
      return pow3(n / 3 - 1) << 2;
    case 2:
      return pow3(n / 3) << 1;
    }
    __builtin_unreachable();
  }
};
// @leet end

// @card hint
// 快速幂？

// @card idea 数学
// 由平方差公式注意到均分的时候乘积最大。定义 $f(x) = n x = c$，则 $n = \dfrac{c}{x}$，因此乘积为 $g(x) = x^n = x^{\frac{c}{x}}$，则 $h(x) = \ln g(x) = c \dfrac{\ln x}{x}$。
//
// 求导得 $\e$ 的时候取得最大值，且 $h(3) > h(2)$。显然不可能出现 2, 3 以外的整数，因此优先凑 3。注意到 $c \le 3$ 的特殊情形需要特判。
//
// 同时这里使用了快速幂。

int main() {
  Solution s;
  CHECK(s.integerBreak(2), 1);
  CHECK(s.integerBreak(10), 36);
  return 0;
}
