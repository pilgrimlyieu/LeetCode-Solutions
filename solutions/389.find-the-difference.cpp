// @leet imports start
// Created: 2025-09-12 22:54:32

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> mp;
    for (char c : s) {
      if (mp.find(c) == mp.end()) {
        mp[c] = 1;
      } else {
        mp[c]++;
      }
    }
    for (char c : t) {
      if (mp.find(c) == mp.end()) {
        return c;
      } else {
        mp[c]--;
      }
    }
    for (auto i : mp) {
      if (i.second == -1) {
        return i.first;
      }
    }
    return ' '; // impossible
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
