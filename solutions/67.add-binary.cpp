// @leet imports start
// Created: 2025-09-21 10:25:44

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int toNum(char c) { return c - '0'; }

  char toChar(int b) { return b + '0'; }

  string addBinary(string a, string b) {
    int len1 = a.length();
    int len2 = b.length();
    int len_max = max(len1, len2);
    int len_min = min(len1, len2);
    char s[len_max + 1];
    s[len_max] = '\0';
    int idx = len_max - 1;
    int plus = 0;
    for (int i = 1; i <= len_min; i++) {
      int result = plus + toNum(a[len1 - i]) + toNum(b[len2 - i]);
      plus = result / 2;
      s[idx--] = toChar(result % 2);
    }
    if (len1 == len_max) {
      for (int i = 0; i < len_max - len_min; i++) {
        s[i] = a[i];
      }
    } else {
      for (int i = 0; i < len_max - len_min; i++) {
        s[i] = b[i];
      }
    }
    if (plus) {
      if (len1 == len_max) {
        int idx_0 = len_max - len_min - 1;
        while (idx_0 >= 0 && a[idx_0] != '0') {
          idx_0--;
        }
        for (int i = idx_0 + 1; i < len_max - len_min; i++) {
          s[i] = '0';
        }
        if (idx_0 == -1) {
          return '1' + string(s);
        }
        s[idx_0] = '1';
      } else if (len2 == len_max) {
        int idx_0 = len_max - len_min - 1;
        while (idx_0 >= 0 && b[idx_0] != '0') {
          idx_0--;
        }
        for (int i = idx_0 + 1; i < len_max - len_min; i++) {
          s[i] = '0';
        }
        if (idx_0 == -1) {
          return '1' + string(s);
        }
        s[idx_0] = '1';
      }
    }
    return s;
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.addBinary("11", "1") << endl;      // 100
  cout << s.addBinary("1010", "1011") << endl; // 10101
  cout << s.addBinary("1", "111") << endl;     // 1000
  return 0;
}
