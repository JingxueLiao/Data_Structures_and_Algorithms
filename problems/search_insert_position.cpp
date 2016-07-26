// Given a sorted array and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

#include <vector>

using namespace std;

int SearchInsert(const vector<int> &nums, int target) {
    int begin = 0, end = nums.size() - 1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (target < nums[mid])
            end = mid - 1;
        else if (nums[mid] < target)
            begin = mid + 1;
        else
            return mid;
    }
    return begin;
}
