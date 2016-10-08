// Given an unsorted array of integers, find the length of longest increasing subsequence.

// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

// Your algorithm should run in O(n2) complexity.

// Follow up: Could you improve it to O(n log n) time complexity?

#include <vector>
#include <algorithm>

using namespace std;

int LengthOfLIS(const vector<int> &nums) {
    vector<int> increasing_subsequences;
    for (auto p = nums.begin(); p != nums.end(); ++p) {
        auto q = lower_bound(increasing_subsequences.begin(), increasing_subsequences.end(), *p);
        if (q == increasing_subsequences.end()) {
            increasing_subsequences.push_back(*p);
        } else {
            *q = *p;
        }
    }
    return increasing_subsequences.size();
}
