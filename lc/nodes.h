#pragma once

#include <optional>
#include <stdexcept>
#include <vector>

/**
 * ListNode / TreeNode：定义与构造
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {
  }
  // NOLINTNEXTLINE(google-explicit-constructor)
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode *next) : val(x), next(next) {
  }

  ListNode *operator[](std::size_t n) {
    ListNode *p = this;
    while (p != nullptr && n > 0) {
      p = p->next;
      --n;
    }
    if (p == nullptr) {
      throw std::out_of_range("ListNode index out of range");
    }
    return p;
  }

  const ListNode *operator[](std::size_t n) const {
    const ListNode *p = this;
    while (p != nullptr && n > 0) {
      p = p->next;
      --n;
    }
    if (p == nullptr) {
      throw std::out_of_range("ListNode index out of range");
    }
    return p;
  }
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  // NOLINTNEXTLINE(google-explicit-constructor)
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {
  }

  explicit operator std::vector<std::optional<int>>() const {
    std::vector<std::optional<int>> result;
    std::vector<const TreeNode *> queue;
    queue.emplace_back(this);
    size_t index = 0;
    while (index < queue.size()) {
      const TreeNode *current = queue[index++];
      if (current) {
        result.emplace_back(current->val);
        queue.emplace_back(current->left);
        queue.emplace_back(current->right);
      } else {
        result.emplace_back(std::nullopt);
      }
    }
    while (!result.empty() && !result.back().has_value()) {
      result.pop_back();
    }
    return result;
  }

  // 链式开关：cout << tree->visualize() 打印 ASCII 树形图而非 BFS 序列
  TreeNode *visualize() {
    _visualized = true;
    return this;
  }
  TreeNode *devisualize() {
    _visualized = false;
    return this;
  }
  [[nodiscard]] bool visualized() const {
    return _visualized;
  }

private:
  bool _visualized = false;
};
