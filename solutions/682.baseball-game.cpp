// @leet imports start
// Created: 2025-09-17 20:00:56

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool is_number(const string &s) {
    // 作弊一下……
    return isdigit(s[s.length() - 1]);
  }

  int calPoints(vector<string> &operations) {
    int len = operations.size();
    vector<int> points;
    int p = 0;
    points.reserve(len);
    for (int i = 0; i < len; i++) {
      if (is_number(operations[i])) {
        points.push_back(stoi(operations[i]));
        p++;
      } else if (operations[i] == "+") {
        points.push_back(points[p - 1] + points[p - 2]);
        p++;
      } else if (operations[i] == "D") {
        points.push_back(points[p - 1] * 2);
        p++;
      } else if (operations[i] == "C") {
        points.pop_back();
        p--;
      }
    }
    int result = 0;
    for (int i = 0; i < p; i++) {
      result += points[i];
    }
    return result;
  }
};
// @leet end

int main(void) {
  Solution s;

  return 0;
}
