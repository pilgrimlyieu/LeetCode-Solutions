// 2025-09-17 19:58:53

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    string toLowerCase(string s) {
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
            }
        }
        return s;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;

    return 0;
}
