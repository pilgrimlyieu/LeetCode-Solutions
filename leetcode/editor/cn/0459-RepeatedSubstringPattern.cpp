// 2025-09-12 23:19:21

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        size_t len = s.length();
        for (size_t i = 0; i < len / 2; i++) {
            if (len % (i + 1) != 0) {
                continue;
            }
            for (int t = 0; t < len / (i + 1); t++) {
                for (int idx = 0; idx < i + 1; idx++) {
                    if (s[idx] != s[t * (i + 1) + idx]) {
                        goto fail;
                    }
                }
            }
            return true;
            fail:
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    
    return 0;
}