// @leet imports start
// Created: 2025-09-12 23:04:40

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int strStr(string haystack, string needle) {
    size_t len1 = haystack.length();
    size_t len2 = needle.length();
    if (len2 > len1) {
      return -1;
    }
    for (size_t i = 0; i <= len1 - len2; i++) {
      if (haystack[i] == needle[0]) {
        for (size_t j = 1; j < len2; j++) {
          if (haystack[i + j] != needle[j]) {
            goto fail;
          }
        }
        return i;
      }
    fail:
    }
    return -1;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
