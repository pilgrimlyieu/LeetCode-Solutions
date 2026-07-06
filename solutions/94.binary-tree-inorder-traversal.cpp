// @leet imports start
// Created: 2025-10-22 13:10:56

#include "../utils.h"

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
  vector<int> res;

  void inorder(TreeNode *node) {
    if (node) {
      inorder(node->left);
      res.emplace_back(node->val);
      inorder(node->right);
    }
  }

public:
  vector<int> inorderTraversal(TreeNode *root) {
    inorder(root);
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
