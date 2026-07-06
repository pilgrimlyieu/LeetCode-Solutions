// @leet imports start
// Created: 2025-09-27 15:15:47

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
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
// @leet end

int main(void) {
  Solution s;
  vector<int> v1 = {3, 2, 2, 3};
  cout << s.removeElement(v1, 3) << endl; // 2
  cout << v1 << endl;                     // [2, 2, 3, 3]
  vector<int> v2 = {0, 1, 2, 2, 3, 0, 4, 2};
  cout << s.removeElement(v2, 2) << endl; // 5
  cout << v2 << endl;                     // [0, 1, 4, 0, 3, 2, 2, 2]
  vector<int> v3 = {1, 1, 2, 2, 2};
  cout << s.removeElement(v3, 2) << endl; // 2
  cout << v3 << endl;                     // [1, 1, 2, 2, 2]
  vector<int> v4 = {2};
  cout << s.removeElement(v4, 3) << endl; // 1
  cout << v4 << endl;                     // [2]
  vector<int> v5 = {2};
  cout << s.removeElement(v5, 2) << endl; // 0
  cout << v5 << endl;                     // []
  vector<int> v6 = {3, 3};
  cout << s.removeElement(v6, 3) << endl; // 0
  cout << v6 << endl;                     // [3, 3]
  vector<int> v7 = {3, 3};
  cout << s.removeElement(v7, 5) << endl; // 2
  cout << v7 << endl;                     // [3, 3]
  return 0;
}
