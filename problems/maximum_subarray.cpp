// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.

// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#include <vector>

using namespace std;

int MaximumSubarray(const vector<int> &nums) {
    if (nums.empty())
        return 0;
    int maximum = nums[0], cur = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (cur <= 0)
            cur = nums[i];
        else
            cur += nums[i];
        if (maximum < cur)
            maximum = cur;
    }
    return maximum;
}
