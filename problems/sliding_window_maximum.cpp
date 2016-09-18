// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 
// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Therefore, return the max sliding window as [3,3,5,5,6,7].
 
// Note: 
// You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 
// Follow up:
// Could you solve it in linear time?

#include <vector>
#include <deque>

using namespace std;

vector<int> MaxSlidingWindow(const vector<int> &nums, int k) {
    if (nums.empty() || k <= 0)
        return vector<int>();
    k = k <= nums.size() ? k : nums.size();
    vector<int> maximums(nums.size() - k + 1);
    deque<int> candidates;
    for (int i = 0; i < nums.size(); ++i) {
        while (!candidates.empty() && candidates.back() < nums[i])
            candidates.pop_back();
        candidates.push_back(nums[i]);
        if (i >= k - 1) {
            maximums[i + 1 - k] = candidates.front();
            if (nums[i - k] == candidates.front())
                candidates.pop_front();
        }
    }
    return maximums;
}
