// @leet imports start
// Created: 2025-09-14 11:49:48

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int lengthOfLastWord(string s) {
    int len = s.length();
    int idx1 = -1;
    int idx2 = -1;
    for (int i = len - 1; i >= 0; i--) {
      if (idx1 == -1) {
        if (s[i] != ' ') {
          idx1 = i;
        }
        continue;
      }
      if (s[i] == ' ') {
        idx2 = i;
        break;
      }
    }
    return idx1 - idx2;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
