// @leet imports start
// Created: 2026-08-18 14:51:20

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
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (!root) {
      return root;
    }
    if (root->val < low) {
      return trimBST(root->right, low, high);
    } else if (root->val > high) {
      return trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
};
// @leet end

// @card idea 递归

// @alt 迭代
// 先确定新根位置，然后迭代修建子树。若当前节点已在范围内，以左子树修建为例：
// 1. 若当前节点左子不在目标范围内，则将左子的右子树作为新左子继续修建；
// 2. 若当前节点左子在目标范围内，则将左子作为新的当前节点。
class SolutionIte {
public:
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    while (root && (root->val < low || root->val > high)) {
      if (root->val < low) {
        root = root->right;
      } else {
        root = root->left;
      }
    }
    if (!root) {
      return nullptr;
    }
    auto node = root;
    while (node->left) {
      if (node->left->val < low) {
        node->left = node->left->right;
      } else {
        node = node->left;
      }
    }
    node = root;
    while (node->right) {
      if (node->right->val > high) {
        node->right = node->right->left;
      } else {
        node = node->right;
      }
    }
    return root;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.trimBST("[1,0,2]"_tree, 1, 2), "[1,null,2]"_tree);
  CHECK(s.trimBST("[3,0,4,null,2,null,null,1]"_tree, 1, 3),
        "[3,2,null,1]"_tree);
  return 0;
}
