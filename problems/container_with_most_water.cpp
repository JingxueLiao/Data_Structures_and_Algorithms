// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container.

#include <vector>
#include <algorithm>

using namespace std;

int MaxArea(const vector<int> &height) {
    int result = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        if (result < (j - i) * min(height[i], height[j]))
            result = (j - i) * min(height[i], height[j]);
        if (height[i] < height[j])
            ++i;
        else
            --j;
    }
    return result;
}
