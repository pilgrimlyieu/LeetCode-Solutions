// @leet imports start
// Created: 2026-08-17 21:25:27

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    auto build = [&](this auto &&self, pair<int, int> lr) -> TreeNode * {
      if (lr.first == lr.second) {
        return nullptr;
      }
      int mid = (lr.first + lr.second) / 2;
      auto node = new TreeNode(nums[mid]);
      node->left = self({lr.first, mid});
      node->right = self({mid + 1, lr.second});
      return node;
    };
    return build({0, nums.size()});
  }
};
// @leet end

// @card note
// 这里用了 C++23 的 this 推导，即 `this auto &&self`，不过若是版本不符合，还是得写 `self(self, ...)`。

int main() {
  Solution s;
  CHECK(s.sortedArrayToBST("[-10,-3,0,5,9]"_vi), "[0,-3,9,-10,null,5]"_tree);
  CHECK(s.sortedArrayToBST("[1,3]"_vi), "[3,1]"_tree);
  return 0;
}
