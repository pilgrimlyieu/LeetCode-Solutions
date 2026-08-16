// @leet imports start
// Created: 2025-09-12 23:16:19

#include "../utils.h"
#include <algorithm>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool isAnagram(string s, string t) {
    int ab[26] = {0};
    for (auto ch : s) {
      ab[ch - 'a']++;
    }
    // 也可以初始时比较字符串长度，减的时候注意有没有变负数
    for (auto ch : t) {
      ab[ch - 'a']--;
    }
    return all_of(ab, ab + 26, [](int a) { return a == 0; });
    // 也可以用 std::{begin, end} 语义更清晰
    // 但对于作为函数参数且退化成指针的情形则不行
  }
};
// @leet end

// @card note
// 主要是学习 `<algorithm>` 库中一些函数，如 `all_of`。

int main(void) {
  Solution s;

  return 0;
}
