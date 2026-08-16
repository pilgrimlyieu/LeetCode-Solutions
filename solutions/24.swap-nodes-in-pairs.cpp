// @leet imports start
// Created: 2025-10-01 11:26:31

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
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *res = head->next;
    while (curr) {
      ListNode *next = curr->next;
      if (!next) {
        break;
      }
      if (prev) {
        prev->next = next;
      }
      curr->next = next->next;
      next->next = curr;
      prev = curr;
      curr = curr->next;
    }
    return res;
  }
};
// @leet end

// @card idea
// 每次以 `curr` 为中心，预先保存 `next`，交换 `prev`, `curr`，然后移动 `curr`。

// @card note
// 这里没有用哨兵节点，于是需要预先记录初始结果。

int main(void) {
  Solution s;
  CHECK(s.swapPairs("[]"_list), "[]"_list);
  CHECK(s.swapPairs("[1]"_list), "[1]"_list);
  CHECK(s.swapPairs("[1,2]"_list), "[2,1]"_list);
  CHECK(s.swapPairs("[1,2,3]"_list), "[2,1,3]"_list);
  CHECK(s.swapPairs("[1,2,3,4]"_list), "[2,1,4,3]"_list);
  CHECK(s.swapPairs("[1,2,3,4,5]"_list), "[2,1,4,3,5]"_list);
  return 0;
}
