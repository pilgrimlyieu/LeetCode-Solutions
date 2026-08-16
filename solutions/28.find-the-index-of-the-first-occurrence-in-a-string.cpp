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

// @card hint
// KMP 算法

// @card idea
// 使用 `next` 数组构造避免原串指针 `i` 回溯，而匹配串指针 `j` 则回溯到最后一个匹配字符对应的 `next` 值。
//
// `next` 数组的含义即，到该位的前缀字符串的最长公共前后缀长度，在后缀匹配失败时，可以直接跳过前缀的匹配继续。

// @card note
// 注意 `i` 不代表原串中匹配串的起点，因此要持续匹配到 `hlen` 而非 `hlen - nlen`。
//
// `j` 只用最初初始化，而不用每次循环重新初始化，因为上一轮循环最后赋值的时候就保证了 `j = next[i - 1]`。
//
// 两处 `while` 之后的判等是为了检查当前这个新字符是否匹配上了前缀的下一个字符。

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
