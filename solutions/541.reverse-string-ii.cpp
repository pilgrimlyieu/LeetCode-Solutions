// @leet imports start
// Created: 2025-10-10 11:12:15

#include "../utils.h"
#include <utility>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  string reverseStr(string s, int k) {
    int len = s.size();
    for (int i = 0; i < len; i += 2 * k) {
      reverse(s.begin() + i, s.begin() + min(k + i, len));
    }
    return s;
  }
};
// @leet end

// @card note
// 主要就是学一下 `reverse`，以及放心大胆用 `min` 等让代码更清晰。

int main(void) {
  Solution s;
  CHECK(s.reverseStr("1234", 2), "2134");
  CHECK(s.reverseStr("123456", 2), "213465");
  CHECK(s.reverseStr("12345678", 2), "21346578");
  CHECK(s.reverseStr("1234567", 8), "7654321");
  return 0;
}
