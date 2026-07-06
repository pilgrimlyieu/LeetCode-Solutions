// @leet imports start
// Created: 2025-10-01 10:45:43

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class MyLinkedList {
public:
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode *head;
  ListNode *tail;
  int length;

  MyLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
  }

  int get(int index) {
    ListNode *cur = head;
    for (int i = 0; i < index; i++) {
      if (!cur->next) {
        return -1;
      }
      cur = cur->next;
    }
    return cur ? cur->val : -1;
  }

  void addAtHead(int val) {
    ListNode *newhead = new ListNode(val);
    newhead->next = head;
    head = newhead;
    if (length == 0) {
      tail = head;
    }
    length++;
  }

  void addAtTail(int val) {
    ListNode *newtail = new ListNode(val);
    if (length > 0) {
      tail->next = newtail;
      tail = newtail;
    } else {
      head = newtail;
      tail = newtail;
    }
    length++;
  }

  void addAtIndex(int index, int val) {
    if (index == length) {
      addAtTail(val);
    } else if (index == 0) {
      addAtHead(val);
    } else if (index < length) {
      ListNode *cur = head;
      for (int i = 0; i < index - 1; i++) {
        cur = cur->next;
      }
      ListNode *newnode = new ListNode(val);
      newnode->next = cur->next;
      cur->next = newnode;
      length++;
    }
  }

  void deleteAtIndex(int index) {
    if (index == 0 && length) {
      head = head->next;
      if (length == 1) {
        tail = nullptr;
      }
      length--;
    } else if (index < length) {
      ListNode *cur = head;
      for (int i = 0; i < index - 1; i++) {
        cur = cur->next;
      }
      if (index == length - 1) {
        tail = cur;
      }
      cur->next = cur->next->next;
      length--;
    }
  }

  void printLL() {
    ListNode *cur = head;
    while (cur) {
      cout << cur->val;
      if (cur->next) {
        cout << "->";
      }
      cur = cur->next;
    }
    cout << endl;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @leet end

int main(void) {
  // MyLinkedList *t = new MyLinkedList();
  // t->addAtHead(1); // 1
  // t->printLL();
  // t->addAtTail(3); // 1->3
  // t->printLL();
  // t->addAtIndex(1, 2); // 1->2->3
  // t->printLL();
  // t->deleteAtIndex(1); // 1->3
  // cout << t->get(1) << endl; // 3

  MyLinkedList *t = new MyLinkedList();
  t->addAtHead(0); // 0
  t->printLL();
  t->addAtIndex(1, 4); // 0->4
  t->printLL();
  t->addAtTail(8); // 0->4->8
  t->printLL();
  t->addAtHead(5); // 5->0->4->8
  t->printLL();
  t->addAtIndex(4, 3); // 5->0->4->8->3
  t->printLL();
  t->addAtTail(0); // 5->0->4->8->3->0
  t->printLL();
  t->addAtTail(5); // 5->0->4->8->3->0->5
  t->printLL();
  t->addAtIndex(6, 3); // 5->0->4->8->3->0->3->5
  t->printLL();
  t->deleteAtIndex(7); // 5->0->4->8->3->0->3
  t->printLL();
  t->deleteAtIndex(5); // 5->0->4->8->3->3
  t->printLL();
  t->addAtTail(4); // 5->0->4->8->3->3->4
  t->printLL();
  return 0;
}
