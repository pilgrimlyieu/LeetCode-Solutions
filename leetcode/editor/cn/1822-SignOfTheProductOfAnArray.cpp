// 2025-09-14 11:06:37

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int signFunc(int x) {
        if (x > 0) {
            return 1;
        } else {
            return -1;
        }
    }
    int arraySign(vector<int>& nums) {
        int result = 1;
        for (int n : nums) {
            if (n == 0) {
                return 0;
            } else {
                result *= signFunc(n);
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    
    return 0;
}