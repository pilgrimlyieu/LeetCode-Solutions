// @leet imports start
// Created: 2026-08-15 20:50:01

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
  int countNodes(TreeNode *root) {
    TreeNode *left = root;
    TreeNode *right = root;
    int hl = 0;
    int hr = 0;
    while (left) {
      left = left->left;
      hl++;
    }
    while (right) {
      right = right->right;
      hr++;
    }
    if (hl == hr) {
      return (1 << hl) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
// @leet end

// @card idea
// 完全二叉树根的两个子树一定有一个是完美二叉树而另一个是完全二叉树，而完美二叉树的节点个数可以在 $O(\log n)$ 时间内计算出来，因此递归可以在 $O(\log^2 n)$ 时间内计算出来完全二叉树的节点个数。

// @card note
// 也可以使用二分搜索。注意到二叉树每个节点的二进制表示可以被视为从根到该节点的路径（例如说 5 `101` 就是左、右，排除掉第一位）。
//
// 还有位运算优先级比较低，需要用括号包裹。

int main() {
  Solution s;
  CHECK(s.countNodes("[1,2,3,4,5,6]"_tree), 6);
  CHECK(s.countNodes("[1,2,3,4,5]"_tree), 5);
  CHECK(s.countNodes("[1,2,3,4,5,6,7]"_tree), 7);
  CHECK(s.countNodes("[1,2,3,4,5,6,7,8]"_tree), 8);
  CHECK(s.countNodes("[1,2,3,4,5,6,7,8,9]"_tree), 9);
  CHECK(s.countNodes("[1,2,3,4,5,6,7,8,9,10]"_tree), 10);
  CHECK(s.countNodes("[1,2,3,4,5,6,7,8,9,10,11]"_tree), 11);
  CHECK(s.countNodes("[1,2,3,4,5,6,7,8,9,10,11,12]"_tree), 12);
  CHECK(s.countNodes("[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]"_tree), 15);
  CHECK(s.countNodes("[]"_tree), 0);
  CHECK(s.countNodes("[1]"_tree), 1);
  return 0;
}
