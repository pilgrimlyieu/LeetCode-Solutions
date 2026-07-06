// @leet imports start
// Created: 2025-10-05 10:38:15

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
  bool hasCycle(ListNode *head) {
    ListNode *fir = head;
    ListNode *sec = head;
    int time = 0;
    while (sec) {
      if (time % 2 == 0) {
        fir = fir->next;
      }
      sec = sec->next;
      if (fir == sec && time >= 1) {
        return true;
      }
      time++;
    }
    return false;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
