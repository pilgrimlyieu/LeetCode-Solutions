// 2025-10-15 11:15:15

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class MyStack {
    queue<int> q;
    int p = 0;

    public:
    MyStack() {}

    void push(int x) {
        if (p != q.size()) {
            int n = q.front();
            q.push(n);
            q.pop();
            p = q.size();
        }
        q.push(x);
        p++;
    }

    int pop() {
        for (int i = 0; i < p - 1; i++) {
            int n = q.front();
            q.pop();
            q.push(n);
        }
        int n = q.front();
        q.pop();
        p = q.size();
        return n;
    }

    int top() {
        for (int i = 0; i < p - 1; i++) {
            int n = q.front();
            q.pop();
            q.push(n);
        }
        p = 1;
        return q.front();
    }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    MyStack *s = new MyStack();
    s->push(1);
    s->push(2);
    cout << s->top() << endl;
    s->push(3);
    cout << s->top() << endl;
    return 0;
}
