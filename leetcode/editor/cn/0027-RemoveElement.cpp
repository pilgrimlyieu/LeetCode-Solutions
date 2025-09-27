// 2025-09-27 15:15:47

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0] == val ? 0 : 1;
        }
        int fir = 0;
        int sec = len - 1;
        while (sec >= fir) {
            if (nums[fir] != val) {
                fir++;
                continue;
            }
            while (sec >= 0 && nums[sec] == val) {
                sec--;
            }
            if (sec > fir) {
                nums[fir] = nums[sec];
                nums[sec] = val;
            }
        }
        return fir;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    vector<int> v1 = {3, 2, 2, 3};
    cout << s.removeElement(v1, 3) << endl; // 2
    printVector(v1); // [2, 2, 3, 3]
    vector<int> v2 = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << s.removeElement(v2, 2) << endl; // 5
    printVector(v2); // [0, 1, 4, 0, 3, 2, 2, 2]
    vector<int> v3 = {1, 1, 2, 2, 2};
    cout << s.removeElement(v3, 2) << endl; // 2
    printVector(v3); // [1, 1, 2, 2, 2]
    vector<int> v4 = {2};
    cout << s.removeElement(v4, 3) << endl; // 1
    printVector(v4); // [2]
    vector<int> v5 = {2};
    cout << s.removeElement(v5, 2) << endl; // 0
    printVector(v5); // []
    vector<int> v6 = {3, 3};
    cout << s.removeElement(v6, 3) << endl; // 0
    printVector(v6); // [3, 3]
    vector<int> v7 = {3, 3};
    cout << s.removeElement(v7, 5) << endl; // 2
    printVector(v7); // [3, 3]
    return 0;
}
