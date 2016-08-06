// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?
// Would this affect the run-time complexity? How and why?
// Write a function to determine if a given target is in the array.

#include <vector>

using namespace std;

bool Search(const vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        while (low < high && nums[low] == nums[high])
            --high;
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) {
            if (nums[mid] < nums[low] && nums[low] <= target)
                high = mid - 1;
            else
                low = mid + 1;
        } else if (target < nums[mid]) {
            if (nums[low] <= nums[mid] && target < nums[low])
                low = mid + 1;
            else
                high = mid - 1;
        } else {
            return true;
        }
    }
    return false;
}
