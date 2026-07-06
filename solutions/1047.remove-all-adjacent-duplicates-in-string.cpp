// @leet imports start
// Created: 2025-10-19 11:13:06

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  string removeDuplicates(string s) {
    int len = s.size();
    string res;
    res.reserve(len);
    int idx = 0;
    for (int i = 0; i < len; i++) {
      if (!res.empty() && s[i] == res[idx - 1]) {
        res.pop_back();
        idx--;
        continue;
      }
      res.push_back(s[i]);
      idx++;
    }
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.removeDuplicates("abbaca") << endl;
  cout << s.removeDuplicates("azxxzy") << endl;
  return 0;
}
