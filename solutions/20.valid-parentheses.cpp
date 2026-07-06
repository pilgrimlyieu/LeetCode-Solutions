// @leet imports start
// Created: 2025-10-19 11:05:52

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for (auto c : s) {
      if (stk.empty()) {
        stk.push(c);
      } else {
        char top = stk.top();
        if (c == ')' && top == '(') {
          stk.pop();
        } else if (c == '}' && top == '{') {
          stk.pop();
        } else if (c == ']' && top == '[') {
          stk.pop();
        } else {
          stk.push(c);
        }
      }
    }
    return stk.empty();
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
