// @leet imports start
// Created: 2025-09-14 10:57:51

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int len = digits.size();
    for (int i = len - 1; i >= 0; i--) {
      int result = digits[i] + 1;
      if (result < 10) {
        digits[i] += 1;
        return digits;
      }
      digits[i] = 0;
    }
    if (digits[0] == 0) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};
// @leet end

int main(void) {
  Solution s;
  vector<int> v = {9, 9, 9};
  cout << s.plusOne(v) << endl;
  return 0;
}
