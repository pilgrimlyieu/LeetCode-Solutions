// @leet imports start
// Created: 2026-08-19 22:37:34

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    int size = candidates.size();
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    auto backtrace = [&](this auto &&self, int i) {
      if (i == size || sum >= target) {
        if (sum == target) {
          ans.push_back(temp);
        }
        return;
      }
      temp.push_back(candidates[i]);
      sum += candidates[i];
      self(i);
      temp.pop_back();
      sum -= candidates[i];
      self(i + 1);
    };
    backtrace(0);
    return ans;
  }
};
// @leet end

int main() {
  Solution s;
  // 题面允许任意顺序，必要时改用 CHECK_ANYORDER
  CHECK_ANYORDER(s.combinationSum("[2,3,6,7]"_vi, 7), "[[2,2,3],[7]]"_vvi);
  CHECK_ANYORDER(s.combinationSum("[2,3,5]"_vi, 8),
                 "[[2,2,2,2],[2,3,3],[3,5]]"_vvi);
  CHECK_ANYORDER(s.combinationSum("[2]"_vi, 1), "[]"_vvi);
  return 0;
}
