// @leet imports start
// Created: 2025-09-21 11:25:37

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
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
// @leet end

int main(void) {
  Solution s;
  cout << s.reverseList("[1,2,3,4,5]"_list) << endl;
  return 0;
}
