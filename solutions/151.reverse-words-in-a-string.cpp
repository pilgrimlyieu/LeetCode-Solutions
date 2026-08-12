// @leet imports start
// Created: 2025-10-15 10:23:30

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  string reverseWords(string s) {
    int len = s.size();
    string res;
    res.reserve(len);
    int i = len - 1, j = len - 1;
    while (j >= 0) {
      while (j >= 0 && s[j] == ' ') {
        j--;
      }
      if (j < 0) {
        break;
      }
      i = j;
      while (i >= 0 && s[i] != ' ') {
        i--;
      }
      for (int k = i + 1; k <= j; k++) {
        res.push_back(s[k]);
      }
      res.push_back(' ');
      j = i;
    }
    res.pop_back();
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  CHECK(s.reverseWords("a"), "a");
  CHECK(s.reverseWords(" abc "), "abc");
  CHECK(s.reverseWords(" abc"), "abc");
  CHECK(s.reverseWords("abc "), "abc");
  CHECK(s.reverseWords("abc    def"), "def abc");
  CHECK(s.reverseWords("   abc   def  "), "def abc");
  CHECK(s.reverseWords("the sky is blue"), "blue is sky the");
  CHECK(s.reverseWords("  hello world  "), "world hello");
  CHECK(s.reverseWords("a good   example"), "example good a");
  return 0;
}
