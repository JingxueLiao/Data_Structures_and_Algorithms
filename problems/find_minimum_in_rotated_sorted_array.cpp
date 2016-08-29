// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// You may assume no duplicate exists in the array.

#include <vector>

using namespace std;

int FindMin(const vector<int> &nums) {
    if (nums.empty())
        return 0;
    int low = 0, high = nums.size() - 1;
    while (low < high && nums[high] < nums[low]) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[high])
            high = mid;
        else
            low = mid + 1;
    }
    return nums[low];
}
