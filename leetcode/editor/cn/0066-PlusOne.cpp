// 2025-09-14 10:57:51

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            int result = digits[i] + 1;
            if (result < 10) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    vector<int> v = {9, 9, 9};
    printVector(s.plusOne(v));
    return 0;
}
