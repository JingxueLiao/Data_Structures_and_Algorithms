// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search.
// If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.

#include <vector>

using namespace std;

int Search(const vector<int> &nums, int target) {
    int begin = 0, end = nums.size() - 1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (target < nums[mid]) {
            if (nums[begin] <= nums[mid] && target < nums[begin])
                begin = mid + 1;
            else
                end = mid - 1;
        } else if (nums[mid] < target) {
            if (nums[mid] < nums[begin] && nums[begin] <= target)
                end = mid - 1;
            else
                begin = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
