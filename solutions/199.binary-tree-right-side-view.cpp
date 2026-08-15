// @leet imports start
// Created: 2026-08-15 19:09:04

#include "../utils.h"
#include <bits/stdc++.h>
#include <pthread.h>
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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    if (!root) {
      return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int idx = q.size();
      while (idx--) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
        if (idx == 0) {
          ans.push_back(node->val);
        }
      }
    }
    return ans;
  }
};
// @leet end

void dfs(vector<int> &ans, TreeNode *node, int depth) {
  if (!node) {
    return;
  }
  if (depth == ans.size()) {
    ans.push_back(node->val);
  }

  dfs(ans, node->right, depth + 1);
  dfs(ans, node->left, depth + 1);
}

vector<int> rightSideView(TreeNode *root) {
  vector<int> ans;
  dfs(ans, root, 0);
  return ans;
}

int main() {
  Solution s;
  // CHECK(s.method("[1,2,3]"_vi), "[1,2]"_vi);

  return 0;
}
