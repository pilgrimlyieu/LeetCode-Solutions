// 2025-10-05 10:15:09

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int length = 0;
        ListNode *current = head;
        while (current) {
            length++;
            current = current->next;
        }
        int pos = length - n;
        if (pos == 0) {
            return head->next;
        }
        else {
            ListNode *father = head;
            for (int i = 0; i < pos - 1; i++) {
                father = father->next;
            }
            father->next = father->next->next;
            return head;
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    printListNode(s.removeNthFromEnd(createListNode({1, 2, 3, 4, 5}), 2)); // 1,2,3,5
    printListNode(s.removeNthFromEnd(createListNode({1, 2, 3, 4, 5}), 1)); // 1,2,3,4
    printListNode(s.removeNthFromEnd(createListNode({1, 2, 3, 4, 5}), 5)); // 2,3,4,5
    printListNode(s.removeNthFromEnd(createListNode({1}), 1)); // NULL
    return 0;
}
