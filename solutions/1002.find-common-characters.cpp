// @leet imports start
// Created: 2025-10-05 11:15:45

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    int len = words.size();
    vector<string> res;
    res.reserve(words[0].length());
    unordered_map<char, int> alp;
    for (auto c : words[0]) {
      if (alp.find(c) == alp.end()) {
        alp[c] = 1;
      } else {
        alp[c]++;
      }
    }
    for (int i = 1; i < len; i++) {
      auto w = words[i];
      unordered_map<char, int> temp;
      for (auto c : w) {
        if (temp.find(c) == temp.end()) {
          temp[c] = 1;
        } else {
          temp[c]++;
        }
      }
      for (auto p : alp) {
        if (temp.find(p.first) != temp.end()) {
          alp[p.first] = min(alp[p.first], temp[p.first]);
        } else {
          alp[p.first] = -1;
        }
      }
    }
    for (auto p : alp) {
      for (int i = 0; i < p.second; i++) {
        // res.emplace_back(string() + p.first);
        res.emplace_back(1, p.first); // 构造函数 int count, char c
      }
    }
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  vector<string> v1 = {"bella", "label", "roller"};
  cout << s.commonChars(v1) << endl; // ell
  vector<string> v2 = {"cool", "lock", "cook"};
  cout << s.commonChars(v2) << endl; // co
  return 0;
}
