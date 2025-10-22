// 2025-10-22 11:13:40

#include <bits/stdc++.h>
#include "../../../utils.h"

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
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
    vector<int> res;

    void preorder(TreeNode *node) {
        if (node) {
            res.emplace_back(node->val);
            preorder(node->left);
            preorder(node->right);
        }
    }

    public:
    vector<int> preorderTraversal(TreeNode *root) {
        preorder(root);
        return res;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(void) {
    Solution s;
    cout << BINTREE(1, nullptr, 2, 3)->visualize() << endl;
    cout << BINTREE(1, 2, 3, 4, 5, nullptr, 8, nullptr, nullptr, 6, 7, 9)->visualize() << endl;
    return 0;
}
