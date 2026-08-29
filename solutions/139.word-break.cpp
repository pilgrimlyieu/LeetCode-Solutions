// @leet imports start
// Created: 2026-08-29 15:03:32

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    bitset<301> dp;
    dp.set(0);
    for (int i = 1; i <= s.size(); i++) {
      for (auto &word : wordDict) {
        if (dp.test(i)) {
          continue;
        }
        if (i >= word.size() && dp.test(i - word.size())) {
          bool valid = true;
          for (int j = 0; j < word.size(); j++) {
            if (word[j] != s[i - word.size() + j]) {
              valid = false;
              break;
            }
          }
          dp.set(i, valid);
        }
      }
    }
    return dp.test(s.size());
  }
};
// @leet end

// @card idea 动态规划
// 明确 `dp[i]` 的含义：前 `i` 个字符是否构成回文串，即 `s[i]` 应该是要检查的下一个字串起点。

// @card note
// 除了用 bitset 外还进行了优化：
// 1. 如只要当前位置已经是回文串，可以不必继续遍历词表；
// 2. 不使用 `substr`，因为总会创建一个副本。
//     - 不过考虑到，如果字典数据规模较大效率较低。可以考虑将字典存入 `unordered_set<string>`，并用 `for (j in 0..i)` 检查每一个子串，时间复杂度 $O(n^2)$。

int main() {
  Solution s;
  CHECK(s.wordBreak("leetcode", R"(["leet","code"])"_vs), true);
  CHECK(s.wordBreak("applepenapple", R"(["apple","pen"])"_vs), true);
  CHECK(s.wordBreak("catsandog", R"(["cats","dog","sand","and","cat"])"_vs),
        false);
  return 0;
}
