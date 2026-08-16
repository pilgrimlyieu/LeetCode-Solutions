// @leet imports start
// Created: 2026-08-16 19:43:29

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
  int sumOfLeftLeaves(TreeNode *root) {
    auto dfs = [](auto &&self, TreeNode *node, bool isLeft) -> int {
      if (!node) {
        return 0;
      }
      if (isLeft && !node->left && !node->right) {
        return node->val;
      }
      return self(self, node->left, true) + self(self, node->right, false);
    };
    return dfs(dfs, root, false); // 根不被视为左叶子
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.sumOfLeftLeaves("[3,9,20,null,null,15,7]"_tree), 24);
  CHECK(s.sumOfLeftLeaves("[1]"_tree), 0);
  return 0;
}
