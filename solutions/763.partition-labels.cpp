// @leet imports start
// Created: 2026-08-27 16:15:05

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  vector<int> partitionLabels(string s) {
    int len = s.length();
    int last[26];
    vector<int> ans;
    for (int i = 0; i < len; i++) {
      last[s[i] - 'a'] = i;
    }
    int start = 0, end = 0;
    for (int i = 0; i < len; i++) {
      end = max(end, last[s[i] - 'a']);
      if (i == end) {
        ans.push_back(end - start + 1);
        start = end + 1;
      }
    }
    return ans;
  }
};
// @leet end

// @card hint
// 除此之外，思考 array 的初始化。

// @card idea
// 本质上是区间合并之并集数目。无需记录每个字母的起始点、按左边界排序然后遍历区间，可以只记录最后出现的位置，然后遍历字符串不断扩展边界即可。

// @card note
// 要注意 array 零值初始化很简单，但非零值要用 `fill`。
//
// 区间合并中：
// 1. 并集一般按左边界排序，因为这样扫描过程中合并区间左边界不会变小，右边界不断取更大值即可。
// 2. 交集一般按右边界排序，因为交集右边界等于重叠区间右边界的最小值。

int main() {
  Solution s;
  CHECK(s.partitionLabels("ababcbacadefegdehijhklij"), "[9,7,8]"_vi);
  CHECK(s.partitionLabels("eccbbbbdec"), "[10]"_vi);
  return 0;
}
