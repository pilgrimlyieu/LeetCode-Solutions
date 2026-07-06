// @leet imports start
// Created: 2025-09-10 17:49:33

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> table;
    for (int i = 0; i < nums.size(); i++) {
      auto result = table.find(target - nums[i]);
      if (result != table.end()) {
        return {result->second, i};
      }
      table[nums[i]] = i;
    }
    return {};
  }
};
// @leet end

int main(void) {
  Solution s;
  vector<int> t1 = {1, 2};
  s.twoSum(t1, 3);
  return 0;
}
