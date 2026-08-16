// @leet imports start
// Created: 2026-08-16 19:00:37

#include "../utils.h"
#include <string>
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
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans{};
    // 注意 void
    auto dfs = [&](auto &&self, TreeNode *node, string path) -> void {
      if (!node) {
        return;
      }
      path += to_string(node->val);
      if (!node->left && !node->right) {
        ans.push_back(path);
      }
      path += "->";
      self(self, node->left, path);
      self(self, node->right, path);
    };
    dfs(dfs, root, "");
    return ans;
  }
};
// @leet end

// @card idea
// 将拼接的中间路径作为参数传递

int main() {
  Solution s;
  // 题面允许任意顺序，必要时改用 CHECK_ANYORDER
  CHECK_ANYORDER(s.binaryTreePaths("[1,2,3,null,5]"_tree),
                 R"(["1->2->5","1->3"])"_vs);
  CHECK_ANYORDER(s.binaryTreePaths("[1]"_tree), R"(["1"])"_vs);
  CHECK_ANYORDER(s.binaryTreePaths("[1,2,3,5,6]"_tree),
                 R"(["1->2->5","1->2->6","1->3"])"_vs);
  return 0;
}
