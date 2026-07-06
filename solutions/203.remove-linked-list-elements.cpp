// @leet imports start
// Created: 2025-10-01 10:29:19

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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *res = head;
    while (res && res->val == val) {
      res = res->next;
    }
    ListNode *cur = res;
    while (cur && cur->next) {
      ListNode *vali = cur->next;
      if (cur->next->val == val) {
        while (vali && vali->val == val) {
          vali = vali->next;
        }
        cur->next = vali;
      }
      cur = vali;
    }
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.removeElements("[1,2,6,3,4,5,6]"_list, 6) << endl;
  cout << s.removeElements("[]"_list, 1) << endl;
  cout << s.removeElements("[7,7,7,7]"_list, 7) << endl;
  cout << s.removeElements("[7,7,7,7,1]"_list, 7) << endl;
  cout << s.removeElements("[7,7,7,7,1,1]"_list, 7) << endl;
  cout << s.removeElements("[2,2,7,7,7,7,1,1]"_list, 7) << endl;
  return 0;
}
