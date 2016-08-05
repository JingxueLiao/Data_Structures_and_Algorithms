// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note:
// You are not suppose to use the library's sort function for this problem.

#include <vector>
#include <algorithm>

using namespace std;

void SortColors(vector<int> &nums) {
    int i = 0, j =  0, k = nums.size() - 1;
    while (i <= k) {
        if (nums[i] == 0) {
            swap(nums[j++], nums[i++]);
        } else if (nums[i] == 2) {
            swap(nums[i], nums[k--]);
        } else {
            ++i;
        }
    }
}
