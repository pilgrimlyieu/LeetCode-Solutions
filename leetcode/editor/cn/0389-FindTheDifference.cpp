// 2025-09-12 22:54:32

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for (char c: s) {
            if (mp.find(c) == mp.end()) {
                mp[c] = 1;
            } else {
                mp[c]++;
            }
        }
        for (char c: t) {
            if (mp.find(c) == mp.end()) {
                return c;
            } else {
                mp[c]--;
            }
        }
        for (auto i: mp) {
            if (i.second == -1) {
                return i.first;
            }
        }
        return ' '; // impossible
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    
    return 0;
}