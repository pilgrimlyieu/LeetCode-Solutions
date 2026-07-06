// @leet imports start
// Created: 2025-09-24 20:12:22

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
};
// @leet end

int main(void) {
  Solution s;
  cout << s.addTwoNumbers("[9,9,9,9]"_list, "[9]"_list) << endl; // [8,0,0,0,1]
  cout << s.addTwoNumbers("[9,9,1]"_list, "[1]"_list) << endl;   // [0,0,2]
  return 0;
}
