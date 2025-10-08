// 2025-10-08 11:33:31

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        for (auto n : nums) {
            if (mp.find(n) == mp.end()) {
                mp[n] = 1;
            }
            else {
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
                    if ((p1.first == p2.first && p2.first == fd->first && p1.second >= 3) ||
                        (p1.first == fd->first && p2.first != fd->first && p1.second >= 2) ||
                        (p2.first == fd->first && p1.first != fd->first && p2.second >= 2) ||
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
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    // printMatrix(s.threeSum(VEC(-1, 0, 1, 2, -1, -4)));
    // printMatrix(s.threeSum(VEC(0, 1, 1)));
    printMatrix(s.threeSum(VEC(0, 0, 1, -1)));
    // printMatrix(s.threeSum(VEC(0, 0, 0)));
    return 0;
}
