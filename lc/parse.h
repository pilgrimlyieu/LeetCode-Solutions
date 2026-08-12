#pragma once

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "nodes.h"

/**
 * LeetCode 字面量解析
 * "[1,3,-1]"_vi           → vector<int>
 * "[[1,2],[3]]"_vvi       → vector<vector<int>>
 * R"(["ab","c"])"_vs      → vector<string>
 * "[1.5,2.0]"_vd          → vector<double>
 * "[true,false]"_vb       → vector<bool>
 * "[1,null,2,3]"_tree     → TreeNode*（BFS 序，null 为空位）
 * "[1,2,3]"_list          → ListNode*（空 "[]" 返回 nullptr）
 * "abc"_vc                → vector<char>
 */

namespace lc_parse {

// 递归下降解析器
struct Parser {
  std::string_view s;
  size_t pos = 0;

  void skip_ws() {
    while (pos < s.size() && std::isspace(static_cast<unsigned char>(s[pos]))) {
      ++pos;
    }
  }

  [[noreturn]] void fail(const std::string &what) const {
    std::cerr << "parse error at offset " << pos << ": " << what
              << "\n  input: " << s << "\n";
    std::exit(2);
  }

  void expect(char c) {
    skip_ws();
    if (pos >= s.size() || s[pos] != c) {
      fail(std::string("expected '") + c + "'");
    }
    ++pos;
  }

  bool try_consume(char c) {
    skip_ws();
    if (pos < s.size() && s[pos] == c) {
      ++pos;
      return true;
    }
    return false;
  }

  bool try_consume_null() {
    skip_ws();
    if (s.substr(pos, 4) == "null") {
      pos += 4;
      return true;
    }
    return false;
  }

  template <typename T> T parse() {
    skip_ws();
    if constexpr (std::is_same_v<T, int> || std::is_same_v<T, long long>) {
      size_t start = pos;
      if (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) {
        ++pos;
      }
      while (pos < s.size() &&
             std::isdigit(static_cast<unsigned char>(s[pos]))) {
        ++pos;
      }
      if (pos == start) {
        fail("expected integer");
      }
      return static_cast<T>(
          std::stoll(std::string(s.substr(start, pos - start))));
    } else if constexpr (std::is_same_v<T, double>) {
      size_t start = pos;
      while (pos < s.size() &&
             (std::isdigit(static_cast<unsigned char>(s[pos])) ||
              s[pos] == '-' || s[pos] == '+' || s[pos] == '.' ||
              s[pos] == 'e' || s[pos] == 'E')) {
        ++pos;
      }
      if (pos == start) {
        fail("expected number");
      }
      return std::stod(std::string(s.substr(start, pos - start)));
    } else if constexpr (std::is_same_v<T, bool>) {
      if (s.substr(pos, 4) == "true") {
        pos += 4;
        return true;
      }
      if (s.substr(pos, 5) == "false") {
        pos += 5;
        return false;
      }
      fail("expected bool");
    } else if constexpr (std::is_same_v<T, char>) {
      expect('"');
      if (pos >= s.size()) {
        fail("expected char");
      }
      char c = s[pos++];
      expect('"');
      return c;
    } else if constexpr (std::is_same_v<T, std::string>) {
      expect('"');
      std::string out;
      while (pos < s.size() && s[pos] != '"') {
        if (s[pos] == '\\' && pos + 1 < s.size()) {
          ++pos; // 简单转义：取转义符后原字符
        }
        out += s[pos++];
      }
      expect('"');
      return out;
    } else {
      static_assert(!sizeof(T), "unsupported scalar type");
    }
  }

  template <typename T> std::vector<T> parse_vector() {
    std::vector<T> out;
    expect('[');
    if (try_consume(']')) {
      return out;
    }
    while (true) {
      out.push_back(parse<T>());
      if (try_consume(']')) {
        return out;
      }
      expect(',');
    }
  }

  template <typename T> std::vector<std::vector<T>> parse_matrix() {
    std::vector<std::vector<T>> out;
    expect('[');
    if (try_consume(']')) {
      return out;
    }
    while (true) {
      out.push_back(parse_vector<T>());
      if (try_consume(']')) {
        return out;
      }
      expect(',');
    }
  }

