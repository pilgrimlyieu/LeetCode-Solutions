// @leet imports start
// Created: 2026-08-17 19:07:25

#include "../utils.h"

using namespace std;
// @leet imports end

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// @leet start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    auto build = [&](auto &&self, Node *node, Node *parent) -> void {
      if (!node) {
        return;
      }
      if (parent && parent->left == node) {
        node->next = parent->right;
      } else if (parent && parent->next) {
        node->next = parent->next->left;
      }
      self(self, node->left, node);
      self(self, node->right, node);
    };
    build(build, root, nullptr);
    return root;
  }
};
// @leet end

// @card idea 递归
// 利用上一级的 next，对于每一个 `node` 额外传入其父节点 `parent`。

// @alt 迭代
// 记录每层第一个节点 `first`，同时靠其连接下一层全部节点。
class SolutionIter {
public:
  Node *connect(Node *root) {
    if (!root) {
      return root;
    }
    auto first = root;
    while (first->left) {
      auto curr = first;
      while (curr) {
        curr->left->next = curr->right;
        if (curr->next) {
          curr->right->next = curr->next->left;
        }
        curr = curr->next;
      }
      first = first->left;
    }
    return root;
  }
};
// @alt end

int main() {
  Solution s;
  // CHECK(s.connect("[1,2,3,4,5,6,7]"_tree), "[1,#,2,3,#,4,5,6,7,#]"_tree);
  // CHECK(s.connect("[]"_tree), "[]"_tree);
  return 0;
}
