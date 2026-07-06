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
    if (!(head && head->next)) {
      return head;
    }
    vector<ListNode *> odds;
    vector<ListNode *> evens;
    odds.assign(51, nullptr);
    evens.assign(51, nullptr);
    int len = 0;
    int oddi = 0;
    int eveni = 0;
    while (head) {
      if (len % 2 == 0) {
        evens[eveni++] = head;
      } else {
        odds[oddi++] = head;
      }
      len++;
      head = head->next;
    }
    for (int i = 0; i < eveni; i++) {
      evens[i]->next = odds[i + 1];
    }
    if (oddi != eveni) {
      evens[eveni - 2]->next = evens[eveni - 1];
    }
    for (int i = 0; i < oddi; i++) {
      odds[i]->next = evens[i];
    }
    return odds[0];
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.swapPairs("[]"_list) << endl;          // {}
  cout << s.swapPairs("[1]"_list) << endl;         // 1
  cout << s.swapPairs("[1,2]"_list) << endl;       // 2,1
  cout << s.swapPairs("[1,2,3]"_list) << endl;     // 2,1,3
  cout << s.swapPairs("[1,2,3,4]"_list) << endl;   // 2,1,4,3
  cout << s.swapPairs("[1,2,3,4,5]"_list) << endl; // 2,1,4,3,5
  return 0;
}
