// @leet imports start
// Created: 2026-08-29 21:14:39

#include "../utils.h"
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
    for (auto price : prices) {
      buy1 = max(buy1, -price);
      sell1 = max(sell1, buy1 + price);
      buy2 = max(buy2, sell1 - price);
      sell2 = max(sell2, buy2 + price);
    }
    return sell2;
  }
};
// @leet end

// @card idea 动态规划
// DP 还是要好好确定状态、转移操作与相应的方程，表达出来后就简单了，甚至可以扩展到其他情形。一共有五个状态，记录当时状态的利润：
// 1. 未进行任何操作，利润始终为 0，无需额外记录；
// 2. 只进行了一次买操作，在 $i$ 时利润为 $\mathrm{buy}_1[i] = \max(\mathrm{buy}[i-1],-\mathrm{price}[i])$；
// 3. 仅完成了一次交易，在 $i$ 时利润为 $\mathrm{sell}_1[i] = \max(\mathrm{sell}_1[i-1],\mathrm{buy}_1[i-1]+\mathrm{price}[i])$；
// 4. 在完成了一次交易后，又进行了第二次买操作，在 $i$ 时利润为 $\mathrm{buy}_2[i] = \max(\mathrm{buy}_2[i-1],\mathrm{sell}_1[i-1]-\mathrm{price}[i])$；
// 5. 完成了全部两次交易，在 $i$ 时利润为 $\mathrm{sell}_2[i] = \max(\mathrm{sell}_2[i-1],\mathrm{buy}_2[i-1]+\mathrm{price}[i])$。
//
// 由于仅跟前一个状态有关，因此可以使用滚动数组优化空间复杂度。同一层后面的状态不需要保存前一层前面的旧状态，例如说 $\mathrm{buy}_1[i]$ 比 $\mathrm{buy}_1[i-1]$ 仅多考虑了第 $i$ 天买入的情况，转移到 $\mathrm{sell}_1[i]$ 的时候，考虑的是第 $i$ 天卖出，同一天买入再卖出收益为零不会有影响。即允许今天买入今天卖出，甚至继续第二次买入，从而将状态传递到了最后（即便实际上最优只进行了一次有效交易），只需要返回最后的 $\mathrm{sell}_2$ 即可，。

// @card note
// 为了基于范围遍历，买入的利润初值设置为极小值。卖出其实也可以如此，不过卖出后的初始利润显然是 0。

int main() {
  Solution s;
  // 注: 题面解析到 4 个输出但有 3 个样例，期望值请手动核对
  CHECK(s.maxProfit("[3,3,5,0,0,3,1,4]"_vi), 6);
  CHECK(s.maxProfit("[1,2,3,4,5]"_vi), 4);
  CHECK(s.maxProfit("[7,6,4,3,1]"_vi), 0);
  CHECK(s.maxProfit("[1]"_vi), 0);
  return 0;
}
