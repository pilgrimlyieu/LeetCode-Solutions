// @leet imports start
// Created: 2025-09-21 11:12:26

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *current;
    if (list1 == NULL && list2 == NULL) {
      return NULL;
    }
    if ((list1 && list2 && list1->val < list2->val) || list2 == NULL) {
      current = list1;
      list1 = list1->next;
    } else {
      current = list2;
      list2 = list2->next;
    }
    ListNode *final = current;
    while (list1 || list2) {
      ListNode *now;
      if ((list1 && list2 && list1->val < list2->val) || list2 == NULL) {
        now = list1;
        list1 = list1->next;
      } else {
        now = list2;
        list2 = list2->next;
      }
      final->next = now;
      final = now;
    }
    return current;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
