// @leet imports start
// Created: 2025-10-19 11:05:52

#include "../utils.h"
#include <unordered_map>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool isValid(string s) {
    int n = s.size();
    if (n % 2 == 1) {
      return false;
    }
    unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};
    stack<char> stk;
    for (auto ch : s) {
      if (pairs.count(ch)) { // 或 pairs.find(ch) != pairs.end()
        if (stk.empty() || stk.top() != pairs[ch]) {
          return false;
        }
        stk.pop();
      } else {
        stk.push(ch);
      }
    }
    return stk.empty();
  }
};
// @leet end

int main(void) {
  Solution s;
  CHECK(s.isValid("()"), true);
  CHECK(s.isValid("()[]{}"), true);
  CHECK(s.isValid("([)]"), false);
  CHECK(s.isValid("))"), false);
  CHECK(s.isValid("([}}])"), false);
  return 0;
}
