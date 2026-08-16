// @leet imports start
// Created: 2026-08-16 20:07:49

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
  bool dfs(TreeNode *node, int sum, int targetSum) {
    if (!node) { // 对空 node 判断，可以省去下面判空
      return false;
    }
    if (!node->left && !node->right) {
      return sum + node->val == targetSum;
    }
    return dfs(node->left, sum + node->val, targetSum) ||
           dfs(node->right, sum + node->val, targetSum);
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    return dfs(root, 0, targetSum);
  }
};
// @leet end

// @card note
// 需要注意要求是「叶子」，因此不能迭代到一半剪枝。同时直接递归中判断叶子，并放空节点进入递归，可以避免将根节点误判。
//
// DFS 中似乎都会这样处理空节点，而不是在上层处理。无需担心多一层的调用栈。

int main() {
  Solution s;
  CHECK(s.hasPathSum("[5,4,8,11,null,13,4,7,2,null,null,null,1]"_tree, 22),
        true);
  CHECK(s.hasPathSum("[1,2,3]"_tree, 5), false);
  CHECK(s.hasPathSum("[]"_tree, 0), false);
  CHECK(s.hasPathSum("[1,2]"_tree, 1), false);
  return 0;
}