  // "[1,null,2]" → BFS 可空序列（树构造原料）
  std::vector<std::optional<int>> parse_opt_ints() {
    std::vector<std::optional<int>> out;
    expect('[');
    if (try_consume(']')) {
      return out;
    }
    while (true) {
      if (try_consume_null()) {
        out.emplace_back(std::nullopt);
      } else {
        out.emplace_back(parse<int>());
      }
      if (try_consume(']')) {
        return out;
      }
      expect(',');
    }
  }
};

inline TreeNode *build_tree(const std::vector<std::optional<int>> &bfs) {
  if (bfs.empty() || !bfs[0].has_value()) {
    return nullptr;
  }
  auto *root = new TreeNode(*bfs[0]);
  std::vector<TreeNode *> queue{root};
  size_t qi = 0;
  size_t i = 1;
  // qi 越界说明 null 节点被赋了孩子（LC 不会生成这种序列，防手打笔误）
  while (i < bfs.size() && qi < queue.size()) {
    TreeNode *parent = queue[qi++];
    if (i < bfs.size()) {
      if (bfs[i].has_value()) {
        parent->left = new TreeNode(*bfs[i]);
        queue.push_back(parent->left);
      }
      ++i;
    }
    if (i < bfs.size()) {
      if (bfs[i].has_value()) {
        parent->right = new TreeNode(*bfs[i]);
        queue.push_back(parent->right);
      }
      ++i;
    }
  }
  return root;
}

inline ListNode *build_list(const std::vector<int> &v) {
  ListNode dummy;
  ListNode *cur = &dummy;
  for (int x : v) {
    cur->next = new ListNode(x);
    cur = cur->next;
  }
  return dummy.next; // 空输入自然返回 nullptr
}

// UDL 返回的 vector 包装：可隐式转 vector<T>&，从而能直接传给
// LeetCode 常见的非常量引用参数（纯右值 vector 做不到，旧 VEC/LValueVec
// 同理）。 注意：以临时形态传入时函数内的修改会随表达式结束丢弃，勿依赖。
template <typename T> struct Lit {
  std::vector<T> data;
  // NOLINTNEXTLINE(google-explicit-constructor)
  operator std::vector<T> &() {
    return data;
  }
  // NOLINTNEXTLINE(google-explicit-constructor)
  explicit operator const std::vector<T> &() const {
    return data;
  }
  auto begin() {
    return data.begin();
  }
  auto end() {
    return data.end();
  }
  [[nodiscard]] auto begin() const {
    return data.begin();
  }
  [[nodiscard]] auto end() const {
    return data.end();
  }
  [[nodiscard]] size_t size() const {
    return data.size();
  }
  decltype(auto) operator[](size_t i) {
    return data[i];
  }
};

} // namespace lc_parse

inline lc_parse::Lit<int> operator""_vi(const char *s, size_t n) {
  return {lc_parse::Parser{{s, n}}.parse_vector<int>()};
}
inline lc_parse::Lit<std::vector<int>> operator""_vvi(const char *s, size_t n) {
  return {lc_parse::Parser{{s, n}}.parse_matrix<int>()};
}
inline lc_parse::Lit<std::string> operator""_vs(const char *s, size_t n) {
  return {lc_parse::Parser{{s, n}}.parse_vector<std::string>()};
}
inline lc_parse::Lit<std::vector<std::string>> operator""_vvs(const char *s,
                                                              size_t n) {
  return {lc_parse::Parser{{s, n}}.parse_matrix<std::string>()};
}
inline lc_parse::Lit<double> operator""_vd(const char *s, size_t n) {
  return {lc_parse::Parser{{s, n}}.parse_vector<double>()};
}
inline lc_parse::Lit<bool> operator""_vb(const char *s, size_t n) {
  return {lc_parse::Parser{{s, n}}.parse_vector<bool>()};
}
// 裸字符串 → vector<char>（"abc"_vc）；R"([["a","b"]])"_vvc → 字符矩阵
inline lc_parse::Lit<char> operator""_vc(const char *s, size_t n) {
  return {{s, s + n}};
}
inline lc_parse::Lit<std::vector<char>> operator""_vvc(const char *s,
                                                       size_t n) {
  return {lc_parse::Parser{{s, n}}.parse_matrix<char>()};
}
inline TreeNode *operator""_tree(const char *s, size_t n) {
  return lc_parse::build_tree(lc_parse::Parser{{s, n}}.parse_opt_ints());
}
inline ListNode *operator""_list(const char *s, size_t n) {
  return lc_parse::build_list(lc_parse::Parser{{s, n}}.parse_vector<int>());
}
