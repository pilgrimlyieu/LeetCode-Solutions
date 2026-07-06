// @leet imports start
// Created: 2025-10-05 10:15:09

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
    } else {
      ListNode *father = head;
      for (int i = 0; i < pos - 1; i++) {
        father = father->next;
      }
      father->next = father->next->next;
      return head;
    }
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.removeNthFromEnd("[1,2,3,4,5]"_list, 2) << endl; // 1,2,3,5
  cout << s.removeNthFromEnd("[1,2,3,4,5]"_list, 1) << endl; // 1,2,3,4
  cout << s.removeNthFromEnd("[1,2,3,4,5]"_list, 5) << endl; // 2,3,4,5
  cout << s.removeNthFromEnd("[1]"_list, 1) << endl;         // NULL
  return 0;
}
