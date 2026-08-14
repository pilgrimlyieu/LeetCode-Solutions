// @leet imports start
// Created: 2025-09-10 17:49:33

#include "../utils.h"
#include <unordered_map>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
      auto it = mp.find(target - nums[i]);
      if (it != mp.end()) {
        return {it->second, i};
      }
      mp[nums[i]] = i;
    }
    return {};
    // __builtin_unreachable(); // GCC/Clang
  }
};
// @leet end

int main(void) {
  Solution s;
  CHECK(s.twoSum("[1,2]"_vi, 3), "[0,1]"_vi);
  CHECK(s.twoSum("[2,2,1]"_vi, 4), "[0,1]"_vi);
  return 0;
}
