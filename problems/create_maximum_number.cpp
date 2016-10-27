// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

// Example 1:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
// k = 5
// return [9, 8, 6, 5, 3]

// Example 2:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// return [6, 7, 6, 0, 4]

// Example 3:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// return [9, 8, 9]

#include <vector>
#include <algorithm>

using namespace std;

vector<int> MaximumKNumber(const vector<int> &nums, int k) {
    vector<int> number;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (!number.empty() && number.back() < nums[i] && number.size() + n - i > k)
            number.pop_back();
        if (number.size() < k)
            number.push_back(nums[i]);
    }
    return number;
}

bool Greater(const vector<int> &nums1, int b1, const vector<int> &nums2, int b2) {
    while (b1 < nums1.size() && b2 < nums2.size()) {
        if (nums1[b1] > nums2[b2]) {
            return true;
        } else if (nums1[b1] < nums2[b2]) {
            return false;
        } else {
            ++b1;
            ++b2;
        }
    }
    return b2 == nums2.size();
}

vector<int> Merge(const vector<int> &nums1, const vector<int> &nums2) {
    vector<int> result(nums1.size() + nums2.size());
    int i = 0, j = 0;
    while (i < nums1.size() || j < nums2.size()) {
        if (Greater(nums1, i, nums2, j)) {
            result[i + j] = nums1[i];
            ++i;
        } else {
            result[i + j] = nums2[j];
            ++j;
        }
    }
    return result;
}

vector<int> MaxNumber(const vector<int> &nums1, const vector<int> &nums2, int k) {
    vector<int> result(nums1.size() + nums2.size());
    for (int i = max(0, k - (int)nums2.size()); i <= k && i <= nums1.size(); ++i)
        result = max(result, Merge(MaximumKNumber(nums1, i), MaximumKNumber(nums2, k - i)));
    return result;
}
