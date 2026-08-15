// @leet imports start
// Created: 2026-08-15 19:00:46

#include "../utils.h"
#include <bits/stdc++.h>
#include <queue>
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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      long long sum = 0;
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        sum += node->val;
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      ans.push_back((double)sum / size);
    }
    return ans;
  }
};
// @leet end

int main() {
  Solution s;
  // CHECK(s.method("[1,2,3]"_vi), "[1,2]"_vi);

  return 0;
}
