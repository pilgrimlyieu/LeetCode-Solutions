// @leet imports start
// Created: 2025-10-10 10:24:35

#include "../utils.h"

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int fir = 0; fir < len; fir++) {
      if (fir > 0 && nums[fir] == nums[fir - 1]) {
        continue;
      }
      for (int sec = fir + 1; sec < len; sec++) {
        if (sec > fir + 1 && nums[sec] == nums[sec - 1]) {
          continue;
        }
        int fot = len - 1;
        long long aim = (long long)target - nums[fir] - nums[sec];
        for (int thi = sec + 1; thi < len; thi++) {
          if (thi > sec + 1 && nums[thi] == nums[thi - 1]) {
            continue;
          }
          while (thi < fot && (long long)nums[thi] + nums[fot] > aim) {
            fot--;
          }
          if (thi == fot) {
            break;
          }
          if ((long long)nums[thi] + nums[fot] == aim) {
            ans.push_back({nums[fir], nums[sec], nums[thi], nums[fot]});
          }
        }
      }
    }
    return ans;
  }
};
// @leet end

int main(void) {
  Solution s;
  cout << s.fourSum("[1,0,-1,0,-2,2]"_vi, 0) << endl;
  cout << s.fourSum("[2,2,2,2,2]"_vi, 8) << endl;
  cout << s.fourSum("[1000000000,1000000000,1000000000,1000000000]"_vi,
                    -294967296)
       << endl;
  return 0;
}
