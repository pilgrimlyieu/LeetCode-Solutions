// @leet imports start
// Created: 2025-10-19 11:22:12

#include "../utils.h"
#include <cctype>
#include <unordered_map>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stk;
    for (auto token : tokens) {
      if (token.size() > 1 || isdigit(token[0])) {
        stk.push(stoi(token));
      } else {
        int n1 = stk.top();
        stk.pop();
        int n2 = stk.top();
        stk.pop();
        if (token == "+") {
          stk.push(n1 + n2);
        } else if (token == "-") {
          stk.push(n2 - n1);
        } else if (token == "*") {
          stk.push(n1 * n2);
        } else if (token == "/") {
          stk.push(n2 / n1);
        }
      }
    }
    return stk.top();
  }
};
// @leet end

/// 用于学习匿名函数存储，实现偏慢
int evalRPN2(vector<string> &tokens) {
  unordered_map<string, function<int(int, int)>> map = {
      {"+", [](int a, int b) { return a + b; }},
      {"-", [](int a, int b) { return a - b; }},
      {"*", [](int a, int b) { return a * b; }},
      {"/", [](int a, int b) { return a / b; }},
  };
  stack<int> stk;
  for (auto &token : tokens) {
    if (map.count(token)) {
      int n1 = stk.top();
      stk.pop();
      int n2 = stk.top();
      stk.pop();
      stk.push(map[token](n2, n1));
    } else {
      stk.push(stoi(token));
    }
  }
  return stk.top();
}

int main(void) {
  Solution s;

  return 0;
}
