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
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};
// @leet end

// @card idea
// 以 `curr` 为中心，记录 `next`，并反转 `prev` 与 `curr` 之间的箭头方向。

// @card note
// 将 `prev` 设为空指针即代表开始的情形，避免特判。

int main(void) {
  Solution s;
  CHECK(s.reverseList("[1,2,3,4,5]"_list), "[5,4,3,2,1]"_list);
  CHECK(s.reverseList("[]"_list), "[]"_list);
  CHECK(s.reverseList("[1]"_list), "[1]"_list);
  return 0;
}
