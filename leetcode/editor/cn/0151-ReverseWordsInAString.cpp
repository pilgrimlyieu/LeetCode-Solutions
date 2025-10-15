// 2025-10-15 10:23:30

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    string reverseWords(string s) {
        int len = s.size();
        string res;
        res.reserve(len);
        int p1 = len - 1;
        int p2 = p1;
        while (p2 >= 0) {
            while (p1 >= 0 && s[p1] == ' ') {
                p1--;
            }
            p2 = p1;
            while (p2 >= 0 && s[p2] != ' ' ) {
                p2--;
            }
            if (p2 < p1) {
                for (int i = p2 + 1; i <= p1; i++) {
                    res.push_back(s[i]);
                }
                res.push_back(' ');
            }
            p1 = p2;
        }
        res.pop_back(); // 至少要有一个单词
        return res;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << s.reverseWords("a") << '|' << endl;
    cout << s.reverseWords(" abc ") << '|' << endl;
    cout << s.reverseWords(" abc") << '|' << endl;
    cout << s.reverseWords("abc ") << '|' << endl;
    cout << s.reverseWords("abc    def") << '|' << endl;
    cout << s.reverseWords("   abc   def  ") << '|' << endl;
    cout << s.reverseWords("the sky is blue") << '|' << endl;
    cout << s.reverseWords("  hello world  ") << '|' << endl;
    cout << s.reverseWords("a good   example") << '|' << endl;
    return 0;
}
