// 2025-10-22 10:44:29

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        int len = nums.size();
        vector<int> res;
        res.reserve(k);
        priority_queue<pair<int, int>> pq;
        while (idx < len) {
            int cur = idx;
            while (idx < len && nums[idx] == nums[cur]) {
                idx++;
            }
            pq.emplace(idx - cur, nums[cur]);
        }
        for (int i = 0; i < k; i++) {
            res.emplace_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << s.topKFrequent(VEC(1, 1, 2, 3, 4, 5, 5), 2) << endl;
    return 0;
}
