// 2025-10-08 10:41:07

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        res.reserve(1000);
        unordered_map<int, int> mp;
        for (auto i: nums1) {
            mp[i] = 0;
        }
        for (auto i: nums2) {
            if (mp.find(i) != mp.end()) {
                mp[i] = 1;
            }
        }
        for (auto p: mp) {
            if (p.second == 1) {
                res.emplace_back(p.first);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    
    return 0;
}