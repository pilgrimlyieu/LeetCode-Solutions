// @leet imports start
// Created: 2025-10-15 10:51:41

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class MyQueue {
  stack<int> s1;
  stack<int> s2;
  int len = 0;

public:
  MyQueue() {}

  void push(int x) { s2.push(x); }

  int pop() {
    if (s1.empty()) {
      while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
      }
    }
    int res = s1.top();
    s1.pop();
    return res;
  }

  int peek() {
    if (s1.empty()) {
      while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
      }
    }
    int res = s1.top();
    return res;
  }

  bool empty() { return s1.empty() && s2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @leet end

int main(void) {
  MyQueue q;

  return 0;
}
