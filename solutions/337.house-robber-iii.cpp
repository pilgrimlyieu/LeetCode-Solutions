// @leet imports start
// Created: 2026-08-29 17:05:26

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
  int rob(TreeNode *root) {
    auto dfs = [&](this auto &&self, TreeNode *node) -> pair<int, int> {
      if (!node) {
        return {0, 0};
      }
      auto p1 = self(node->left), p2 = self(node->right);
      return {max(p1.first + p2.first, p1.second + p2.second + node->val),
              p1.first + p2.first};
    };
    return dfs(root).first;
  }
};
// @leet end

// @card idea 动态规划
// 类似一般的打家劫舍，同时保存 `i-2` 与 `i-1` 的情形，这里分别保存以该节点为根能获得最高金额、以该节点两子节点为根能获得最高金额之和。
//
// 也可以考虑保存选不选的情况，这样最后返回的时候还需要取一次最大值。

int main() {
  Solution s;
  CHECK(s.rob("[3,2,3,null,3,null,1]"_tree), 7);
  CHECK(s.rob("[3,4,5,1,3,null,1]"_tree), 9);
  return 0;
}
