// @leet imports start
// Created: 2026-08-18 12:41:12

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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    auto curr = root;
    auto node = new TreeNode(val);
    while (curr) {
      if (val < curr->val) {
        if (curr->left) {
          curr = curr->left;
        } else {
          curr->left = node;
          break;
        }
      } else {
        if (curr->right) {
          curr = curr->right;
        } else {
          curr->right = node;
          break;
        }
      }
    }
    return root ? root : node;
  }
};
// @leet end

// @card note
// 注意空树情形。

int main() {
  Solution s;
  CHECK(s.insertIntoBST("[4,2,7,1,3]"_tree, 5), "[4,2,7,1,3,5]"_tree);
  CHECK(s.insertIntoBST("[40,20,60,10,30,50,70]"_tree, 25),
        "[40,20,60,10,30,50,70,null,null,25]"_tree);
  CHECK(s.insertIntoBST("[4,2,7,1,3,null,null,null,null,null,null]"_tree, 5),
        "[4,2,7,1,3,5]"_tree);
  return 0;
}
