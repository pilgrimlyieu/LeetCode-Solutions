// @leet imports start
// Created: 2026-08-17 22:55:46

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root == p || root == q) {
      return root;
    }
    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);
    if (left && right) {
      return root;
    }
    return left ? left : right;
  }
};
// @leet end

// @card idea
// 若 `root` 是 `p` 或 `q` 的最近公共祖先，有两种可能情况：
// 1. 二者在不同子树：`p` 在 `root` 的左子树，`q` 在 `root` 的右子树（或反之）；
// 2. 二者在相同子树：`root` 就是 `p`，`q` 在 `root` 的子树（或反之）。
//
// 该写法会报告节点 `p` 或 `q` 的祖先节点，若子树中没有 `p` 或 `q`，则返回空。对于更远的公共祖先，因为返回值不会为空（且不可能同时非空），因此会将最近公共祖先向上传递，直到返回。

// @card note
// 也可以自己追踪子树中 `p`, `q` 的存在情况，更易懂一点。只是需要注意依靠调用栈更新了最近祖先后，要避免后面覆盖了结果。

int main() {
  Solution s;
  // CHECK(s.lowestCommonAncestor("[3,5,1,6,2,0,8,null,null,7,4]"_tree, 5, 1), "3"_tree);
  // CHECK(s.lowestCommonAncestor("[3,5,1,6,2,0,8,null,null,7,4]"_tree, 5, 4), "5"_tree);
  auto t = "[3,5,1,6,2,0,8,null,null,7,4]"_tree;
  CHECK(s.lowestCommonAncestor(t, t->left, t->left->right->right), t->left);
  // CHECK(s.lowestCommonAncestor("[1,2]"_tree, 1, 2), "1"_tree);
  return 0;
}
