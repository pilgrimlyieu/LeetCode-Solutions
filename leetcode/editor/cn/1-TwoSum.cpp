// 2025-09-10 17:49:33

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
//leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    vector<int> t1 = {1, 2};
    s.twoSum(t1, 3);
    return 0;
}