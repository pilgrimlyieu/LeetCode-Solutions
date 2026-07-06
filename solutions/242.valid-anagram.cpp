// @leet imports start
// Created: 2025-09-12 23:16:19

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> mp;
    for (auto c : s) {
      if (mp.find(c) == mp.end()) {
        mp[c] = 1;
      } else {
        mp[c]++;
      }
    }
    for (auto c : t) {
      if (mp.find(c) == mp.end()) {
        return false;
      } else {
        mp[c]--;
      }
    }
    for (auto i : mp) {
      if (i.second != 0) {
        return false;
      }
    }
    return true;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
