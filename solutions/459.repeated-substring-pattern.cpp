// @leet imports start
// Created: 2025-09-12 23:19:21

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    size_t len = s.length();
    for (size_t i = 0; i < len / 2; i++) {
      if (len % (i + 1) != 0) {
        continue;
      }
      for (int t = 0; t < len / (i + 1); t++) {
        for (int idx = 0; idx < i + 1; idx++) {
          if (s[idx] != s[t * (i + 1) + idx]) {
            goto fail;
          }
        }
      }
      return true;
    fail:
    }
    return false;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
