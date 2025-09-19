// 2025-09-19 23:07:50

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    double average(vector<int> &salary) {
        int max = 1000;
        int min = 1000000;
        int sum = 0; // 范围应该没超
        int len = salary.size();
        for (auto sal : salary) {
            if (sal > max) {
                max = sal;
            }
            if (sal < min) { // 神经 else
                min = sal;
            }
            sum += sal;
        }
        // cout << sum << endl;
        // cout << max << endl;
        // cout << min << endl;
        sum -= max + min;
        return (double)sum / (len - 2);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    vector<int> v = {2000,   375000, 349000, 9000,   335000, 423000, 428000, 484000, 482000, 145000,
                     328000, 72000,  470000, 275000, 55000,  448000, 182000, 128000, 475000, 368000,
                     469000, 268000, 265000, 397000, 323000, 245000, 173000, 460000, 183000, 404000,
                     123000, 248000, 295000, 4000,   27000,  281000, 413000, 218000};
    s.average(v);
    return 0;
}
