// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
// Try to solve it in linear time/space.
// Return 0 if the array contains less than 2 elements.
// You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

#include <vector>
#include <algorithm>

using namespace std;

int MaximumGap(const vector<int> &nums) {
    if (nums.size() <= 1)
        return 0;
    int n = nums.size();
    int maximum = nums[0], minimum = nums[0];
    for (int i = 1; i < n; ++i) {
        maximum = max(maximum, nums[i]);
        minimum = min(minimum, nums[i]);
    }
    int gap = (maximum - minimum + n - 2) / (n - 1);
    if (gap == 0)
        return 0;
    vector<int> max_buckets(n, -1), min_buckets(n, -1);
    for (int i = 0; i < n; ++i) {
        int index = (nums[i] - minimum) / gap;
        if (max_buckets[index] == -1 || nums[max_buckets[index]] < nums[i])
            max_buckets[index] = i;
        if (min_buckets[index] == -1 || nums[i] < nums[min_buckets[index]])
            min_buckets[index] = i;
    }
    int pre = minimum;
    for (int i = 0; i < n; ++i) {
        if (min_buckets[i] == -1)
            continue;
        gap = max(gap, nums[min_buckets[i]] - pre);
        pre = nums[max_buckets[i]];
    }
    return gap;
}
