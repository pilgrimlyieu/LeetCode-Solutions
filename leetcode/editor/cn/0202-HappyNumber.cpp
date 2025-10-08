// 2025-10-08 10:49:17

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    bool isHappy(int n) {
        int res = n;
        while (res >= 10) {
            int out = 0;
            while (res != 0) {
                out += (res % 10) * (res % 10);
                res /= 10;
            }
            res = out;
        }
        return res == 1 || res == 7;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;

    return 0;
}
