// 2025-09-17 20:15:11

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    bool judgeCircle(string moves) {
        int h = 0;
        int v = 0;
        for (auto s : moves) {
            switch (s) {
                case 'L':
                    h++;
                    break;
                case 'R':
                    h--;
                    break;
                case 'U':
                    v++;
                    break;
                case 'D':
                    v--;
                    break;
            }
        }
        return h == 0 && v == 0;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << s.judgeCircle("UD") << s.judgeCircle("LL");
    return 0;
}
