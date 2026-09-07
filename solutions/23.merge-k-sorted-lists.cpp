// @leet imports start
// Created: 2026-09-07 22:16:35

#include "../utils.h"
#include <queue>
#include <vector>

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq;
    for (auto list : lists) {
      if (list) {
        pq.push(list);
      }
    }
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (!pq.empty()) {
      auto node = pq.top();
      pq.pop();
      tail->next = node;
      tail = tail->next;
      if (node->next) {
        pq.push(node->next);
      }
    }
    return dummy.next;
  }
};
// @leet end

// @card idea 优先队列
// `Compare` 在这里的含义是 `a` 优先级是否低于 `b`。默认 `less` 是大根堆。

// @alt 分治
class SolutionDAC {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto mergeTwoLists = [](ListNode *a, ListNode *b) {
      ListNode dummy(0);
      ListNode *tail = &dummy;
      while (a && b) {
        if (a->val < b->val) {
          tail->next = a;
          a = a->next;
        } else {
          tail->next = b;
          b = b->next;
        }
        tail = tail->next;
      }
      tail->next = a ? a : b;
      return dummy.next;
    };
    auto merge = [&](this auto &&self, int left, int right) -> ListNode * {
      if (left == right) {
        return lists[left];
      } else if (left > right) {
        return nullptr;
      }
      int mid = (left + right) / 2;
      return mergeTwoLists(self(left, mid), self(mid + 1, right));
    };
    return merge(0, lists.size() - 1);
  }
};
// @alt end

int main() {
  Solution s;
  // CHECK(s.mergeKLists(/* TODO lists = [[1,4,5],[1,3,4],[2,6]] */),
  //       "[1,1,2,3,4,4,5,6]"_list);
  // CHECK(s.mergeKLists(/* TODO lists = [] */), "[]"_list);
  // CHECK(s.mergeKLists(/* TODO lists = [[]] */), "[]"_list);
  return 0;
}
