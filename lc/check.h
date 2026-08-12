#pragma once

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

#include "print.h"

/**
 * @brief CHECK 宏：序列化比对断言 ---
 * CHECK(actual, expected)                   基础比对
 * CHECK("示例2", actual, expected)          带用例标签
 * CHECK_ANYORDER([label,] actual, expected) 排序后比对（任意顺序均可的题）
 * CHECK_INPLACE(call, modified, expected)   void 函数改引参：先调用后比对
 * CHECK_FIRSTK(k_call, vec, expected)       返回 k 取前 k 个比对
 * main 返回后打印汇总；有失败以非零码退出。
 */

namespace lc_check {

const double EPS = 1e-5; // 浮点数比较容差

inline int passed = 0;
inline int failed = 0;

inline bool use_color() {
  static const bool tty = isatty(fileno(stdout)) != 0;
  return tty;
}
inline const char *c_green() {
  return use_color() ? "\033[32m" : "";
}
inline const char *c_red() {
  return use_color() ? "\033[31m" : "";
}
inline const char *c_dim() {
  return use_color() ? "\033[2m" : "";
}
inline const char *c_reset() {
  return use_color() ? "\033[0m" : "";
}

template <typename T> std::string stringify(const T &value) {
  std::ostringstream oss;
  if constexpr (std::is_floating_point_v<std::decay_t<T>>) {
    oss << lc_print::format_double(value);
  } else {
    oss << value;
  }
  return oss.str();
}

struct Summary {
  ~Summary() {
    if (passed + failed == 0) {
      return;
    }
    std::cout << "\n== " << passed << " passed, " << failed
              << " failed ==" << std::endl;
    if (failed > 0) {
      std::_Exit(1);
    }
  }
};
inline Summary summary;

// 首个差异处的 ^ 指示行（两串同位逐字符比较）
inline std::string diff_caret(const std::string &a, const std::string &e) {
  size_t i = 0;
  while (i < a.size() && i < e.size() && a[i] == e[i]) {
    ++i;
  }
  return std::string(i, ' ') + "^";
}

inline void report(const char *file, int line, const std::string &label,
                   const std::string &actual, const std::string &expected,
                   bool ok) {
  if (ok) {
    ++passed;
    std::cout << c_green() << "PASS" << c_reset();
    if (!label.empty()) {
      std::cout << " " << c_dim() << label << c_reset();
    }
    std::cout << " " << actual << std::endl;
  } else {
    ++failed;
    std::cout << c_red() << "FAIL" << c_reset() << " ";
    if (!label.empty()) {
      std::cout << label << " ";
    }
    std::cout << c_dim() << file << ":" << line << c_reset()
              << "\n  expected: " << expected << "\n  actual:   " << actual
              << "\n            " << c_red() << diff_caret(actual, expected)
              << c_reset() << std::endl;
  }
}

template <typename A, typename E>
void check(const char *file, int line, const std::string &label,
           const A &actual, const E &expected) {
  if constexpr (std::is_arithmetic_v<std::decay_t<A>> &&
                std::is_arithmetic_v<std::decay_t<E>> &&
                (std::is_floating_point_v<std::decay_t<A>> ||
                 std::is_floating_point_v<std::decay_t<E>>)) {
    bool ok = std::abs(static_cast<double>(actual) -
                       static_cast<double>(expected)) <= EPS;
    report(file, line, label, stringify(static_cast<double>(actual)),
           stringify(static_cast<double>(expected)), ok);
  } else {
    std::string a = stringify(actual);
    std::string e = stringify(expected);
    report(file, line, label, a, e, a == e);
  }
}
// 无标签二参形式
template <typename A, typename E>
void check(const char *file, int line, const A &actual, const E &expected) {
  check(file, line, "", actual, expected);
}

template <typename A, typename E>
void check_anyorder(const char *file, int line, const std::string &label,
                    A actual, E expected) {
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  check(file, line, label, actual, expected);
}
template <typename A, typename E>
void check_anyorder(const char *file, int line, A actual, E expected) {
  check_anyorder(file, line, "", std::move(actual), std::move(expected));
}

// 前 k 个比对：k 为函数返回值（负值按 0 处理），vec 为被修改的实参
template <typename V, typename E>
void check_firstk(const char *file, int line, long long k, const V &vec,
                  const E &expected) {
  using Elem = std::decay_t<decltype(*std::begin(vec))>;
  auto count = std::clamp<long long>(k, 0, static_cast<long long>(vec.size()));
  std::vector<Elem> prefix(std::begin(vec), std::begin(vec) + count);
  check(file, line, "k=" + std::to_string(k), prefix, expected);
}
template <typename V, typename E>
void check_firstk_anyorder(const char *file, int line, long long k, V vec,
                           E expected) {
  using Elem = std::decay_t<decltype(*std::begin(vec))>;
  auto count = std::clamp<long long>(k, 0, static_cast<long long>(vec.size()));
  std::vector<Elem> prefix(std::begin(vec), std::begin(vec) + count);
  check_anyorder(file, line, "k=" + std::to_string(k), prefix, expected);
}

} // namespace lc_check

// 变参转发：braced-init-list 的逗号由 C++
// 解析器处理；二参/三参（带标签）自动分派
#define CHECK(...) lc_check::check(__FILE__, __LINE__, __VA_ARGS__)
#define CHECK_ANYORDER(...)                                                    \
  lc_check::check_anyorder(__FILE__, __LINE__, __VA_ARGS__)
// void 原地修改：先求值 call，再比对 modified
#define CHECK_INPLACE(call, modified, expected)                                \
  do {                                                                         \
    (call);                                                                    \
    CHECK((modified), (expected));                                             \
  } while (0)
// 返回 k、取前 k 个：k_call 求值一次
#define CHECK_FIRSTK(k_call, vec, expected)                                    \
  lc_check::check_firstk(__FILE__, __LINE__, (k_call), (vec), (expected))
#define CHECK_FIRSTK_ANYORDER(k_call, vec, expected)                           \
  lc_check::check_firstk_anyorder(__FILE__, __LINE__, (k_call), (vec),         \
                                  (expected))
