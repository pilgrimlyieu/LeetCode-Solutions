// 2025-09-14 11:49:48

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int idx1 = -1;
        int idx2 = -1;
        for (int i = len - 1; i >= 0; i--) {
            if (idx1 == -1) {
                if (s[i] != ' ') {
                    idx1 = i;
                }
                continue;
            }
            if (s[i] == ' ') {
                idx2 = i;
                break;
            }
        }
        return idx1 - idx2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    
    return 0;
}