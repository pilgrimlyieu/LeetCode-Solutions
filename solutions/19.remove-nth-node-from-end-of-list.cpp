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
    auto dummy = new ListNode(0, head);
    auto first = dummy;
    auto second = head;
    while (n--) {
      second = second->next;
    }
    while (second) {
      first = first->next;
      second = second->next;
    }
    first->next = first->next->next;
    return dummy->next;
  }
};
// @leet end

int main(void) {
  Solution s;
  CHECK(s.removeNthFromEnd("[1,2,3,4,5]"_list, 2), "[1,2,3,5]"_list);
  CHECK(s.removeNthFromEnd("[1,2,3,4,5]"_list, 1), "[1,2,3,4]"_list);
  CHECK(s.removeNthFromEnd("[1,2,3,4,5]"_list, 5), "[2,3,4,5]"_list);
  CHECK(s.removeNthFromEnd("[1]"_list, 1), "[]"_list);
  CHECK(s.removeNthFromEnd("[1,2]"_list, 1), "[1]"_list);
  return 0;
}
