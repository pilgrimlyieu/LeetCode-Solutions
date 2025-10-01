// 2025-10-01 10:29:19

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode(ListNode *node) {
    string res = "[";
    while (node) {
        res += to_string(node->val) + ",";
        node = node->next;
    }
    if (res.size() > 1) {
        res.pop_back();
    }
    res += "]";
    cout << res << endl;
}

ListNode *createListNode(const vector<int> &v) {
    if (v.empty())
        return nullptr;
    ListNode *head = new ListNode(v[0]);
    ListNode *current = head;
    for (int i = 1; i < v.size(); ++i) {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    return head;
}

// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *res = head;
        while (res && res->val == val) {
            res = res->next;
        }
        ListNode *cur = res;
        while (cur && cur->next) {
            ListNode *vali = cur->next;
            if (cur->next->val == val) {
                while (vali && vali->val == val) {
                    vali = vali->next;
                }
                cur->next = vali;
            }
            cur = vali;
        }
        return res;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    printListNode(s.removeElements(createListNode({1, 2, 6, 3, 4, 5, 6}), 6));
    printListNode(s.removeElements(createListNode({}), 1));
    printListNode(s.removeElements(createListNode({7, 7, 7, 7}), 7));
    printListNode(s.removeElements(createListNode({7, 7, 7, 7, 1}), 7));
    printListNode(s.removeElements(createListNode({7, 7, 7, 7, 1, 1}), 7));
    printListNode(s.removeElements(createListNode({2, 2, 7, 7, 7, 7, 1, 1}), 7));
    return 0;
}
