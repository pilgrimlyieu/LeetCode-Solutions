// @leet imports start
// Created: 2026-08-16 17:54:08

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
  bool isBalanced(TreeNode *root) {
    bool isBal = true;
    auto getHeight = [&](auto &&self, TreeNode *node) {
      if (!node) {
        return 0;
      }
      int hl = self(self, node->left);
      int hr = self(self, node->right);
      if (abs(hl - hr) > 1) {
        isBal = false;
      }
      return 1 + max(hl, hr);
    };
    getHeight(getHeight, root);
    return isBal;
  }
};
// @leet end

// @card hint
// **平衡二叉树**指该树所有节点的左右子树的高度相差不超过 1。

int main() {
  Solution s;
  CHECK(s.isBalanced("[3,9,20,null,null,15,7]"_tree), true);
  CHECK(s.isBalanced("[1,2,2,3,3,null,null,4,4]"_tree), false);
  CHECK(s.isBalanced("[]"_tree), true);
  CHECK(s.isBalanced("[1,2,3,4,5,6,null,8]"_tree), true);
  return 0;
}
