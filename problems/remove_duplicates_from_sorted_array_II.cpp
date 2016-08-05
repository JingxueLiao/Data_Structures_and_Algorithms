// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],
// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
// It doesn't matter what you leave beyond the new length.

#include <vector>

using namespace std;

int RemoveDuplicates(vector<int> &nums) {
    int i = 0, j = 0;
    while (j < nums.size()) {
        nums[i++] = nums[j++];
        if (j < nums.size() && nums[j] == nums[j - 1])
            nums[i++] = nums[j++];
        while (j < nums.size() && nums[j] == nums[j - 1])
            ++j;
    }
    return i;
}
