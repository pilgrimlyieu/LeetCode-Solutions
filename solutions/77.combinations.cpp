// @leet imports start
// Created: 2026-08-19 17:26:34

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp(k);
    iota(temp.begin(), temp.end(), 1);
    while (true) {
      while (temp.back() <= n) {
        ans.push_back(temp);
        temp.back()++;
      }
      int i = k - 1;
      while (i >= 0 && temp[i] >= n - k + 1 + i) {
        i--;
      }
      if (i < 0) {
        break;
      }
      iota(temp.begin() + i, temp.end(), temp[i] + 1);
    }
    return ans;
  }
};
// @leet end

// @card idea
// 跟手动列出所有组合方式一致，最后一位进到最大位后，向前回溯找到可以进位的位置并递增。使用了 `iota` 函数简化进位后的重置步骤。空间复杂度 $O(k)$。
//
// 也可以考虑正着来，在 `temp` 末尾加一个哨兵值 `n+1`，并寻找 `temp` 第一个不连续递增的点将它递增，这样一样可以扫过全部组合。且寻找递增点的时候还可以顺带将旧的位置重置，无需像这里的解法必须找到回溯点再确定重置。

// @alt 递归回溯
// 时间复杂度都是 $O(\biome{n}{k} \times k)$，空间复杂度是 $O(n + k) = O(n)$，额外付出了调用栈空间的代价。
//
// 这样思考递归回溯：
// 1. 若满足终止条件则剪枝终止；
// 2. 对于所有可选元素（此时）：
//     1. 考虑当前元素
//     2. 递归
//     3. 不考虑当前元素，回溯
class SolutionRecursion {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    auto backtrace = [&](this auto &&self, int i) {
      if (temp.size() + (n - i + 1) < k) { // 后面全加上也无法匹配
        return;
      }
      if (temp.size() == k) { // 满了，是一个合适的组合
        ans.push_back(temp);
        return;
      }
      temp.push_back(i); // 考虑 i
      self(i + 1);
      temp.pop_back(); // 不考虑 i
      self(i + 1);
    };
    backtrace(1);
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  DBG(s.combine(5, 3));
  CHECK_ANYORDER(s.combine(4, 2), "[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]"_vvi);
  CHECK(s.combine(1, 1), "[[1]]"_vvi);
  CHECK(s.combine(3, 3), "[[1,2,3]]"_vvi);
  return 0;
}
