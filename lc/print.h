#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

#include "nodes.h"

/** 泛型打印 */

namespace lc_print {

// 可迭代检测（排除 string/const char*，它们按标量走）
template <typename T, typename = void> struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T,
                   std::void_t<decltype(std::begin(std::declval<const T &>())),
                               decltype(std::end(std::declval<const T &>()))>>
    : std::true_type {};

template <typename T>
constexpr bool is_container_v =
    is_iterable<T>::value && !std::is_convertible_v<T, std::string_view>;

inline std::string format_double(double d) {
  char buf[32];
  std::snprintf(buf, sizeof(buf), "%.5f", d);
  return buf;
}

} // namespace lc_print

// 前置声明，容器元素可以是任何已支持类型（含嵌套容器/pair/节点指针）
template <typename T, typename = std::enable_if_t<lc_print::is_container_v<T>>>
std::ostream &operator<<(std::ostream &os, const T &container);

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::optional<T> &opt) {
  return opt.has_value() ? (os << opt.value()) : (os << "null");
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template <typename... Ts>
std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
  os << "(";
  std::apply(
      [&os](const Ts &...args) {
        size_t i = 0;
        ((os << args << (++i < sizeof...(Ts) ? ", " : "")), ...);
      },
      t);
  return os << ")";
}

inline std::ostream &operator<<(std::ostream &os, const ListNode *node) {
  os << "[";
  for (const ListNode *cur = node; cur; cur = cur->next) {
    os << cur->val << (cur->next ? " -> " : "");
  }
  return os << "]";
}

namespace lc_print {

inline void visualize_tree_helper(std::ostream &os, const TreeNode *node,
                                  const std::string &prefix, bool isLeftChild) {
  if (!node) {
    return;
  }
  visualize_tree_helper(os, node->right,
                        prefix + (isLeftChild ? "│   " : "    "), false);
  os << prefix << (isLeftChild ? "└── " : "┌── ") << node->val << "\n";
  visualize_tree_helper(os, node->left,
                        prefix + (isLeftChild ? "    " : "│   "), true);
}

inline std::ostream &visualize_tree(std::ostream &os, const TreeNode *root) {
#if defined(_WIN32) || defined(_WIN64)
  system("chcp 65001 > nul");
#endif
  visualize_tree_helper(os, root->right, "   ", false);
  os << "── " << root->val << "\n";
  visualize_tree_helper(os, root->left, "   ", true);
  return os;
}

} // namespace lc_print

inline std::ostream &operator<<(std::ostream &os, const TreeNode *node) {
  if (!node) {
    return os << "(empty tree)";
  }
  if (node->visualized()) {
    return lc_print::visualize_tree(os, node);
  }
  return os << static_cast<std::vector<std::optional<int>>>(*node);
}

// 通用容器打印：vector/deque/set/map/unordered_*
template <typename T, typename>
std::ostream &operator<<(std::ostream &os, const T &container) {
  os << "[";
  bool first = true;
  for (const auto &elem : container) {
    if (!first) {
      os << ", ";
    }
    first = false;
    using E = std::decay_t<decltype(elem)>;
    if constexpr (std::is_floating_point_v<E>) {
      os << lc_print::format_double(elem);
    } else {
      os << elem;
    }
  }
  return os << "]";
}

// string --> vector<char>
inline std::vector<char> S2V(const std::string &s) {
  return {s.begin(), s.end()};
}
inline std::string V2S(const std::vector<char> &v) {
  return {v.begin(), v.end()};
}
