// Given a nested list of integers, implement an iterator to flatten it.

// Each element is either an integer, or a list -- whose elements may also be integers or other lists.

// Example 1:
// Given the list [[1,1],2,[1,1]],

// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

// Example 2:
// Given the list [1,[4,[6]]],

// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger> &nestedList) {
        curs.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        if (!hasNext())
            return -1;
        return (curs.top()++)->getInteger();
    }

    bool hasNext() {
        while (!curs.empty()) {
            if (curs.top() == ends.top()) {
                curs.pop();
                ends.pop();
            } else {
                if (curs.top()->isInteger()) {
                    return true;
                } else {
                    ends.push(curs.top()->getList().end());
                    curs.push((curs.top()++)->getList().begin());
                }
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::const_iterator> curs;
    stack<vector<NestedInteger>::const_iterator> ends;
};
