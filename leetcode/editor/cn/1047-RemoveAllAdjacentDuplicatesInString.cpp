// 2025-10-19 11:13:06

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    string removeDuplicates(string s) {
        int len = s.size();
        string res;
        res.reserve(len);
        int idx = 0;
        for (int i = 0; i < len; i++) {
            if (!res.empty() && s[i] == res[idx - 1]) {
                res.pop_back();
                idx--;
                continue;
            }
            res.push_back(s[i]);
            idx++;
        }
        return res;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << s.removeDuplicates("abbaca") << endl;
    cout << s.removeDuplicates("azxxzy") << endl;
    return 0;
}
