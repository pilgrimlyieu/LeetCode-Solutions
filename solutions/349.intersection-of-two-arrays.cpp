// @leet imports start
// Created: 2025-10-08 10:41:07

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    res.reserve(1000);
    unordered_map<int, int> mp;
    for (auto i : nums1) {
      mp[i] = 0;
    }
    for (auto i : nums2) {
      if (mp.find(i) != mp.end()) {
        mp[i] = 1;
      }
    }
    for (auto p : mp) {
      if (p.second == 1) {
        res.emplace_back(p.first);
      }
    }
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
