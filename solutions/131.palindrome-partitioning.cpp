// @leet imports start
// Created: 2026-08-20 21:17:21

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<string>> partition(string s) {
    int size = s.size();
    vector<vector<string>> ans;
    vector<string> temp;
    vector<vector<int>> f(size, vector<int>(size, true));
    for (int i = size - 1; i >= 0; i--) {
      for (int j = i + 1; j < size; j++) {
        f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
      }
    }
    int last = 0;
    auto dfs = [&](this auto &&self, int i) {
      if (i == s.size()) {
        if (last == s.size()) {
          ans.push_back(temp);
        }
        return;
      }
      self(i + 1);
      if (f[last][i]) {
        int tmp = last;
        temp.emplace_back(s, last, i - last + 1);
        last = i + 1;
        self(i + 1);
        temp.pop_back();
        last = tmp;
      }
    };
    dfs(0);
    return ans;
  }
};
// @leet end

// @card hint
// 如何存取字符串的部分？

// @card idea
// 依旧可以用循环法，标记起点，然后遍历后面的点，就不用 `last` 变量。
//
// DP 的时候注意，后处理的依赖于前处理的，因此要确保正确遵照依赖关系。如外层循环 `i` 要先获取 `i + 1` 的情况，因此要从大到小遍历。

// @card note
// 获取部分字符串可以用 `s.substr(start, length)`，存取可以用 `vec.emplace_back(s, start, length)`。

int main() {
  Solution s;
  CHECK_ANYORDER(s.partition("aab"), R"([["a","a","b"],["aa","b"]])"_vvs);
  CHECK_ANYORDER(s.partition("a"), R"([["a"]])"_vvs);

  CHECK_ANYORDER(
      s.partition("abbab"),
      R"([["a","b","b","a","b"],["a","b","bab"],["a","bb","a","b"],["abba","b"]])"_vvs);
  return 0;
}
