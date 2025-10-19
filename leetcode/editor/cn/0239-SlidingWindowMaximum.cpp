// 2025-10-19 11:34:53

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int len = nums.size();
        vector<int> r;
        r.reserve(len - k + 1);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            pq.emplace(nums[i], i);
        }
        r.emplace_back(pq.top().first);
        for (int i = k; i < len; i++) {
            pq.emplace(nums[i], i);
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            r.emplace_back(pq.top().first);
        }
        return r;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << s.maxSlidingWindow(VEC(1, 3, -1, -3, 5, 3, 6, 7), 3) << endl; // 3, 3, 5, 5, 6, 7
    cout << s.maxSlidingWindow(VEC(7, 6, 3, 5, -3, -1, 3, 1), 3) << endl; // 7, 6, 5, 5, 3, 3
    cout << s.maxSlidingWindow(VEC(1, 2, 3, 4, 5, 6), 1) << endl;
    cout << s.maxSlidingWindow(VEC(6, 5, 4, 3, 2, 1), 1) << endl;
    cout << s.maxSlidingWindow(VEC(1), 1) << endl; // 1
    return 0;
}
