// 2025-09-21 11:01:06

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    double myPow(double x, int n) {
        double result = 1;
        if (x == 1.0) {
            return x;
        }
        long long nn = abs((long long)n);
        if (n < 0) {
            x = 1.0 / x;
        }
        if (x == -1.0) {
            return (n % 2 == 0) ? 1.0 : -1.0;
        }
        for (long long i = 0; i < nn; i++) {
            result *= x;
            if (result == 0.0) {
                return 0.0;
            }
        }
        return result;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << s.myPow(2.0, -2147483648) << endl;
    return 0;
}
