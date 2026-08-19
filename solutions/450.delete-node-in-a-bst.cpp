// @leet imports start
// Created: 2026-08-18 12:50:22

#include "../utils.h"
#include <cstdio>

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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root) {
      return nullptr;
    }
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
      return root;
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
      return root;
    }
    if (!root->left) {
      return root->right;
    } else if (!root->right) {
      return root->left;
    }
    TreeNode *succ = root->left;
    // TreeNode *succParent = root;
    while (succ->right) {
      // succParent = succ;
      succ = succ->right;
    }
    succ->right = root->right;
    // if (succParent != root) {
    //   succParent->right = succ->left;
    //   succ->left = root->left;
    // }
    succ->left = deleteNode(root->left, succ->val);
    return succ;
  }
};
// @leet end

// @card idea 递归
// 若找到目标节点，有几种情况：
// 1. 目标节点是叶子节点，直接将其父节点的连接删除即可；
// 2. 目标节点仅有一侧子树，直接将子树接上父节点即可；
// 3. 目标节点有左右子树，需要找到左子树的最右节点或右子树的最左节点，与目标节点交换。

// @alt 迭代
// 可以进行一定的特判以减小代码工作量，避免强行将多种情形塞入一种逻辑致使代码晦涩难懂。例如下面可以对前两种情形特判，然后在 3. 时直接选择左子树即可。
class SolutionIter {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    auto node = root;
    TreeNode *parent = nullptr;
    while (node && node->val != key) {
      if (node->val < key) {
        parent = node;
        node = node->right;
      } else {
        parent = node;
        node = node->left;
      }
    }
    if (!node) {
      return root;
    }
    TreeNode *succ = nullptr;
    TreeNode *succParent = node;
    if (node->left) {
      succ = node->left;
      while (succ->right) {
        succParent = succ;
        succ = succ->right;
      }
      if (succParent != node) {
        succParent->right = succ->left;
      } else {
        succParent->left = succ->left;
      }
    } else if (node->right) { // @fold
      succ = node->right;
      while (succ->left) {
        succParent = succ;
        succ = succ->left;
      }
      if (succParent != node) {
        succParent->left = succ->right;
      } else {
        succParent->right = succ->right;
      }
    } // @fold end
    if (succ) {
      succ->left = node->left;
      succ->right = node->right;
    }
    if (!parent) {
      return succ;
    }
    if (parent->left == node) {
      parent->left = succ;
    } else {
      parent->right = succ;
    }
    return root;
  }
};
// @alt end

// @card note
// 只用记录父节点，要判断目标节点是左子还是右子可以直接用父节点比较，无需额外使用一个布尔变量并更新。
//
// 第三种情形也可以将一侧子树接在另一侧与目标节点中序邻接的节点。不过直接置换可以保证平衡性。

int main() {
  Solution s;
  CHECK(s.deleteNode("[5,3,6,2,4,null,7]"_tree, 3),
        "[5,4,6,2,null,null,7]"_tree);
  CHECK(s.deleteNode("[5,3,6,2,4,null,7]"_tree, 0), "[5,3,6,2,4,null,7]"_tree);
  CHECK(s.deleteNode("[]"_tree, 0), "[]"_tree);
  CHECK(s.deleteNode("[1]"_tree, 1), "[]"_tree);
  CHECK(s.deleteNode("[5,3,6,2,4,null,7]"_tree, 5), "[6,3,7,2,4]"_tree);
  CHECK(s.deleteNode("[1,2,3,4,5,6,7]"_tree, 7), "[1,2,3,4,5,6]"_tree);
  CHECK(s.deleteNode("[4,null,7,6,8,5,null,null,9]"_tree, 7),
        "[4,null,8,6,9,5]"_tree);
  return 0;
}
