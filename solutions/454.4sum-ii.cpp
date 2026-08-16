// @leet imports start
// Created: 2025-10-08 11:08:01

#include "../utils.h"
#include <unordered_map>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (auto n1 : nums1) {
      for (auto n2 : nums2) {
        mp[n1 + n2]++;
      }
    }
    for (auto n3 : nums3) {
      for (auto n4 : nums4) {
        auto it = mp.find(-n3 - n4);
        if (it != mp.end()) {
          ans += it->second;
        }
        // 可以直接 ans += mp[-n3 - n4]，不过依赖非直觉行为，谨慎使用
      }
    }
    return ans;
  }
};
// @leet end

// @card idea
// 四个数组就拆成 $2 \times 2$，可以以 $O(n^2)$ 时间复杂度完成。

// @card note
// `unordered_map` 的 `[]` 运算符行为是访问或插入，若元素不存在则插入默认构造器（`0`, `""` 等）。

int main(void) {
  Solution s;
  CHECK(s.fourSumCount("[1,2]"_vi, "[-2,-1]"_vi, "[-1,2]"_vi, "[0,2]"_vi), 2);
  CHECK(s.fourSumCount("[0]"_vi, "[0]"_vi, "[0]"_vi, "[0]"_vi), 1);
  CHECK(s.fourSumCount("[0,1]"_vi, "[0,-1]"_vi, "[0]"_vi, "[0]"_vi), 2);
  return 0;
}
