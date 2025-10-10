// 2025-10-10 11:12:15

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    string reverseStr(string s, int k) {
        int len = s.length();
        string ans = s;
        int t = 0;
        for (; t < len / k; t++) {
            if (t % 2 == 0) {
                int idx = t * k;
                for (int i = 0; i < k / 2; i++) {
                    swap(ans[idx + i], ans[idx + k - 1 - i]);
                }
            }
        }
        if (t % 2 == 0) {
            int idx = t * k;
            for (int i = 0; i < (len - idx) / 2; i++) {
                swap(ans[idx + i], ans[len - 1 - i]);
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << s.reverseStr("1234", 2) << endl;
    cout << s.reverseStr("123456", 2) << endl;
    cout << s.reverseStr("12345678", 2) << endl;
    cout << s.reverseStr("1234567", 8) << endl;
    return 0;
}
