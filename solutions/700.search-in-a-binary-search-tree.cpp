// @leet imports start
// Created: 2026-08-17 19:53:02

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
  TreeNode *searchBST(TreeNode *root, int val) {
    while (root) {
      if (root->val > val) {
        root = root->left;
      } else if (root->val < val) {
        root = root->right;
      } else {
        break;
      }
    }
    return root;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.searchBST("[4,2,7,1,3]"_tree, 2), "[2,1,3]"_tree);
  CHECK(s.searchBST("[4,2,7,1,3]"_tree, 5), "[]"_tree);
  return 0;
}
