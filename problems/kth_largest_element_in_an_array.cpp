// Find the kth largest element in an unsorted array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.

#include <vector>

using namespace std;

int FindKthLargest(vector<int> &nums, int k) {
    if (nums.empty() || k <= 0 || k > nums.size())
        return 0;
    int begin = 0, end = nums.size() - 1;
    while (begin < end) {
        int pivot = nums[begin];
        int i = begin, j = end;
        while (i < j) {
            while (i < j && nums[j] <= pivot)
                --j;
            nums[i] = nums[j];
            while (i < j && nums[i] >= pivot)
                ++i;
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        int t = i - begin + 1;
        if (t < k) {
            begin = i + 1;
            k -= t;
        } else if (t > k) {
            end = i - 1;
        } else {
            return pivot;
        }
    }
    return nums[begin];
}
