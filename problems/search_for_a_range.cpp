// Given a sorted array of integers, find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

#include <vector>

using namespace std;

vector<int> SearchRange(const vector<int> &nums, int target) {
    vector<int> range(2, -1);
    int begin = 0, end = nums.size() - 1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (target <= nums[mid])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    if (begin < nums.size() && nums[begin] == target) {
        range[0] = begin;
        end = nums.size() - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (target < nums[mid])
                end = mid - 1;
            else
                begin = mid + 1;
        }
        range[1] = end;
    }
    return range;
}
