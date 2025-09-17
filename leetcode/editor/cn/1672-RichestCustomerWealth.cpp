// 2025-09-17 21:17:53

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sumVec(vector<int>& vec) {
        int sum = 0;
        for (auto i : vec) {
            sum += i;
        }
        return sum;
    }

    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (auto v: accounts) {
            int now;
            if ((now = sumVec(v)) > max) {
                max = now;
            }
        }
        return max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    
    return 0;
}