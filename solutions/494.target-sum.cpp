// @leet imports start
// Created: 2026-08-28 19:00:52

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int dp1_arr[2001] = {0};
    int dp2_arr[2001] = {0};
    int *dp_old = dp1_arr;
    int *dp_new = dp2_arr;
    auto get = [&](int i) -> int & {
      static int dummy = 0;
      return (i >= -1000 && i <= 1000) ? dp_old[i + 1000] : dummy = 0;
    };
    get(0) = 1;
    for (int prefixSum = 0; auto n : nums) {
      prefixSum += n;
      for (int i = -prefixSum; i <= prefixSum; i++) {
        dp_new[1000 + i] = get(i - n) + get(i + n);
      }
      swap(dp_old, dp_new);
    }
    return get(target);
  }
};
// @leet end

// @alt 子集和
// 考虑正数总和和负数（绝对值）总和分别为 `P`, `N`，则 `P - N = target`, `P + N = sum`，由此 `P = (target + sum) / 2`，转换为 0-1 背包问题。不过需要两次遍历，同时动态开数组。
class SolutionSum {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = reduce(nums.begin(), nums.end());
    if (abs(target) > sum || (sum + target) % 2 != 0) {
      return 0;
    }
    int bag = (sum + target) / 2;
    vector<int> dp(bag + 1, 0);
    dp[0] = 1;
    for (auto n : nums) {
      for (int i = bag; i >= n; i--) {
        dp[i] += dp[i - n];
      }
    }
    return dp.back();
  }
};
// @alt end

// @card note
// 解法 1 为了仅使用一遍遍历进行了一些优化，同时使用了一些新的写法，主要是为了长见识：
// 1. 由于更新方向不确定，滚动数组也需要保留新旧。更新一层的时候可以用 `copy(begin(src), end(src), begin(dest))`；
// 2. 但实际上只用交换即可，这里用 `int *p = arr;` 获取了指针，并交换指针。若是动态扩容的向量，则使用 `vector<int>* p = &v;`；
// 3. 不可以直接 `swap(arr1, arr2)`，其对数组的实现是逐元素交换，必须获取指针进行交换（指针初始化特地分开写）；
// 4. 每次更新的范围在前缀和的区间内，使用基于范围的 for 循环初始化语句（C++20）；
// 5. 包装器 `get` 同时处理边界与偏移的情况，让代码更清晰。为了允许赋值，传递的是引用，同时提供了静态默认值的引用；
// 6. 因为是引用，所以要谨慎考虑使用过程中被修改的情况，表达式其他地方也会同时更新，可能会有意料之外的效果！
// 7. 要在 `dp_new` 更新，这时候不能用 `get`。这里只是为了展示更多写法才这样写，实际上这样写反而混乱，还是只传值更合适。

int main() {
  Solution s;
  CHECK(s.findTargetSumWays("[1,1,1,1,1]"_vi, 3), 5);
  CHECK(s.findTargetSumWays("[1]"_vi, 1), 1);
  return 0;
}
