// 2025-09-19 22:51:07

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> mm;
        mm.assign(m, 0);
        vector<int> nn;
        nn.assign(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    mm[i] = 1;
                    nn[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mm[i] || nn[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;

    return 0;
}
