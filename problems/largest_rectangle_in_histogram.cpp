// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

// For example,
// Given heights = [2,1,5,6,2,3],
// return 10.

#include <vector>
#include <stack>
#include <utility>

using namespace std;

int LargestRectangleArea(const vector<int> &heights) {
    stack<pair<int, int>> pending;
    int largest = 0;
    for (int i = 0; i < heights.size(); ++i) {
        while (!pending.empty() && heights[i] < pending.top().first) {
            int h = pending.top().first;
            pending.pop();
            int left = pending.empty() ? 0 : pending.top().second + 1;
            if (largest < (i - left) * h)
                largest = (i - left) * h;
        }
        pending.push(make_pair(heights[i], i));
    }
    while (!pending.empty()) {
        int h = pending.top().first;
        pending.pop();
        int left = pending.empty() ? 0 : pending.top().second + 1;
        if (largest < (heights.size() - left) * h)
            largest = (heights.size() - left) * h;
    }
    return largest;
}
