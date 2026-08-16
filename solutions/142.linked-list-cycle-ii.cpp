// @leet imports start
// Created: 2025-10-05 10:46:42

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
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *quick = head;
    while (quick) {
      if (!quick->next) {
        break;
      }
      slow = slow->next;
      quick = quick->next->next;
      if (slow == quick) {
        ListNode *root = head;
        while (slow != root) {
          slow = slow->next;
          root = root->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
// @leet end

// @card idea
// 若有环则不可能遇到空节点，使用快慢指针必定会相遇。

// @card note
// 为了找到入口，考虑环外链长 `a`，环长 `b`，快指针速度是慢指针的两倍，相遇时有 `t = a + mb + l` 与 `2t = a + nb + l`，即 `t = (n - m)b`，慢指针继续或是从起始点出发再走 `a` 就会在入口处相遇。其他参数也都可以以此计算出来。

int main(void) {
  Solution s;
  auto l1 = "[3,2,0,-4]"_list;
  (*l1)[3]->next = (*l1)[1];
  CHECK(s.detectCycle(l1)->val, 2);
  auto l2 = "[1,2]"_list;
  (*l2)[1]->next = l2;
  CHECK(s.detectCycle(l2)->val, 1);
  auto l3 = "[1]"_list;
  CHECK(s.detectCycle(l3), "[]"_list);
  return 0;
}
