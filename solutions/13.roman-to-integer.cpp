// @leet imports start
// Created: 2025-09-14 11:38:08

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int getNum(char c) {
    switch (c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return 0;
    }
  }

  bool rComp(char a, char b) { return getNum(a) > getNum(b); }

  int romanToInt(string s) {
    int len = s.length();
    bool first = false;
    int result = 0;
    for (int i = len - 1; i > 0; i--) {
      if (rComp(s[i], s[i - 1])) {
        result += getNum(s[i]) - getNum(s[i - 1]);
        if (--i == 0) {
          first = true;
        }
      } else {
        result += getNum(s[i]);
      }
    }
    if (!first) {
      result += getNum(s[0]);
    }
    return result;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
