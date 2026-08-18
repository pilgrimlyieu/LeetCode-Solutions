// @leet imports start
// Created: 2026-08-18 15:08:46

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
  TreeNode *convertBST(TreeNode *root) {
    auto sumBST = [](this auto &&self, TreeNode *node, int sum) -> int {
      if (!node) {
        return sum;
      }
      node->val += self(node->right, sum);
      return self(node->left, node->val);
    };
    sumBST(root, 0);
    return root;
  }
};
// @leet end

// @card idea 递归

// @alt 迭代
class SolutionIter {
public:
  TreeNode *convertBST(TreeNode *root) {
    vector<TreeNode *> stk;
    auto node = root;
    int sum = 0;
    while (!stk.empty() || node) {
      while (node) {
        stk.push_back(node);
        node = node->right;
      }
      node = stk.back();
      stk.pop_back();
      node->val += sum;
      sum = node->val;
      node = node->left;
    }
    return root;
  }
};
// @alt end

int main() {
  Solution s;
  // 注: 题面解析到 4 个输出但有 2 个样例，期望值请手动核对
  CHECK(s.convertBST("[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]"_tree),
        "[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]"_tree);
  CHECK(s.convertBST("[0,null,1]"_tree), "[1,null,1]"_tree);
  CHECK(s.convertBST("[1,0,2]"_tree), "[3,3,2]"_tree);
  CHECK(s.convertBST("[3,2,4,1]"_tree), "[7,9,4,10]"_tree);
  return 0;
}
