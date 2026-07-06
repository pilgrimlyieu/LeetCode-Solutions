// @leet imports start
// Created: 2025-10-08 11:33:31

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    unordered_map<int, int> mp;
    for (auto n : nums) {
      if (mp.find(n) == mp.end()) {
        mp[n] = 1;
      } else {
        mp[n]++;
      }
    }
    for (auto p1 : mp) {
      for (auto p2 : mp) {
        if (p2.first < p1.first) {
          continue;
        }
        if (p1.first != p2.first || p1.second >= 2) {
          auto fd = mp.find(-p1.first - p2.first);
          if (fd == mp.end() || fd != mp.end() && fd->first < p2.first) {
            continue;
          }
          if ((p1.first == p2.first && p2.first == fd->first &&
               p1.second >= 3) ||
              (p1.first == fd->first && p2.first != fd->first &&
               p1.second >= 2) ||
              (p2.first == fd->first && p1.first != fd->first &&
               p2.second >= 2) ||
              (p1.first != fd->first && p2.first != fd->first)) {
            vector<int> resa = {p1.first, p2.first, fd->first};
            res.emplace_back(resa);
          }
        }
      }
    }
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  // cout << s.threeSum("[-1,0,1,2,-1,-4]"_vi) << endl;
  // cout << s.threeSum("[0,1,1]"_vi) << endl;
  cout << s.threeSum("[0,0,1,-1]"_vi) << endl;
  // cout << s.threeSum("[0,0,0]"_vi) << endl;
  return 0;
}
