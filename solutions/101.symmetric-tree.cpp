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

int main() {
  Solution s;
  // CHECK(s.method("[1,2,3]"_vi), "[1,2]"_vi);
  CHECK(s.isSymmetric("[1,2,2,3,4,4,3]"_tree), true);
  CHECK(s.isSymmetric("[1,2,2,null,3,null,3]"_tree), false);
  return 0;
}
