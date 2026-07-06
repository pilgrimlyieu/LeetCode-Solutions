// @leet imports start
// Created: 2025-10-08 11:27:37

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> v1;
    v1.assign(26, 0);
    vector<int> v2;
    v2.assign(26, 0);
    for (auto c : ransomNote) {
      v1[c - 'a']++;
    }
    for (auto c : magazine) {
      v2[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (v1[i] > v2[i]) {
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
