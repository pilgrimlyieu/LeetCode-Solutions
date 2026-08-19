// @leet imports start
// Created: 2026-08-22 15:25:47

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> ans;
    auto dfs = [&](this auto &&self, int idx) {
      if (idx == size) {
        ans.push_back(nums);
        return;
      }
      bool used[22] = {false};
      for (int i = idx; i < size; i++) {
        if (used[nums[i] + 10]) {
          continue;
        }
        swap(nums[idx], nums[i]);
        self(idx + 1);
        swap(nums[idx], nums[i]);
        used[nums[i] + 10] = true;
      }
    };
    dfs(0);
    return ans;
  }
};
// @leet end

// @card idea
// 以 46. 普通全排列分左右两区交换法为基础，每一层遍历的时候，重复元素仅在第一次的时候考虑。因为数据规模很小，这里直接使用了数组标记。
//
// 也可以将 `nums` 排序并额外使用一个数组 `visited` 记录访问情况，不过这样每一层都需要遍历全部元素。

int main() {
  Solution s;
  // 题面允许任意顺序，必要时改用 CHECK_ANYORDER
  DBG(s.permuteUnique("[0,1,0,2]"_vi));
  CHECK_ANYORDER(s.permuteUnique("[1,1,2]"_vi),
                 "[[1,1,2],[1,2,1],[2,1,1]]"_vvi);
  CHECK_ANYORDER(s.permuteUnique("[1,2,3]"_vi),
                 "[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]"_vvi);
  CHECK_ANYORDER(
      s.permuteUnique("[2,2,1,1]"_vi),
      "[[1,1,2,2],[1,2,1,2],[1,2,2,1],[2,1,1,2],[2,1,2,1],[2,2,1,1]]"_vvi);
  CHECK_ANYORDER(
      s.permuteUnique("[0,1,0,0,9]"_vi),
      "[[0,0,0,1,9],[0,0,0,9,1],[0,0,1,0,9],[0,0,1,9,0],[0,0,9,0,1],[0,0,9,1,0],[0,1,0,0,9],[0,1,0,9,0],[0,1,9,0,0],[0,9,0,0,1],[0,9,0,1,0],[0,9,1,0,0],[1,0,0,0,9],[1,0,0,9,0],[1,0,9,0,0],[1,9,0,0,0],[9,0,0,0,1],[9,0,0,1,0],[9,0,1,0,0],[9,1,0,0,0]]"_vvi);
  return 0;
}
