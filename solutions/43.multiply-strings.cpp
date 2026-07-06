// @leet imports start
// Created: 2025-09-24 20:46:59

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> stringToIntVec(string num) {
    vector<int> res;
    int len = num.length();
    res.reserve(len);
    for (int i = 0; i < len; i++) {
      res.push_back(num[len - 1 - i] - '0');
    }
    return res;
  }

  string intVecToString(vector<int> &nums) {
    stringstream ss;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      int num = nums[len - 1 - i];
      if (num < 0) {
        continue;
      }
      ss << nums[len - 1 - i];
    }
    return ss.str();
  }

  int addNum(int origin, int addition) {
    return (origin < 0) ? addition : origin + addition;
  }

  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }
    vector<int> nums1 = stringToIntVec(num1);
    vector<int> nums2 = stringToIntVec(num2);
    int l1 = num1.length();
    int l2 = num2.length();
    vector<int> res;
    res.assign(l1 + l2, -1);
    for (int i = 0; i < l1; i++) {
      int next = 0;
      for (int j = 0; j < l2; j++) {
        int result = addNum(res[i + j], next + nums1[i] * nums2[j]);
        next = result / 10;
        res[i + j] = result % 10;
      }
      if (next) {
        res[i + l2] = addNum(res[i + l2], next);
      }
    }
    return intVecToString(res);
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.multiply("2", "3") << endl;     // 6
  cout << s.multiply("123", "456") << endl; // 56088
  return 0;
}
