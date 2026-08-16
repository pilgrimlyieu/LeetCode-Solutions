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

// @card hint
// 主要思考字符串到数字的转换函数，与匿名函数的写法。

// @card note
// 使用 `count` 来判断是否存在，也可以用 `find` 并与 `end` 迭代器判等。

// @alt 匿名函数映射
// 用于学习匿名函数存储（实现偏慢）：实际上题目给了固定情形，且没有复用的需要，也没必要这样写。
class SolutionMap {
public:
  int evalRPN(vector<string> &tokens) {
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
};
// @alt end

int main(void) {
  Solution s;
  SolutionMap s2;
  auto t1 = vector<string>{"2", "1", "+", "3", "*"};
  CHECK(s.evalRPN(t1), 9);
  CHECK(s2.evalRPN(t1), 9);
  auto t2 = vector<string>{"4", "13", "5", "/", "+"};
  CHECK(s.evalRPN(t2), 6);
  CHECK(s2.evalRPN(t2), 6);
  return 0;
}
