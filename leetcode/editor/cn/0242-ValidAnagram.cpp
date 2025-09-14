// 2025-09-12 23:16:19

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for (auto c: s) {
            if (mp.find(c) == mp.end()) {
                mp[c] = 1;
            } else {
                mp[c]++;
            }
        }
        for (auto c: t) {
            if (mp.find(c) == mp.end()) {
                return false;
            } else {
                mp[c]--;
            }
        }
        for (auto i: mp) {
            if (i.second != 0) {
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    
    return 0;
}