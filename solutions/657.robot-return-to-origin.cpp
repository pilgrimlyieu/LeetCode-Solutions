// @leet imports start
// Created: 2025-09-17 20:15:11

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool judgeCircle(string moves) {
    int h = 0;
    int v = 0;
    for (auto s : moves) {
      switch (s) {
      case 'L':
        h++;
        break;
      case 'R':
        h--;
        break;
      case 'U':
        v++;
        break;
      case 'D':
        v--;
        break;
      }
    }
    return h == 0 && v == 0;
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.judgeCircle("UD") << s.judgeCircle("LL");
  return 0;
}
