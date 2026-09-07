// @leet imports start
// Created: 2026-09-07 14:05:04

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> stk, ans(n);
    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && temperatures[stk.back()] <= temperatures[i]) {
        stk.pop_back();
      }
      ans[i] = stk.empty() ? 0 : stk.back() - i;
      stk.push_back(i);
    }
    return ans;
  }
};
// @leet end

// @card idea 从右往左
// 栈中保存<u>当前位置右边已经处理过的下标</u>，满足栈中温度从底到顶严格递减。每次弹出所有**不严格大于**当前温度的元素，因为不可能作为后面的答案了。

// @alt 从左往右
// 栈中保存<u>还没找到更高温度的下标</u>，不断更新栈顶。
class SolutionL2R {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> stk, ans(n);
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && temperatures[stk.back()] < temperatures[i]) {
        int prev = stk.back();
        stk.pop_back();
        ans[prev] = i - prev;
      }
      stk.push_back(i);
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.dailyTemperatures("[73,74,75,71,69,72,76,73]"_vi),
        "[1,1,4,2,1,1,0,0]"_vi);
  CHECK(s.dailyTemperatures("[30,40,50,60]"_vi), "[1,1,1,0]"_vi);
  CHECK(s.dailyTemperatures("[30,60,90]"_vi), "[1,1,0]"_vi);
  return 0;
}
