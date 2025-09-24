// 2025-09-24 20:12:22

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

string printListNode(ListNode *node) {
    string res = "[";
    while (node) {
        res += to_string(node->val) + ",";
        node = node->next;
    }
    if (res.size() > 1) {
        res.pop_back();
    }
    res += "]";
    return res;
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode();
        ListNode *current = result;
        int next = 0;
        while (l1 && l2) {
            int plus = next + l1->val + l2->val;
            next = plus / 10;
            if (next || l1->next || l2->next) {
                result->next = new ListNode();
            }
            result->val += plus % 10;
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
            // cout << "[DEBUG1] " << printListNode(current) << endl;
        }
        while (l1) {
            int plus = next + l1->val;
            next = plus / 10;
            if (next || l1->next) {
                result->next = new ListNode();
            }
            result->val += plus % 10;
            result = result->next;
            l1 = l1->next;
            // cout << "[DEBUG2] " << printListNode(current) << endl;
        }
        while (l2) {
            int plus = next + l2->val;
            next = plus / 10;
            if (next || l2->next) {
                result->next = new ListNode();
            }
            result->val += plus % 10;
            result = result->next;
            l2 = l2->next;
            // cout << "[DEBUG3] " << printListNode(current) << endl;
        }
        if (next) {
            result->val = next;
        }
        return current;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << printListNode(s.addTwoNumbers(createListNode({9, 9, 9, 9}), createListNode({9}))) << endl; // [8,0,0,0,1]
    cout << printListNode(s.addTwoNumbers(createListNode({9, 9, 1}), createListNode({1}))) << endl; // [0,0,2]
    return 0;
}
