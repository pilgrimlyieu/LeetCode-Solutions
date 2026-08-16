// @leet imports start
// Created: 2026-08-16 21:05:41

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int size = inorder.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++) {
      mp[inorder[i]] = i;
    }
    int posti = size - 1; // 外部记录后序根位置，并先遍历右子树，可以不用传入
    auto build = [&](auto &&self, pair<int, int> inp) -> TreeNode * {
      if (inp.second == inp.first) {
        return nullptr;
      }
      int val = postorder[posti--];
      auto root = new TreeNode(val);
      int index = mp[val];
      root->right = self(self, {index + 1, inp.second});
      root->left = self(self, {inp.first, index});
      return root;
    };
    return build(build, {0, size});
  }
};
// @leet end

// @card idea
// 根的位置在后序遍历的最后一位，在中序遍历的中间位置。中序遍历根的左边是左子树、右边是右子树，后序遍历中是左子树、右子树、根，因此可以递归构造。

// @card note
// 这种重复查找可以使用哈希表优化，可将平均 $O(n\log n)$、最差 $O(n^2)$ 优化到 $O(n)$。
//
// 此外，后序遍历的根节点在最后，因此可以从后往前遍历，先构建右子树，再构建左子树，这样不用手动记录与追踪后序遍历数组中根节点的位置。

// @alt 迭代
// 对于后序遍历相邻两个节点，前者要么是后者的右子，要么是后者某个祖先（包括本身）的左子。
//
// 类似前序的情况，栈保存当前正在构造、但左子树还没处理的节点路径。可视为从根节点到最右节点的链。想象从根节点出发一直构建右子树到底，然后开始返回逐步构建左子树。
//
// 迭代做法可以将栈视为递归做法的调用栈，前序读入一个新节点代表递归进入该节点。若还不是中序的下一个节点，则还要继续递归右子树，否则说明右子树递归结束，不断弹出栈返回，进入左子树。
//
// 后序遍历因为是「左右根」，因此是先右再左，中序也要倒过来进行索引。还要特别注意要跳过初始已加入栈的根。
class SolutionIter {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> postorder) {
    int size = inorder.size();
    vector<TreeNode *> stk;
    stk.reserve(size);
    auto root = new TreeNode(postorder[size - 1]);
    stk.push_back(root);
    int idx = size - 1;
    for (int i = size - 2; i >= 0; i--) {
      auto node = new TreeNode(postorder[i]);
      if (stk.back()->val != inorder[idx]) {
        stk.back()->right = node;
      } else {
        TreeNode *last;
        while (!stk.empty() && stk.back()->val == inorder[idx]) {
          last = stk.back();
          stk.pop_back();
          idx--;
        }
        last->left = node;
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
  CHECK(s.buildTree("[9,3,15,20,7]"_vi, "[9,15,7,20,3]"_vi),
        "[3,9,20,null,null,15,7]"_tree);
  CHECK(s.buildTree("[-1]"_vi, "[-1]"_vi), "[-1]"_tree);
  CHECK(s2.buildTree("[9,3,15,20,7]"_vi, "[9,15,7,20,3]"_vi),
        "[3,9,20,null,null,15,7]"_tree);
  CHECK(s2.buildTree("[-1]"_vi, "[-1]"_vi), "[-1]"_tree);
  return 0;
}
