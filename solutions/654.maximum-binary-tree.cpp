// @leet imports start
// Created: 2026-08-16 21:18:53

#include "../utils.h"
#include <algorithm>
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    vector<TreeNode *> stk;
    stk.reserve(nums.size());
    for (auto n : nums) {
      auto node = new TreeNode(n);
      TreeNode *last = nullptr;
      while (!stk.empty() && stk.back()->val < n) {
        last = stk.back();
        stk.pop_back();
      }
      node->left = last;
      if (!stk.empty()) {
        stk.back()->right = node;
      }
      stk.emplace_back(node);
    }
    return stk.front();
  }
};
// @leet end

// @card idea 单调栈
// 构建一个单调递减栈，代表处理过的所有节点：
// 1. 遍历数组，弹出栈上比当前节点小的所有节点；
// 2. 最后一个弹出的节点是比当前节点小的最大节点，作为当前节点的左子树；
// 3. 栈顶节点（若有）是当前节点左边第一个值比它大的节点，因此当前节点作为栈顶节点的右子树。
// 4. 最后栈底就是根节点。

int main() {
  Solution s;
  CHECK(s.constructMaximumBinaryTree("[3,2,1,6,0,5]"_vi),
        "[6,3,5,null,2,0,null,null,1]"_tree);
  CHECK(s.constructMaximumBinaryTree("[3,2,1]"_vi), "[3,null,2,null,1]"_tree);
  return 0;
}
