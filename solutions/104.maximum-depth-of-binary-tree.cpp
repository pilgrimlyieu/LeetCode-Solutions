// @leet imports start
// Created: 2026-08-15 20:20:28

#include "../utils.h"
#include <algorithm>

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
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.maxDepth("[3,9,20,null,null,15,7]"_tree), 3);
  CHECK(s.maxDepth("[1,null,2]"_tree), 2);
  return 0;
}
