// @leet imports start
// Created: 2026-08-20 22:11:41

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    int len = s.length();
    vector<string> ans;
    string temp;
    auto valid = [&](int left, int right) {
      if (s[left] != '0') {
        return stoi(s.substr(left, right - left + 1)) < 256;
      }
      return left == right;
    };
    auto dfs = [&](this auto &&self, int idx, int n) {
      if (idx == len) {
        if (n == 4) {
          ans.push_back(temp);
        }
        return;
      }
      for (int i = idx; i < min(len, idx + 3); i++) {
        if (valid(idx, i)) {
          temp += s.substr(idx, i - idx + 1);
          if (n != 3) {
            temp += '.';
          }
          self(i + 1, n + 1);
          int removal = i - idx + 1;
          if (n != 3) {
            removal++;
          }
          temp.resize(temp.size() - removal);
        }
      }
    };
    dfs(0, 0);
    return ans;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.restoreIpAddresses("25525511135"),
        R"(["255.255.11.135","255.255.111.35"])"_vs);
  CHECK(s.restoreIpAddresses("0000"), R"(["0.0.0.0"])"_vs);
  CHECK(s.restoreIpAddresses("101023"),
        R"(["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"])"_vs);
  return 0;
}
