// @leet imports start
// Created: 2025-09-17 19:58:53

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  string toLowerCase(string s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] += 'a' - 'A';
      }
    }
    return s;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
