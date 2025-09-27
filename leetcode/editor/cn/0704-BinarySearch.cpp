// 2025-09-27 15:00:08

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    int search(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (true) {
            int idx = (end - start) / 2 + start;
            if (end - start == 1 && nums[end] == target) {
                return end;
            }
            if (end - start == 1 && nums[start] == target) {
                return start;
            }
            if (nums[start] > target || nums[end] < target || end - start == 1) {
                return -1;
            }
            if (nums[idx] == target) {
                return idx;
            }
            if (nums[idx] > target) {
                end = idx;
            }
            else if (nums[idx] < target) {
                start = idx;
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    vector<int> v1 = {2, 5};
    vector<int> v2 = {-1, 0, 3, 5, 9, 12};
    cout << s.search(v1, 5) << endl; // 1
    cout << s.search(v2, 9) << endl; // 4
    cout << s.search(v2, 2) << endl; // -1
    return 0;
}
