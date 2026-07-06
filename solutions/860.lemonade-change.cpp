// @leet imports start
// Created: 2025-09-19 23:16:50

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    vector<int> changes = {0, 0};
    for (auto bill : bills) {
      if (bill == 5) {
        changes[0]++;
      } else if (bill == 10) {
        if (changes[0] == 0) {
          return false;
        }
        changes[0]--;
        changes[1]++;
      } else {
        if (changes[0] > 0 && changes[1] > 0) {
          changes[0]--;
          changes[1]--;
        } else if (changes[0] >= 3) {
          changes[0] -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
