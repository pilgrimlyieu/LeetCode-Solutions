// 2025-09-21 11:25:37

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
    ListNode *reverseList(ListNode *head) {
        vector<ListNode *> v;
        v.assign(5001, nullptr);
        v[0] = nullptr;
        int idx = 0;
        while (head) {
            v[++idx] = head;
            head = head->next;
        }
        ListNode *final = v[idx];
        ListNode *current = final;
        while (current) {
            current->next = v[--idx];
            current = current->next;
        }
        return final;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << printListNode(s.reverseList(createListNode({1, 2, 3, 4, 5}))) << endl;
    return 0;
}
