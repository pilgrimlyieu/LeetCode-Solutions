// @leet imports start
// Created: 2025-09-14 11:11:36

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool canMakeArithmeticProgression(vector<int> &arr) {
    sort(arr.begin(), arr.end(),
         [](int const &a, int const &b) { return a < b; });
    int len = arr.size();
    int itv = arr[1] - arr[0];
    for (int i = 1; i < len - 1; i++) {
      if (arr[i + 1] - arr[i] != itv) {
        return false;
      }
    }
    return true;
  }
};
// @leet end

int main(void) {
  Solution s;
  vector<int> v = {1, 10, 10, 10, 19};
  cout << s.canMakeArithmeticProgression(v);
  return 0;
}
