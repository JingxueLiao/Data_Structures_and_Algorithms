// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
// 
// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

#include <vector>
#include <algorithm>

using namespace std;

int Trap(const vector<int> &height) {
    int water = 0;
    int begin = 0, end = height.size() - 1;
    while (begin < end) {
        if (height[begin] < height[end]) {
            int cur = begin;
            while (cur < end && height[cur] <= height[begin]) {
                water += height[begin] - height[cur];
                ++cur;
            }
            begin = cur;
        } else {
            int cur = end;
            while (begin < cur && height[cur] <= height[end]) {
                water += height[end] - height[cur];
                --cur;
            }
            end = cur;
        }
    }
    return water;
}
