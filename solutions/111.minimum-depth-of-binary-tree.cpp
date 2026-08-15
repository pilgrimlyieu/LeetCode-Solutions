// @leet imports start
// Created: 2026-08-15 20:39:09

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
public:
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    if (leftDepth && rightDepth) {
      return 1 + min(leftDepth, rightDepth);
    } else {
      return 1 + max(leftDepth, rightDepth);
    }
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.minDepth("[3,9,20,null,null,15,7]"_tree), 2);
  CHECK(s.minDepth("[2,null,3,null,4,null,5,null,6]"_tree), 5);
  return 0;
}
