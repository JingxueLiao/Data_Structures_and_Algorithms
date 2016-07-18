/*
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays.
* The overall run time complexity should be O(log (m+n)).
*
* Examples:
* nums1 = [1, 3]
* nums2 = [2]
* The median is 2.0
* 
* nums1 = [1, 2]
* nums2 = [3, 4]
* The median is (2 + 3)/2 = 2.5
*/

#include <vector>
#include <algorithm>

using namespace std;

int findKthElementOfTwoSortedArrays(const vector<int> &nums1, int begin1, const vector<int> &nums2, int begin2, int k) {
    if (nums2.size() - begin2 < nums1.size() - begin1)
        return findKthElementOfTwoSortedArrays(nums2, begin2, nums1, begin1, k);
    if (begin1 == nums1.size())
        return nums2[begin2 + k - 1];
    if (k == 1)
        return min(nums1[begin1], nums2[begin2]);
    int k1 = k / 2 < nums1.size() - begin1 ? k / 2 : nums1.size() - begin1, k2 = k - k1;
    if (nums1[begin1 + k1 - 1] < nums2[begin2 + k2 - 1]) {
        return findKthElementOfTwoSortedArrays(nums1, begin1 + k1, nums2, begin2, k - k1);
    } else if (nums2[begin2 + k2 - 1] < nums1[begin1 + k1 - 1]) {
        return findKthElementOfTwoSortedArrays(nums1, begin1, nums2, begin2 + k2, k - k2);
    } else {
        return nums1[begin1 + k1 - 1];
    }
}

double findMedianOfTwoSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if ((nums1.size() + nums2.size()) % 2)
        return findKthElementOfTwoSortedArrays(nums1, 0, nums2, 0, (m + n) / 2 + 1);
    else
        return (double)(findKthElementOfTwoSortedArrays(nums1, 0, nums2, 0, (m + n) / 2) + findKthElementOfTwoSortedArrays(nums1, 0, nums2, 0, (m + n) / 2 + 1)) / 2;
}
