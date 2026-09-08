// @leet imports start
// Created: 2026-09-07 22:44:47

#include "../utils.h"
#include <queue>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class MedianFinder {
public:
  priority_queue<int, vector<int>, less<>> qMin;
  priority_queue<int, vector<int>, greater<>> qMax;

  MedianFinder() {}

  void addNum(int num) {
    if (qMin.empty() || num <= qMin.top()) {
      qMin.push(num);
      if (qMax.size() + 1 < qMin.size()) {
        qMax.push(qMin.top());
        qMin.pop();
      }
    } else {
      qMax.push(num);
      if (qMax.size() > qMin.size()) {
        qMin.push(qMax.top());
        qMax.pop();
      }
    }
  }

  double findMedian() {
    return (qMin.size() == qMax.size()) ? (qMin.top() + qMax.top()) / 2.0
                                        : qMin.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @leet end

int main() {
  MedianFinder obj;
  // 样例 1 输入: ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]; [[],[1],[2],[],[3],[]]
  // 样例 1 输出: (未解析)
  return 0;
}
