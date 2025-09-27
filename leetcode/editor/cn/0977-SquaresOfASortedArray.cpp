// 2025-09-27 15:41:49

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    vector<int> sortedSquares(vector<int> &nums) {
        int len = nums.size();
        vector<int> res;
        res.reserve(len);
        int fir = 0;
        while (fir < len && nums[fir] < 0) {
            fir++;
        }
        int sec = fir;
        fir--;
        while (fir >= 0 && sec < len) {
            if (abs(nums[fir]) > abs(nums[sec])) {
                res.push_back(nums[sec] * nums[sec]);
                sec++;
            }
            else {
                res.push_back(nums[fir] * nums[fir]);
                fir--;
            }
        }
        while (fir >= 0) {
            res.push_back(nums[fir] * nums[fir]);
            fir--;
        }
        while (sec < len) {
            res.push_back(nums[sec] * nums[sec]);
            sec++;
        }
        return res;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    vector<int> v1 = {-1};
    printVector(s.sortedSquares(v1)); // [1]
    vector<int> v2 = {1};
    printVector(s.sortedSquares(v2)); // [1]
    vector<int> v3 = {-1, 2, 2};
    printVector(s.sortedSquares(v3)); // [1, 4, 4]
    return 0;
}
