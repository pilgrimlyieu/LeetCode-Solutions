// @leet imports start
// Created: 2026-08-19 22:28:37

#include "../utils.h"
#include <unordered_map>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    int size = digits.size();
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                      {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;
    string temp;
    auto select = [&](this auto &&self, int i) {
      if (i == size) {
        ans.push_back(temp);
        return;
      }
      for (auto c : mp[digits[i]]) {
        temp += c;
        self(i + 1);
        temp.pop_back();
      }
    };
    select(0);
    return ans;
  }
};
// @leet end

int main() {
  Solution s;
  // 题面允许任意顺序，必要时改用 CHECK_ANYORDER
  CHECK_ANYORDER(s.letterCombinations("23"),
                 R"(["ad","ae","af","bd","be","bf","cd","ce","cf"])"_vs);
  CHECK_ANYORDER(s.letterCombinations("2"), R"(["a","b","c"])"_vs);
  return 0;
}
