// @leet imports start
// Created: 2025-09-12 23:04:40

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int strStr(string haystack, string needle) {
    int hlen = haystack.size(), nlen = needle.size();
    if (hlen < nlen) {
      return -1;
    }
    vector<int> next(nlen);
    next[0] = 0;
    for (int i = 1, j = 0; i < nlen; i++) {
      while (j > 0 && needle[i] != needle[j]) {
        j = next[j - 1];
      }
      if (needle[i] == needle[j]) {
        j++;
      }
      next[i] = j;
    }
    for (int i = 0, j = 0; i < hlen; i++) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == nlen) {
        return i - j + 1;
      }
    }
    return -1;
  }
};
// @leet end

int main(void) {
  Solution s;
  CHECK(s.strStr("abacababacababc", "abacababc"), 6);
  CHECK(s.strStr("aaa", "a"), 0);
  CHECK(s.strStr("aaa", "aa"), 0);
  CHECK(s.strStr("aaa", "aaa"), 0);
  CHECK(s.strStr("a", "a"), 0);
  CHECK(s.strStr("sadbutsad", "sad"), 0);
  CHECK(s.strStr("leetcode", "leeto"), -1);
  CHECK(s.strStr("hello", "ll"), 2);
  CHECK(s.strStr("aaaaa", "bba"), -1);
  CHECK(s.strStr("mississippi", "issip"), 4);
  CHECK(s.strStr("mississippi", "issipi"), -1);
  return 0;
}
