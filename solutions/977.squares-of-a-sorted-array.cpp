// @leet imports start
// Created: 2025-09-27 15:41:49

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int len = nums.size();
    vector<int> res(len);
    for (int i = 0, j = len - 1, idx = len - 1; i <= j;) {
      if (abs(nums[i]) > abs(nums[j])) {
        res[idx--] = nums[i] * nums[i];
        i++;
      } else {
        res[idx--] = nums[j] * nums[j];
        j--;
      }
    }
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  CHECK(s.sortedSquares("[-4,-1,0,3,10]"_vi), "[0,1,9,16,100]"_vi);
  CHECK(s.sortedSquares("[-7,-3,2,3,11]"_vi), "[4,9,9,49,121]"_vi);
  CHECK(s.sortedSquares("[-1]"_vi), "[1]"_vi);
  CHECK(s.sortedSquares("[1]"_vi), "[1]"_vi);
  CHECK(s.sortedSquares("[-5,-3,-2,-1]"_vi), "[1,4,9,25]"_vi);
  CHECK(s.sortedSquares("[-1, 2, 2]"_vi), "[1, 4, 4]"_vi);
  return 0;
}
