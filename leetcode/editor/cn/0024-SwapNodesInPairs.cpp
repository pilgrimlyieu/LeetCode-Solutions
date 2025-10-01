// 2025-10-01 11:26:31

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
    ListNode *swapPairs(ListNode *head) {
        if (!(head && head->next)) {
            return head;
        }
        vector<ListNode *> odds;
        vector<ListNode *> evens;
        odds.assign(51, nullptr);
        evens.assign(51, nullptr);
        int len = 0;
        int oddi = 0;
        int eveni = 0;
        while (head) {
            if (len % 2 == 0) {
                evens[eveni++] = head;
            }
            else {
                odds[oddi++] = head;
            }
            len++;
            head = head->next;
        }
        for (int i = 0; i < eveni; i++) {
            evens[i]->next = odds[i + 1];
        }
        if (oddi != eveni) {
            evens[eveni - 2]->next = evens[eveni - 1];
        }
        for (int i = 0; i < oddi; i++) {
            odds[i]->next = evens[i];
        }
        return odds[0];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    printListNode(s.swapPairs(createListNode({}))); // {}
    printListNode(s.swapPairs(createListNode({1}))); // 1
    printListNode(s.swapPairs(createListNode({1, 2}))); // 2,1
    printListNode(s.swapPairs(createListNode({1, 2, 3}))); // 2,1,3
    printListNode(s.swapPairs(createListNode({1, 2, 3, 4}))); // 2,1,4,3
    printListNode(s.swapPairs(createListNode({1, 2, 3, 4, 5}))); // 2,1,4,3,5
    return 0;
}
