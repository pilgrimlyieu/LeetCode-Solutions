// @leet imports start
// Created: 2026-08-22 15:01:34

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> ans;
    auto dfs = [&](this auto &&self, int idx) -> void {
      if (idx == size) {
        ans.push_back(nums);
        return;
      }
      for (int i = idx; i < size; i++) {
        swap(nums[idx], nums[i]);
        self(idx + 1);
        swap(nums[idx], nums[i]);
      }
    };
    dfs(0);
    return ans;
  }
};
// @leet end

// @card idea 交换
// 使用 `idx` 标记已经选好的部分，同时也是排列中下一个要确定的数的下标，自然后面就是待选项，交换即可。无需额外空间。
//
// 以及还是要理解变量含义，`self(idx + 1)` 最初写成了 `self(i + 1)` 一直没发现问题。

// @alt 朴素回溯
// 使用 `unordered_set` 记录是否使用，需要额外空间与检查。
class SolutionSimple {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> ans;
    vector<int> temp(size);
    unordered_set<int> unused(nums.begin(), nums.end());
    int l = 0;
    auto dfs = [&](this auto &&self) -> void {
      if (l == size) {
        ans.push_back(temp);
        return;
      }
      for (int i = 0; i < size; i++) {
        if (!unused.contains(nums[i])) {
          continue;
        }
        temp[l++] = nums[i];
        unused.erase(nums[i]);
        self();
        l--;
        unused.insert(nums[i]);
      }
    };
    dfs();
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  // 题面允许任意顺序，必要时改用 CHECK_ANYORDER
  CHECK_ANYORDER(s.permute("[1,2,3]"_vi),
                 "[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]"_vvi);
  CHECK_ANYORDER(s.permute("[0,1]"_vi), "[[0,1],[1,0]]"_vvi);
  CHECK_ANYORDER(s.permute("[1]"_vi), "[[1]]"_vvi);
  return 0;
}
