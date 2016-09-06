// Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s.
// If there isn't one, return 0 instead.

// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.

#include <vector>
#include <algorithm>

using namespace std;

int MinSubArrayLen(int s, const vector<int> &nums) {
    if (nums.empty())
        return 0;
    int i = 0, j = 0;
    int sum = 0, len = 0;
    while (j < nums.size()) {
        sum += nums[j++];
        if (s <= sum) {
            while (i < j && s <= sum - nums[i])
                sum -= nums[i++];
            len = j - i;
            break;
        }
    }
    while (j < nums.size()) {
        sum += nums[j++];
        while (i < j && s <= sum - nums[i])
            sum -= nums[i++];
        len = min(len, j - i);
    }
    return len;
}
