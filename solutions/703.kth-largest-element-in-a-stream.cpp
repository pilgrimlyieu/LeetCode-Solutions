// @leet imports start
// Created: 2026-09-08 09:25:40

#include "../utils.h"
#include <functional>
#include <initializer_list>
#include <queue>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class KthLargest {
public:
  priority_queue<int, vector<int>, greater<>> pq;
  int size;

  KthLargest(int k, vector<int> &nums) : size(k) {
    for (auto num : nums) {
      add(num);
    }
  }

  int add(int val) {
    if (pq.size() == size && pq.top() >= val) {
      return pq.top();
    }
    if (pq.size() == size) {
      pq.pop();
    }
    pq.push(val);
    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @leet end

int main() {
  // KthLargest obj;
  // 样例 1 输入: ["KthLargest","add","add","add","add","add"]; [[3,[4,5,8,2]],[3],[5],[10],[9],[4]]
  // 样例 1 输出: (未解析)
  // 样例 2 输入: ["KthLargest","add","add","add","add"]; [[4,[7,7,7,7,8,3]],[2],[10],[9],[9]]
  // 样例 2 输出: (未解析)
  return 0;
}
