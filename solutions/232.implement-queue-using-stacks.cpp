// @leet imports start
// Created: 2025-10-15 10:51:41

#include "../utils.h"
#include <stack>

using namespace std;
// @leet imports end

// @leet start
class MyQueue {
public:
  stack<int> inStk;
  stack<int> outStk;

  MyQueue() {}

  void push(int x) {
    inStk.push(x);
  }

  int pop() {
    shake();
    int res = outStk.top();
    outStk.pop();
    return res;
  }

  int peek() {
    shake();
    return outStk.top();
  }

  bool empty() {
    return inStk.empty() && outStk.empty();
  }

  void shake() {
    if (outStk.empty()) {
      while (!inStk.empty()) {
        outStk.push(inStk.top());
        inStk.pop();
      }
    }
  }
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

// @card idea
// 将两个栈分别作为输入和输出栈即可。

int main(void) {
  MyQueue q;
  return 0;
}
