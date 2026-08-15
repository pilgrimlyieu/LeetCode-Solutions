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
