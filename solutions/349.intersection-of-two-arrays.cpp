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

int main(void) {
  Solution s;

  return 0;
}
