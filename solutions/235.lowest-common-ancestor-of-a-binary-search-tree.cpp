// @leet imports start
// Created: 2026-08-18 12:27:54

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    int minBound = min(p->val, q->val);
    int maxBound = max(p->val, q->val);
    while (root) {
      if (root->val > maxBound) {
        root = root->left;
      } else if (root->val < minBound) {
        root = root->right;
      } else {
        return root;
      }
    }
    return nullptr;
  }
};
// @leet end

int main() {
  Solution s;
  // 注: 题面解析到 2 个输出但有 3 个样例，期望值请手动核对
  // CHECK(s.lowestCommonAncestor("[6,2,8,0,4,7,9,null,null,3,5]"_tree, 2, 8), /* TODO */);
  // CHECK(s.lowestCommonAncestor("[6,2,8,0,4,7,9,null,null,3,5]"_tree, 2, 4), /* TODO */);
  // CHECK(s.lowestCommonAncestor("[2,1]"_tree, 2, 1), /* TODO */);
  return 0;
}
