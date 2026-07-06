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
  // vector<char> s1 = {'t', 'e', 's', 'a'};
  // vector<char> s2 = {'t', 'e', 's'};
  auto s1 = S2V("tesa");
  auto s2 = S2V("tes");
  s.reverseString(s1);
  s.reverseString(s2);
  cout << s1 << endl << s2 << endl;
  return 0;
}
