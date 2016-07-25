// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include <vector>
#include <algorithm>

using namespace std;

void NextPermutation(vector<int> &nums) {
    if (nums.empty())
        return;
    int i = nums.size() - 1;
    while (i > 0 && nums[i] <= nums [i - 1])
        --i;
    reverse(nums.begin() + i, nums.end());
    if (i > 0) {
        int j = i;
        while (nums[j] <= nums[i - 1])
            ++j;
        swap(nums[i - 1], nums[j]);
    }
    return;
}
