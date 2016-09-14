// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.

// Notes:
// You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively.
// You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

#include <queue>

using namespace std;

class Stack {
public:
    void push(int x) {
        data.push(x);
        for (int i = 1; i < data.size(); ++i) {
            data.push(data.front());
            data.pop();
        }
    }

    void pop() {
        data.pop();
    }

    int top() {
        return data.front();
    }

    bool empty() const {
        return data.empty();
    }

private:
    queue<int> data;
};
