// @leet imports start
// Created: 2025-10-08 10:41:07

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> bkt(nums1.begin(), nums1.end());
    vector<int> ans;
    ans.reserve(min(nums1.size(), nums2.size()));
    for (auto n : nums2) {
      if (bkt.erase(n)) {
        ans.push_back(n);
      }
    }
    return ans;
  }
};
// @leet end

// @card note
// 主要注意 `unordered_set` 等容器可以直接从 `vector` 等容器初始化而来，同时 `erase` 函数可同时用来检测与移除（这是简写，实际上为了清晰可以分开）。

int main(void) {
  Solution s;

  return 0;
}
