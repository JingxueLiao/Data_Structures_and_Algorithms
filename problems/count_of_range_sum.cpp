// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

// Note:
// A naive algorithm of O(n^2) is trivial. You MUST do better than that.

// Example:
// Given nums = [-2, 5, -1], lower = -2, upper = 2,
// Return 3.
// The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

#include <vector>
#include <algorithm>

using namespace std;

int Merge(vector<long long> &sums, int begin, int end, int lower, int upper) {
    int mid = begin + (end - begin) / 2;
    int ranges = 0;
    int l = lower_bound(sums.begin() + mid, sums.begin() + end, lower + sums[begin]) - sums.begin();
    int r = upper_bound(sums.begin() + mid, sums.begin() + end, upper + sums[begin]) - sums.begin();
    for (int i = begin; i < mid; ++i) {
        while (l < end && sums[l] - sums[i] < lower)
            ++l;
        while (r < end && sums[r] - sums[i] <= upper)
            ++r;
        ranges += r - l;
    }
    vector<long long> sorted(end - begin);
    int i = begin, j = mid, k = 0;
    while (i < mid && j < end) {
        if (sums[i] < sums[j]) {
            sorted[k++] = sums[i++];
        } else {
            sorted[k++] = sums[j++];
        }
    }
    while (i < mid)
        sorted[k++] = sums[i++];
    while (j < end)
        sorted[k++] = sums[j++];
    for (int i = begin; i < end; ++i)
        sums[i] = sorted[i - begin];
    return ranges;
}

int CountRange(vector<long long> &sums, int begin, int end, int lower, int upper) {
    if (begin + 1 == end)
        return 0;
    int mid = begin + (end - begin) / 2;
    int left = CountRange(sums, begin, mid, lower, upper);
    int right = CountRange(sums, mid, end, lower, upper);
    return left + right + Merge(sums, begin, end, lower, upper);
}

int CountRangeSum(const vector<int> &nums, int lower, int upper) {
    if (nums.empty())
        return 0;
    vector<long long> sums(nums.size() + 1);
    for (int i = 0; i < nums.size(); ++i)
        sums[i + 1] = sums[i] + nums[i];
    return CountRange(sums, 0, sums.size(), lower, upper);
}
