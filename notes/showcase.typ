#import "lib.typ": *

#show: note.with(
  id: "239",
  title: "滑动窗口最大值",
  slug: "sliding-window-maximum",
  difficulty: "Hard",
  date: "2026-07-07",
  tags: ("单调队列", "滑动窗口", "堆"),
)

= 题意

给定数组 `nums` 和窗口大小 $k$，窗口从最左侧滑到最右侧，每次右移一位，返回每个窗口内的*最大值*。

#quote(block: true)[
  输入：`nums = [1,3,-1,-3,5,3,6,7]`，`k = 3`\
  输出：`[3,3,5,5,6,7]`
]

= 思路

维护一个*单调递减队列*，队首恒为当前窗口最大值：

+ 新元素入队前，从队尾弹出所有比它小的元素——它们在新元素在场时永远不可能成为最大值；
+ 队首元素滑出窗口范围（下标 $<= i - k$）时从队首弹出；
+ 每步取队首即答案。

每个元素至多入队、出队各一次，整体 $O(n)$。对比堆解法 $O(n log n)$：堆里留着过期元素，取最大值时才惰性清理。

#tip[
  单调队列的本质：*淘汰永远不可能成为答案的候选*。队列里剩下的是「按下标递增、按值递减」的候选序列。
]

= 复杂度

#complexity(time: $O(n)$, space: $O(k)$)
#complexity(time: $O(n)$)
#complexity(space: $O(k)$)

= 代码要点

存下标而非值，方便判断队首是否过期：

```cpp
deque<int> dq; // 存下标，对应值单调递减
vector<int> res;
for (int i = 0; i < nums.size(); i++) {
    while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() <= i - k) dq.pop_front();
    if (i >= k - 1) res.push_back(nums[dq.front()]);
}
```

本地验证用 `CHECK` 宏（见 #link("https://github.com/pilgrimlyieu/LeetCode-Solutions")[仓库] `utils.h`）：

```cpp
CHECK(s.maxSlidingWindow("[1,3,-1,-3,5,3,6,7]"_vi, 3), "[3,3,5,5,6,7]"_vi);
```

= 坑点与总结

#pitfall[
  弹队尾的条件写 `<=` 而非 `<`：相等元素留旧不留新会导致旧元素过期时误判窗口最大值仍在。
]

#variant[
  求窗口*最小值*只需翻转比较方向；二维滑窗（LC 1696）同款思路先行后列各做一遍。
]

#takeaway[
  「窗口 + 极值」的组合优先想单调队列；若还需要*第 $k$ 大*或*中位数*，才升级到堆 / 平衡树（multiset）。
]
