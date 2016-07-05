#pragma once

#include <vector>

using std::vector;

int merge(vector<int> &nums, int begin, int mid, int end) {
    int inversions = 0;
    vector<int> tmp(end - begin + 1);
    int i = begin, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
            inversions += j - mid - 1;
        } else {
            tmp[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = nums[i++];
        inversions += j - mid - 1;
    }
    while (j <= end) {
        tmp[k++] = nums[j++];
    }
    for (int i = begin; i <= end; ++i)
        nums[i] = tmp[i - begin];
    return inversions;
}

int divide(vector<int> &nums, int begin, int end) {
    if (begin == end)
        return 0;
    int inversions = 0;
    int mid = begin + (end - begin) / 2;
    inversions += divide(nums, begin, mid);
    inversions += divide(nums, mid + 1, end);
    inversions += merge(nums, begin, mid, end);
    return inversions;
}

int count_inversions(const vector<int> &nums) {
    vector<int> tmp(nums);
    return divide(tmp, 0, tmp.size() - 1);
}
