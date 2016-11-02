// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

// Example:
// (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
// (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

// Note:
// You may assume all input has valid answer.

// Follow Up:
// Can you do it in O(n) time and/or in-place with O(1) extra space?

#include <vector>
#include <algorithm>

using namespace std;

int Index(int i, int n) {
    return (i * 2 + 1) % (n | 1);
}

void WiggleSort(vector<int> &nums) {
    if (nums.empty())
        return;
    int n = nums.size();
    nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
    int mid = nums[n / 2];
    int i = 0, j = n - 1, k = 0;
    while (i <= j) {
        int cur = nums[Index(i, n)];
        if (mid < cur) {
            swap(nums[Index(i, n)], nums[Index(k, n)]);
            ++i;
            ++k;
        } else if (cur < mid) {
            swap(nums[Index(i, n)], nums[Index(j, n)]);
            --j;
        } else {
            ++i;
        }
    }
}
