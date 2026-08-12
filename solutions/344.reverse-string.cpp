// @leet imports start
// Created: 2025-10-10 10:57:57

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  void reverseString(vector<char> &s) {
    int len = s.size();
    for (int i = 0; i < len / 2; i++) {
      swap(s[i], s[len - 1 - i]);
    }
  }
};
// @leet end

int main(void) {
  Solution s;
  auto s1 = "tesa"_vc;
  auto s2 = "tes"_vc;
  s.reverseString(s1);
  s.reverseString(s2);
  CHECK(s1, "aset"_vc);
  CHECK(s2, "set"_vc);
  return 0;
}
