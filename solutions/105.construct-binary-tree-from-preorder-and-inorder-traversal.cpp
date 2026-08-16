// @leet imports start
// Created: 2026-08-16 21:36:54

#include "../utils.h"
#include <unordered_map>
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int size = preorder.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++) {
      mp[inorder[i]] = i;
    }
    int prei = 0;
    auto build = [&](auto &&self, pair<int, int> ip) -> TreeNode * {
      if (ip.first == ip.second) {
        return nullptr;
      }
      int val = preorder[prei++];
      auto root = new TreeNode(val);
      int index = mp[val];
      root->left = self(self, {ip.first, index});
      root->right = self(self, {index + 1, ip.second});
      return root;
    };
    return build(build, {0, size});
  }
};
// @leet end

// @alt 迭代
// 对于前序遍历相邻两个节点，后者要么是前者的左子，要么是前者某个祖先（包括本身）的右子。
//
// 栈保存当前正在构造、但右子树还没处理的节点路径。可视为从根节点到最左节点的链。想象从根节点出发一直构建左子树到底，然后开始返回逐步构建右子树。
//
// 迭代做法可以将栈视为递归做法的调用栈，前序读入一个新节点代表递归进入该节点。若还不是中序的下一个节点，则还要继续递归左子树，否则说明左子树递归结束，不断弹出栈返回，进入右子树。
class SolutionIter {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int size = preorder.size();
    vector<TreeNode *> stk;
    stk.reserve(size);
    auto root = new TreeNode(preorder[0]);
    stk.push_back(root);
    int idx = 0;
    for (int i = 1; i < size; i++) {
      auto node = new TreeNode(preorder[i]);
      if (stk.back()->val != inorder[idx]) {
        stk.back()->left = node;
      } else {
        TreeNode *last;
        while (!stk.empty() && stk.back()->val == inorder[idx]) {
          last = stk.back();
          stk.pop_back();
          idx++;
        }
        last->right = node;
      }
      stk.push_back(node);
    }
    return root;
  }
};
// @alt end

int main() {
  Solution s;
  SolutionIter s2;
  CHECK(s.buildTree("[3,9,20,15,7]"_vi, "[9,3,15,20,7]"_vi),
        "[3,9,20,null,null,15,7]"_tree);
  CHECK(s.buildTree("[-1]"_vi, "[-1]"_vi), "[-1]"_tree);
  CHECK(s2.buildTree("[3,9,20,15,7]"_vi, "[9,3,15,20,7]"_vi),
        "[3,9,20,null,null,15,7]"_tree);
  CHECK(s2.buildTree("[-1]"_vi, "[-1]"_vi), "[-1]"_tree);
  return 0;
}
