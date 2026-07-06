// @leet imports start
// Created: 2025-10-19 11:22:12

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
  bool isnumber(string s) {
    int len = s.size();
    if (len < 1)
      return false;
    if (isdigit(s[0]) || (s[0] == '-' && len >= 2)) {
      for (int i = 1; i < len; i++) {
        if (!isdigit(s[i]))
          return false;
      }
      return true;
    }
    return false;
  }

public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stk;
    for (auto token : tokens) {
      if (isnumber(token)) {
        stk.push(stoi(token));
      } else {
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        int res;
        if (token == "+") {
          res = a + b;
        } else if (token == "-") {
          res = b - a;
        } else if (token == "*") {
          res = a * b;
        } else if (token == "/") {
          res = b / a;
        }
        stk.push(res);
      }
    }
    return stk.top();
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
