// @leet imports start
// Created: 2025-10-15 11:15:15

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class MyStack {
  queue<int> q;
  int p = 0;

public:
  MyStack() {}

  void push(int x) {
    if (p != q.size()) {
      int n = q.front();
      q.push(n);
      q.pop();
      p = q.size();
    }
    q.push(x);
    p++;
  }

  int pop() {
    for (int i = 0; i < p - 1; i++) {
      int n = q.front();
      q.pop();
      q.push(n);
    }
    int n = q.front();
    q.pop();
    p = q.size();
    return n;
  }

  int top() {
    for (int i = 0; i < p - 1; i++) {
      int n = q.front();
      q.pop();
      q.push(n);
    }
    p = 1;
    return q.front();
  }

  bool empty() {
    return q.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @leet end

int main(void) {
  MyStack *s = new MyStack();
  s->push(1);
  s->push(2);
  cout << s->top() << endl;
  s->push(3);
  cout << s->top() << endl;
  return 0;
}
