// 2025-10-08 11:08:01

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        unordered_map<int, int> mp3;
        unordered_map<int, int> mp4;
        auto initf = [&](unordered_map<int, int> &mp, vector<int> &nums) {
            for (auto i : nums) {
                if (mp.find(i) == mp.end()) {
                    mp[i] = 1;
                }
                else {
                    mp[i]++;
                }
            }
        };
        initf(mp1, nums1);
        initf(mp2, nums2);
        initf(mp3, nums3);
        initf(mp4, nums4);
        int res = 0;
        for (auto p1 : mp1) {
            for (auto p2 : mp2) {
                for (auto p3 : mp3) {
                    auto p4f = mp4.find(-p1.first - p2.first - p3.first);
                    if (p4f != mp4.end()) {
                        res += p1.second * p2.second * p3.second * p4f->second;
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
    cout << s.fourSumCount(VEC(1, 2), VEC(-2, -1), VEC(-1, 2), VEC(0, 2)) << endl;
    cout << s.fourSumCount(VEC(0), VEC(0), VEC(0), VEC(0)) << endl;
    cout << s.fourSumCount(VEC(0, 1), VEC(0, -1), VEC(0), VEC(0)) << endl;
    return 0;
}
