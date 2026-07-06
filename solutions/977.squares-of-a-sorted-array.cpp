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
    vector<int> res;
    res.reserve(len);
    int fir = 0;
    while (fir < len && nums[fir] < 0) {
      fir++;
    }
    int sec = fir;
    fir--;
    while (fir >= 0 && sec < len) {
      if (abs(nums[fir]) > abs(nums[sec])) {
        res.push_back(nums[sec] * nums[sec]);
        sec++;
      } else {
        res.push_back(nums[fir] * nums[fir]);
        fir--;
      }
    }
    while (fir >= 0) {
      res.push_back(nums[fir] * nums[fir]);
      fir--;
    }
    while (sec < len) {
      res.push_back(nums[sec] * nums[sec]);
      sec++;
    }
    return res;
  }
};
// @leet end

int main(void) {
  Solution s;
  vector<int> v1 = {-1};
  cout << s.sortedSquares(v1) << endl; // [1]
  vector<int> v2 = {1};
  cout << s.sortedSquares(v2) << endl; // [1]
  vector<int> v3 = {-1, 2, 2};
  cout << s.sortedSquares(v3) << endl; // [1, 4, 4]
  return 0;
}
