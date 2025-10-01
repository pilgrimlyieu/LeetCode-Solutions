// 2025-10-01 10:12:58

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int h = n;
        int w = n;
        int idx = 1;
        int x = 0;
        int y = 0;
        while (h > 0 && w > 0) {
            mat[x][y] = idx++;
            for (int i = 0; i < w - 1; i++) {
                mat[y][++x] = idx++;
            }
            for (int i = 0; i < h - 1; i++) {
                mat[++y][x] = idx++;
            }
            for (int i = 0; i < w - 1; i++) {
                mat[y][--x] = idx++;
            }
            for (int i = 0; i < w - 2; i++) {
                mat[--y][x] = idx++;
            }
            x++;
            h -= 2;
            w -= 2;
        }
        return mat;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    printMatrix(s.generateMatrix(1));
    printMatrix(s.generateMatrix(2));
    printMatrix(s.generateMatrix(3));
    printMatrix(s.generateMatrix(4));
    return 0;
}
