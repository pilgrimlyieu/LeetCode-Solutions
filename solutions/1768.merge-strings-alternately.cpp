// @leet imports start
// Created: 2025-09-12 22:45:08

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    size_t len1 = word1.length();
    size_t len2 = word2.length();
    string result(len1 + len2, ' ');
    size_t min_len = min(len1, len2);
    size_t idx = 0;
    for (size_t i = 0; i < min_len; i++) {
      result[idx++] = word1[i];
      result[idx++] = word2[i];
    }
    for (size_t i = min_len; i < len1; i++) {
      result[idx++] = word1[i];
    }
    for (size_t i = min_len; i < len2; i++) {
      result[idx++] = word2[i];
    }
    return result;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
