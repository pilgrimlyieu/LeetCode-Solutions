// @leet imports start
// Created: 2025-09-24 20:41:05

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
  ListNode *addTwoNumbersRev(ListNode *l1, ListNode *l2) {
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
      // cout << "[DEBUG1] " << current << endl;
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
      // cout << "[DEBUG2] " << current << endl;
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
      // cout << "[DEBUG3] " << current << endl;
    }
    if (next) {
      result->val = next;
    }
    return current;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    return reverseList(addTwoNumbersRev(reverseList(l1), reverseList(l2)));
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
