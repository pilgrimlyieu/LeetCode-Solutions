// @leet imports start
// Created: 2026-08-17 21:09:14

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
  vector<int> findMode(TreeNode *root) {
    vector<int> ans;
    int maxCount = 0;
    int count = 0;
    TreeNode *last = nullptr;
    // @fold
    auto visit = [&](TreeNode *node) {
      if (last && node->val == last->val) {
        count++;
      } else {
        count = 1;
      }
      last = node;
      if (count > maxCount) {
        maxCount = count;
        ans = {node->val};
      } else if (count == maxCount) {
        ans.push_back(node->val);
      }
    };
    // @fold end
    auto inorder = [&](auto &&self, TreeNode *node) {
      if (!node) {
        return;
      }
      self(self, node->left);
      visit(node);
      self(self, node->right);
    };
    inorder(inorder, root);
    return ans;
  }
};
// @leet end

// @alt Morris 中序遍历
// 中序遍历顺序是左根右，问题在于遍历完左子树后如何回到根节点。递归/栈通过调用栈或显式栈保存根节点。
//
// Morris 中序遍历在进入当前节点左子树之前，找到中序下的前驱节点，并将其 `right` 指针临时设置为当前节点作为「线索」。当左子树遍历完成后会回到当前节点，再将线索断开。
//
// 当前节点中序下的前驱节点是左子树（若有）的最右边的节点，且其 `right` 一定为空。这样就实现了 $O(1)$ 空间复杂度的中序遍历。
class SolutionMorris {
public:
  vector<int> getMinimumDifference(TreeNode *root) {
    vector<int> ans;
    int maxCount = 0;
    int count = 0;
    TreeNode *last = nullptr;
    // @fold
    auto visit = [&](TreeNode *node) {
      if (last && node->val == last->val) {
        count++;
      } else {
        count = 1;
      }
      last = node;
      if (count > maxCount) {
        maxCount = count;
        ans = {node->val};
      } else if (count == maxCount) {
        ans.push_back(node->val);
      }
    };
    // @fold end
    while (root) {
      if (!root->left) {
        visit(root);
        root = root->right;
      } else {
        auto prev = root->left;
        // 找左子树最右节点；如果右指针已经连回 root，说明线索已建立
        while (prev->right && prev->right != root) {
          prev = prev->right;
        }
        if (!prev->right) {
          prev->right = root;
          root = root->left;
        } else {
          prev->right = nullptr;
          visit(root);
          root = root->right;
        }
      }
    }
    return ans;
  }
};
// @alt end

// @card idea 中序遍历递归

// @card note
// 题目本身不难，因为二叉搜索树的中序遍历就是有序的。主要是考虑 $O(1)$ 空间复杂度的中序遍历（Morris 中序遍历）。
//
// 两种解法的 `visit` 定义如下：
//
// ```cpp
// auto visit = [&](TreeNode *node) {
//   if (last && node->val == last->val) {
//     count++;
//   } else {
//     count = 1;
//   }
//   last = node;
//   if (count > maxCount) {
//     maxCount = count;
//     ans = {node->val};
//   } else if (count == maxCount) {
//     ans.push_back(node->val);
//   }
// };
// ```

int main() {
  Solution s;
  // 题面允许任意顺序，必要时改用 CHECK_ANYORDER
  CHECK(s.findMode("[1,null,2,2]"_tree), "[2]"_vi);
  CHECK(s.findMode("[0]"_tree), "[0]"_vi);
  return 0;
}
