// @leet imports start
// Created: 2025-09-21 10:06:22

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    int len = coordinates.size();
    int xx = coordinates[0][0];
    int yy = coordinates[0][1];
    double kk;
    bool kset = false;
    bool isv = false;
    for (int i = 1; i < len; i++) {
      int x = coordinates[i][0];
      int y = coordinates[i][1];
      if (!kset && x == xx) {
        isv = true;
        continue;
      }
      if ((isv && x != xx) || (!isv && x == xx)) {
        return false;
      }
      double k = (double)(y - yy) / (x - xx);
      if (!kset) {
        kk = k;
        kset = true;
      }
      if (kset && k != kk) {
        return false;
      }
    }
    return true;
  }
};
// @leet end

int main(void) {
  Solution s;
  vector<vector<int>> v0 = {{1, 1}, {2, 2}, {3, 4},
                            {4, 5}, {5, 6}, {7, 7}};   // false
  vector<vector<int>> v1 = {{0, 0}, {0, 1}, {0, -1}};  // true
  vector<vector<int>> v2 = {{2, 1}, {4, 2}, {6, 3}};   // true
  vector<vector<int>> v3 = {{1, -8}, {2, -3}, {1, 2}}; // false
  cout << s.checkStraightLine(v0) << endl;
  cout << s.checkStraightLine(v1) << endl;
  cout << s.checkStraightLine(v2) << endl;
  cout << s.checkStraightLine(v3) << endl;
  return 0;
}
