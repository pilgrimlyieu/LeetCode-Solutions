// @leet imports start
// Created: 2025-10-05 10:27:19

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> map;
    while (headA) {
      map.insert(headA);
      headA = headA->next;
    }
    while (headB) {
      if (map.find(headB) != map.end()) {
        return headB;
      }
      headB = headB->next;
    }
    return nullptr;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
