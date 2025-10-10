// 2025-10-10 10:24:35

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int fir = 0; fir < len; fir++) {
            if (fir > 0 && nums[fir] == nums[fir - 1]) {
                continue;
            }
            for (int sec = fir + 1; sec < len; sec++) {
                if (sec > fir + 1 && nums[sec] == nums[sec - 1]) {
                    continue;
                }
                int fot = len - 1;
                long long aim = (long long)target - nums[fir] - nums[sec];
                for (int thi = sec + 1; thi < len; thi++) {
                    if (thi > sec + 1 && nums[thi] == nums[thi - 1]) {
                        continue;
                    }
                    while (thi < fot && (long long)nums[thi] + nums[fot] > aim) {
                        fot--;
                    }
                    if (thi == fot) {
                        break;
                    }
                    if ((long long)nums[thi] + nums[fot] == aim) {
                        ans.push_back({nums[fir], nums[sec], nums[thi], nums[fot]});
                    }
                }
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << s.fourSum(VEC(1, 0, -1, 0, -2, 2), 0) << endl;
    cout << s.fourSum(VEC(2, 2, 2, 2, 2), 8) << endl;
    cout << s.fourSum(VEC(1000000000, 1000000000, 1000000000, 1000000000), -294967296) << endl;
    return 0;
}
