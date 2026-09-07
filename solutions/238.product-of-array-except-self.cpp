// @leet imports start
// Created: 2026-09-07 17:34:15

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 1), prefix(n, 1), suffix(n, 1);
    for (int i = 0; i < n - 1; i++) {
      prefix[i + 1] = prefix[i] * nums[i];
      suffix[n - 2 - i] = suffix[n - 1 - i] * nums[n - 1 - i];
    }
    for (int i = 0; i < n; i++) {
      ans[i] = prefix[i] * suffix[i];
    }
    return ans;
  }
};
// @leet end

// @alt 双指针
class SolutionLR {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size(), left = 0, right = n - 1, leftProd = 1, rightProd = 1;
    vector<int> ans(n, 1);
    while (left < n && right >= 0) {
      ans[left] *= leftProd;
      ans[right] *= rightProd;
      leftProd *= nums[left++];
      rightProd *= nums[right--];
    }
    return ans;
  }
};
// @alt end

int main() {
  Solution s;
  CHECK(s.productExceptSelf("[1,2,3,4]"_vi), "[24,12,8,6]"_vi);
  CHECK(s.productExceptSelf("[-1,1,0,-3,3]"_vi), "[0,0,9,0,0]"_vi);
  return 0;
}
