#pragma once

#include <cstdio>
#include <iostream>
#include <string_view>
#include <unistd.h>
#include <vector>

/**
 * @brief DBG 宏：解题中途的变量快照
 * DBG(i, dq, res) → [file:line] i = 3, dq = [1, 2], res = [3]
 * 输出到 stderr（不污染 CHECK 的 stdout），颜色按 isatty 门控。
 */

namespace lc_dbg {

inline bool use_color() {
  static const bool tty = isatty(fileno(stderr)) != 0;
  return tty;
}

// 按顶层逗号切分 #__VA_ARGS__（追踪 ()/[]/{}/<> 深度与字符串字面量）
inline std::vector<std::string_view> split_names(std::string_view names) {
  std::vector<std::string_view> out;
  int depth = 0;
  bool in_str = false;
  size_t start = 0;
  for (size_t i = 0; i < names.size(); ++i) {
    char c = names[i];
    if (in_str) {
      if (c == '"' && names[i - 1] != '\\') {
        in_str = false;
      }
      continue;
    }
    switch (c) {
    case '"':
      in_str = true;
      break;
    case '(':
    case '[':
    case '{':
    case '<':
      ++depth;
      break;
    case ')':
    case ']':
    case '}':
    case '>':
      --depth;
      break;
    case ',':
      if (depth == 0) {
        out.push_back(names.substr(start, i - start));
        start = i + 1;
      }
      break;
    default:
      break;
    }
  }
  out.push_back(names.substr(start));
  // 去首尾空格
  for (auto &sv : out) {
    while (!sv.empty() && sv.front() == ' ') {
      sv.remove_prefix(1);
    }
    while (!sv.empty() && sv.back() == ' ') {
      sv.remove_suffix(1);
    }
  }
  return out;
}

template <typename... Args>
void print(const char *file, int line, const char *names, const Args &...args) {
  const char *cyan = use_color() ? "\033[36m" : "";
  const char *dim = use_color() ? "\033[2m" : "";
  const char *reset = use_color() ? "\033[0m" : "";

  // 去掉路径只留文件名
  std::string_view fname{file};
  if (auto p = fname.rfind('/'); p != std::string_view::npos) {
    fname.remove_prefix(p + 1);
  }

  auto parts = split_names(names);
  std::cerr << dim << "[" << fname << ":" << line << "]" << reset << " ";
  size_t i = 0;
  auto emit = [&](const auto &val) {
    // parts 可能因参数内含 < > 位移/比较运算符而切分失准，越界时退化为 ?
    std::string_view name = i < parts.size() ? parts[i] : std::string_view{"?"};
    std::cerr << cyan << name << reset << " = " << val;
    if (i + 1 < sizeof...(Args)) {
      std::cerr << ", ";
    }
    ++i;
  };
  (emit(args), ...);
  std::cerr << std::endl;
}

} // namespace lc_dbg

#define DBG(...) lc_dbg::print(__FILE__, __LINE__, #__VA_ARGS__, __VA_ARGS__)
