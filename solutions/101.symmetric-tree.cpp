// @leet imports start
// Created: 2026-08-15 19:33:47

#include "../utils.h"
#include <bits/stdc++.h>
#include <optional>
#include <queue>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool check(TreeNode *p, TreeNode *q) {
    if (!p || !q) {
      return p == q;
    }
    return p->val == q->val && check(p->left, q->right) &&
           check(p->right, q->left);
  }

  bool isSymmetric(TreeNode *root) {
    return check(root->left, root->right);
  }
};
// @leet end

// @card idea 递归双指针
// 不要局限在递归一个方向，可以在一个递归中同时追踪两个指针，一个向左另一个就向右。

// @alt 迭代（队列成对比较）
// 迭代写法就是使用队列，也是不要局限在一个一个元素考虑，而是考虑一对一对，同时将两侧的元素压入，并同时取出比较。
class SolutionIter {
public:
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      auto v = q.front();
      q.pop();
      if (!u && !v) {
        continue;
      } else if (!u || !v || (u->val != v->val)) {
        return false;
      }
      q.push(u->left);
      q.push(v->right);
      q.push(u->right);
      q.push(v->left);
    }
    return true;
  }
};
// @alt end

int main() {
  Solution s;
  SolutionIter s2;
  // CHECK(s.method("[1,2,3]"_vi), "[1,2]"_vi);
  CHECK(s.isSymmetric("[1,2,2,3,4,4,3]"_tree), true);
  CHECK(s.isSymmetric("[1,2,2,null,3,null,3]"_tree), false);
  CHECK(s2.isSymmetric("[1,2,2,3,4,4,3]"_tree), true);
  CHECK(s2.isSymmetric("[1,2,2,null,3,null,3]"_tree), false);
  return 0;
}
