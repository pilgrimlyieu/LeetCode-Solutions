// 2025-10-19 11:22:12

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    bool isnumber(string s) {
        int len = s.size();
        if (len < 1)
            return false;
        if (isdigit(s[0]) || (s[0] == '-' && len >= 2)) {
            for (int i = 1; i < len; i++) {
                if (!isdigit(s[i]))
                    return false;
            }
            return true;
        }
        return false;
    }

    public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (auto token : tokens) {
            if (isnumber(token)) {
                stk.push(stoi(token));
            }
            else {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int res;
                if (token == "+") {
                    res = a + b;
                } else if (token == "-") {
                    res = b - a;
                } else if (token == "*") {
                    res = a * b;
                } else if (token == "/") {
                    res = b / a;
                }
                stk.push(res);
            }
        }
        return stk.top();
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;

    return 0;
}
