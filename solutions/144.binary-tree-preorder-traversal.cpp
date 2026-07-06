// @leet imports start
// Created: 2025-10-22 11:13:40

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

  void preorder(TreeNode *node) {
    if (node) {
      res.emplace_back(node->val);
      preorder(node->left);
      preorder(node->right);
    }
  }

public:
  vector<int> preorderTraversal(TreeNode *root) {
    preorder(root);
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << "[1,null,2,3]"_tree->visualize() << endl;
  cout << "[1,2,3,4,5,null,8,null,null,6,7,9]"_tree->visualize() << endl;
  return 0;
}
