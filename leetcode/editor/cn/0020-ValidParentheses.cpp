// 2025-10-19 11:05:52

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c: s) {
            if (stk.empty()) {
                stk.push(c);
            } else {
                char top = stk.top();
                if (c == ')' && top == '(') {
                    stk.pop();
                } else if (c == '}' && top == '{') {
                    stk.pop();
                } else if (c == ']' && top == '[') {
                    stk.pop();
                } else {
                    stk.push(c);
                }
            }
        }
        return stk.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;

    return 0;
}