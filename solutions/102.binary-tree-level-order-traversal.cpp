// @leet imports start
// Created: 2026-08-15 17:25:24

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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root) {
      return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      ans.emplace_back();
      int size = q.size();
      while (size--) {
        TreeNode *node = q.front();
        q.pop();
        ans.back().emplace_back(node->val); // 使用 back 而非记录层数
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
    }
    return ans;
  }
};
// @leet end

// @card hint
// 同时考虑迭代和递归的写法。

// @card idea 迭代 BFS
// 因为要层数信息，不能简单的 BFS。不过可以从 BFS 扩展，一次可以弹出一整层元素。

// @alt 递归 DFS
// 这里主要展示了 lambda 函数的递归写法，需要传入 `auto &&self`。
class SolutionDFS {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    auto lvlOrd = [&](auto &&self, vector<vector<int>> &vec, TreeNode *node,
                      int level) {
      if (!node) {
        return;
      }
      if (vec.size() <= level) {
        vec.emplace_back();
      }
      vec[level].emplace_back(node->val);
      self(self, vec, node->left, level + 1);
      self(self, vec, node->right, level + 1);
    };
    lvlOrd(lvlOrd, ans, root, 0);
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  SolutionDFS s2;
  // CHECK(s.method("[1,2,3]"_vi), "[1,2]"_vi);
  CHECK(s.levelOrder("[3,9,20,null,null,15,7]"_tree),
        "[[3],[9,20],[15,7]]"_vvi);
  CHECK(s.levelOrder("[1]"_tree), "[[1]]"_vvi);
  CHECK(s.levelOrder("[]"_tree), "[]"_vvi);
  CHECK(s.levelOrder("[1,2,3,4,5]"_tree), "[[1],[2,3],[4,5]]"_vvi);
  CHECK(s.levelOrder("[1,2,null,3,null,4,null,5]"_tree),
        "[[1],[2],[3],[4],[5]]"_vvi);
  CHECK(s2.levelOrder("[3,9,20,null,null,15,7]"_tree),
        "[[3],[9,20],[15,7]]"_vvi);
  CHECK(s2.levelOrder("[1,2,null,3,null,4,null,5]"_tree),
        "[[1],[2],[3],[4],[5]]"_vvi);
  return 0;
}
