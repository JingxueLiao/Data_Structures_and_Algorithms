// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {
    }

    void push(int x) {
        if (data.empty() || x <= minimum) {
            data.push(minimum);
            minimum = x;
        }
        data.push(x);
    }

    void pop() {
        if (data.top() == minimum) {
            data.pop();
            minimum = data.top();
        }
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minimum;
    }

private:
    stack<int> data;
    int minimum;
};
