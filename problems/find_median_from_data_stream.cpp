// Median is the middle value in an ordered integer list.
// If the size of the list is even, there is no middle value.
// So the median is the mean of the two middle value.

// Examples: 
// [2,3,4] , the median is 3
// [2,3], the median is (2 + 3) / 2 = 2.5

// Design a data structure that supports the following two operations:
// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.

// For example:
// add(1)
// add(2)
// findMedian() -> 1.5
// add(3) 
// findMedian() -> 2

#include <queue>
#include <algorithm>

using namespace std;

class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (low.empty()) {
            low.push(num);
        } else if (low.size() == high.size()) {
            if (num > high.top()) {
                low.push(high.top());
                high.pop();
                high.push(num);
            } else {
                low.push(num);
            }
        } else {
            if (num < low.top()) {
                high.push(low.top());
                low.pop();
                low.push(num);
            } else {
                high.push(num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (high.size() < low.size()) {
            return low.top();
        } else {
            return (double)(low.top() + high.top()) / 2;
        }
    }

private:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
};
