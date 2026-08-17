// @leet imports start
// Created: 2026-08-17 18:58:50

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 && root2) {
      root1->val += root2->val;
      root1->left = mergeTrees(root1->left, root2->left);
      root1->right = mergeTrees(root1->right, root2->right);
    }
    return root1 ? root1 : root2;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.mergeTrees("[1,3,2,5]"_tree, "[2,1,3,null,4,null,7]"_tree),
        "[3,4,5,5,4,null,7]"_tree);
  CHECK(s.mergeTrees("[1]"_tree, "[1,2]"_tree), "[2,2]"_tree);
  return 0;
}
