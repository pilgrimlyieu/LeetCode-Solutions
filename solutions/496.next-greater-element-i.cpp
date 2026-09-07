// @leet imports start
// Created: 2026-09-07 14:25:13

#include "../utils.h"
#include <unordered_map>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> ans(n1, -1), stk;
    unordered_map<int, int> mp;
    for (int i = 0; i < n2; i++) {
      while (!stk.empty() && nums2[i] > stk.back()) {
        mp[stk.back()] = nums2[i];
        stk.pop_back();
      }
      stk.push_back(nums2[i]);
    }
    for (int i = 0; i < n1; i++) {
      ans[i] = (mp.find(nums1[i]) == mp.end()) ? -1 : mp[nums1[i]];
    }
    return ans;
  }
};
// @leet end

int main() {
  Solution s;
  CHECK(s.nextGreaterElement("[4,1,2]"_vi, "[1,3,4,2]"_vi), "[-1,3,-1]"_vi);
  CHECK(s.nextGreaterElement("[2,4]"_vi, "[1,2,3,4]"_vi), "[3,-1]"_vi);
  return 0;
}
