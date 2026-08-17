// @leet imports start
// Created: 2026-08-17 19:56:49

#include "../utils.h"
#include <vector>

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
  bool isValidBST(TreeNode *root) {
    auto check = [](auto &&self, TreeNode *node,
                    pair<long, long> bound) -> bool {
      if (!node) {
        return true;
      }
      if (!(bound.first < node->val && node->val < bound.second)) {
        return false;
      }
      return self(self, node->left, {bound.first, node->val}) &&
             self(self, node->right, {node->val, bound.second});
    };
    return check(check, root, {LONG_MIN, LONG_MAX});
  }
};
// @leet end

// @card idea 递归
// 二叉搜索树的一个根节点的左节点的右节点不仅要大于左节点，还需要小于根节点。可以传入一个约束的数据范围。

// @card note
// 注意数据范围，因此开 `long`。

// @alt 中序遍历迭代
// 利用二叉搜索树中序遍历后是单调递增序列进行迭代。
//
// 注意外循环的条件，`root` 非空或栈还有节点。
class SolutionInIter {
public:
  bool isValidBST(TreeNode *root) {
    vector<TreeNode *> stk;
    long val = LONG_MIN;
    while (!stk.empty() || root) {
      while (root) {
        stk.push_back(root);
        root = root->left;
      }
      root = stk.back();
      stk.pop_back();
      if (root->val <= val) {
        return false;
      }
      val = root->val;
      root = root->right;
    }
    return true;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.isValidBST("[2147483647]"_tree), true);
  CHECK(s.isValidBST("[2,1,3]"_tree), true);
  CHECK(s.isValidBST("[2,2,2]"_tree), false);
  CHECK(s.isValidBST("[5,1,4,null,null,3,6]"_tree), false);
  CHECK(s.isValidBST("[5,4,6,null,null,3,7]"_tree), false);
  CHECK(s.isValidBST("[45,42,null,null,44,43,null,41]"_tree), false);
  return 0;
}
