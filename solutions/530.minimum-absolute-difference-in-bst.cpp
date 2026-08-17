// @leet imports start
// Created: 2026-08-17 20:34:14

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
  int getMinimumDifference(TreeNode *root) {
    vector<TreeNode *> stk;
    int minAbs = INT_MAX;
    TreeNode *last = nullptr;
    while (!stk.empty() || root) {
      while (root) {
        stk.push_back(root);
        root = root->left;
      }
      root = stk.back();
      stk.pop_back();
      if (last) {
        int delta = abs(last->val - root->val);
        if (delta < minAbs) {
          minAbs = delta;
        }
      }
      last = root;
      root = root->right;
    }
    return minAbs != INT_MAX ? minAbs : 0;
  }
};
// @leet end

// @card note
// 主要就是中序遍历迭代，使用栈模拟递归的调用栈，先逐步展开左子树，直到最左节点，然后回溯到父节点，再展开右子树。

int main() {
  Solution s;
  CHECK(s.getMinimumDifference("[]"_tree), 0);
  CHECK(s.getMinimumDifference("[1]"_tree), 0);
  CHECK(s.getMinimumDifference("[1,null,2]"_tree), 1);
  CHECK(s.getMinimumDifference("[4,2,6,1,3]"_tree), 1);
  CHECK(s.getMinimumDifference("[1,0,48,null,null,12,49]"_tree), 1);
  CHECK(s.getMinimumDifference("[236,104,701,null,227,null,911]"_tree), 9);
  return 0;
}
