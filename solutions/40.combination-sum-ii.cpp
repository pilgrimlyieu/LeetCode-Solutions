// @leet imports start
// Created: 2026-08-19 22:43:27

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    auto backtrace = [&](this auto &&self, int start) {
      if (sum >= target) {
        if (sum == target) {
          ans.push_back(temp);
        }
        return;
      }
      for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) {
          continue;
        }
        temp.push_back(candidates[i]);
        sum += candidates[i];
        self(i + 1);
        temp.pop_back();
        sum -= candidates[i];
      }
    };
    backtrace(0);
    return ans;
  }
};
// @leet end

// @card idea 循环枚举式
// 都需要对 `candidates` 先排序，并使用一些方式判断重复。如循环枚举式对同一个侯选位置排除相同元素，而选/不选子集型则禁止选择先前没有选过的相同元素（这样包含重复选择的路径一定会在一开始连续选取，排除重复）。
//
// 对于本题还可以统计不同数字出现频率，然后按数字来枚举选择多少个，且可以很容易扩展为「每个元素可以选择有限次」问题。

// @alt 子集型
// 使用一个变量 `used` 标记上一个元素是否被采用，当且仅当上一个元素被采用（即允许同种元素多次出现），或虽然上一个没用但新元素不同时可以采用。这样对于相同元素的采用情况会是字典序。
class SolutionSubset {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    auto backtrace = [&](this auto &&self, int i, bool used) {
      if (i == candidates.size() || sum >= target) {
        if (sum == target) {
          ans.push_back(temp);
        }
        return;
      }
      if (used || i == 0 || candidates[i] != candidates[i - 1]) {
        temp.push_back(candidates[i]);
        sum += candidates[i];
        self(i + 1, true);
        temp.pop_back();
        sum -= candidates[i];
      }
      self(i + 1, false);
    };
    backtrace(0, false);
    return ans;
  }
};
// @alt end

// @card note
// **循环枚举式**思考当前位置可以放什么元素。每层递归填充组合的一个位置，循环枚举该位置可以放哪些元素。决策树是一棵多叉树。
// - 核心参数 `start`：当前层允许从候选哪个下标开始选择。
//
// ```cpp
// vector<vector<int>> solve(/* 参数 */) {
//   vector<vector<int>> ans;
//   vector<int> path;
//   auto backtrack = [&](this auto &&self, /* 参数 */) {
//     if (/* 终止条件 */) {
//       ans.push_back(path);
//       return;
//     }
//
//     for (/* 遍历当前可选列表 */) {
//       /* 剪枝 */
//       path.push_back(/* 选择并进入下一层 */);
//       self(/* 新参数 */);
//       path.pop_back(); /* 撤销选择，继续在本层挑选候选 */
//     }
//   };
//   backtrack(/* 初始参数 */);
//   return ans;
// }
// ```
//
// **子集选/不选型**思考每个候选元素，是否要加入组合。决策树是一棵二叉树。
// - 核心参数 `idx`：当前正在考虑的候选元素下标。
//
// ```cpp
// vector<vector<int>> solve(/* 参数 */) {
//   vector<vector<int>> ans;
//   vector<int> path;
//   auto backtrack = [&](this auto &&self, /* 参数 */) {
//     if (/* 终止条件 */) {
//       ans.push_back(path);
//       return;
//     }
//     /* 剪枝 */
//
//     path.push_back(/* 选择 */);
//     self(/* 新参数 */); // 选
//     path.pop_back(); /* 撤销选择 */
//     self(/* 新参数 */) // 不选
//   };
//   backtrack(/* 初始参数 */);
//   return ans;
// }
// ```

int main() {
  Solution s;
  CHECK_ANYORDER(s.combinationSum2("[10,1,2,7,6,1,5]"_vi, 8),
                 "[[1,1,6],[1,2,5],[1,7],[2,6]]"_vvi);
  CHECK_ANYORDER(s.combinationSum2("[2,5,2,1,2]"_vi, 5), "[[1,2,2],[5]]"_vvi);
  return 0;
}
