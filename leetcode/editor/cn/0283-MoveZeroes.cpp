// 2025-09-12 23:26:55

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    int swap_zero(vector<int> &nums, int idx1, int idx2) {
        int temp = nums[idx2];
        nums[idx2] = nums[idx1];
        nums[idx1] = temp;
        return temp;
    }

    void moveZeroes(vector<int> &nums) {
        int len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] != 0) {
                continue;
            }
            int index = i + 1;
            for (; index < len; index++) {
                if (nums[index] != 0) {
                    break;
                }
            }
            if (index == len) { // if this happens, the task has been done before.
                return;
            }
            swap_zero(nums, i, index);
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    vector<int> v = {0, 1, 0, 3, 12};
    s.moveZeroes(v);
    return 0;
}
