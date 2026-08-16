// @leet imports start
// Created: 2026-08-16 19:51:42

#include "../utils.h"
#include <deque>

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
  int findBottomLeftValue(TreeNode *root) {
    deque<TreeNode *> dq;
    dq.push_back(root);
    int val;
    while (!dq.empty()) {
      TreeNode *node = dq.front();
      dq.pop_front();
      if (node->right) {
        dq.push_back(node->right);
      }
      if (node->left) {
        dq.push_back(node->left);
      }
      val = node->val; // 倒着遍历，最左边的便会覆盖前面的值
    }
    return val;
  }
};
// @leet end

// @card idea 队列 BFS
// 倒序遍历（先右后左），同层最左的值就会保留下来。

// @alt DFS
// 记录当前最大高度和对应的值，遍历到更深的节点时更新值。需要注意初值情况。
class SolutionDFS {
public:
  void dfs(TreeNode *node, int height, int &curVal, int &curHeight) {
    if (!node) {
      return;
    }
    if (height > curHeight) {
      curVal = node->val;
      curHeight = height;
    }
    dfs(node->left, height + 1, curVal, curHeight);
    dfs(node->right, height + 1, curVal, curHeight);
  }

  int findBottomLeftValue(TreeNode *root) {
    int val = root->val, height = 0;
    dfs(root, 0, val, height);
    return val;
  }
};
// @alt end

int main() {
  Solution s;
  SolutionDFS s2;
  CHECK(s.findBottomLeftValue("[2,1,3]"_tree), 1);
  CHECK(s.findBottomLeftValue("[1,2,3,4,null,5,6,null,null,7]"_tree), 7);
  CHECK(s.findBottomLeftValue("[1]"_tree), 1);
  CHECK(s2.findBottomLeftValue("[2,1,3]"_tree), 1);
  CHECK(s2.findBottomLeftValue("[1,2,3,4,null,5,6,null,null,7]"_tree), 7);
  CHECK(s2.findBottomLeftValue("[1]"_tree), 1);
  return 0;
}
