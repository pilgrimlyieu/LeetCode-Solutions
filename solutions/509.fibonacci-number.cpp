// @leet imports start
// Created: 2026-08-27 17:41:30

#include "../utils.h"
#include <bit>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int fib(int n) {
    if (n < 2) {
      return n;
    }
    int p = 0, q = 0, r = 1;
    for (int i = 2; i <= n; i++) {
      p = q;
      q = r;
      r = p + q;
    }
    return r;
  }
};
// @leet end

// @card idea 动态规划
// $F(n)$ 只依赖 $F(n-1), F(n-2)$，无需用一个数组旧值，滚动数组即可。

// @alt 代数
// 不用从小到大计算出每个值，实际上每次可以折半。注意到：
// $$
// \begin{bmatrix}
//     1 & 1 \\
//     1 & 0
// \end{bmatrix} \begin{bmatrix}
//     F(n) \\
//     F(n-1)
// \end{bmatrix} = \begin{bmatrix}
//     F(n+1) \\
//     F(n)
// \end{bmatrix}
// $$
//
// 于是有**斐波那契 Q 矩阵**：
// $$
// \bm{Q} = \begin{bmatrix}
//     1 & 1 \\
//     1 & 0
// \end{bmatrix},\quad \bm{Q}^n = \begin{bmatrix}
//     F_{n+1} & F_n \\
//     F_n & F_{n-1}
// \end{bmatrix}
// $$
//
// 则：
// $$
// \bm{Q}^{2k} = \bm{Q}^k \boldsymbol{\cdot} \bm{Q}^k = \begin{bmatrix}
//     F_{k+1}^2+F_k^2 & F_{k+1}F_k + F_kF_{k-1} \\
//     F_kF_{k+1}+F_{k-1}F_k & F_k^2+F_{k-1}^2
// \end{bmatrix}
// $$
//
// 得到：
// $$
// \left\lbrace\begin{aligned}
//     F_{2k} &= F_k(F_{k-1}+F_{k+1}) = F_k(2F_{k+1}-F_k) \\
//     F_{2k+1} &= F_k^2 + F_{k+1}^2
// \end{aligned}\right.
// $$
class SolutionAlgebra {
public:
  int fib(int n) {
    // 返回 (F(n), F(n+1))
    auto fib_pair = [](this auto &&self, int n) -> pair<int, int> {
      if (n == 0) {
        return {0, 1};
      }
      auto [p, q] = self(n >> 1);
      auto r = p * ((q << 1) - p);
      auto s = p * p + q * q;
      if (n & 1) {
        return {s, r + s}; // (F(2k+1), F(2k+2))
      } else {
        return {r, s}; // (F(2k), F(2k+1))
      }
    };
    // return fib_pair(n).first;
    if (n == 0) {
      return 0;
    }
    auto p = 0, q = 1; // F(0), F(1)
    // 或 sizeof(n) * 8 - 1 - __builtin_clz(n)
    auto bit = 1 << (bit_width((unsigned)n) - 1);
    while (bit) {
      auto r = p * ((q << 1) - p);
      auto s = p * p + q * q;
      if (n & bit) {
        p = s, q = r + s;
      } else {
        p = r, q = s;
      }
      bit >>= 1;
    }
    return p;
  }
};
// @alt end

// @card note
// 迭代的解法就是从高位到低位构造 `n`，从左到右扫描，`res = (res << 1) + bit`。

int main() {
  SolutionAlgebra s;
  CHECK(s.fib(0), 0);
  CHECK(s.fib(1), 1);
  CHECK(s.fib(2), 1);
  CHECK(s.fib(3), 2);
  CHECK(s.fib(4), 3);
  CHECK(s.fib(10), 55);
  return 0;
}
