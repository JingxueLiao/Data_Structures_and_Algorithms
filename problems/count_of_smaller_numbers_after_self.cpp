// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

// Example:

// Given nums = [5, 2, 6, 1]

// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
// Return the array [2, 1, 1, 0].

#include <vector>

using namespace std;

void merge(vector<int> &nums, vector<pair<int, int>> &counts, int begin, int end) {
    vector<int> sorted_nums(end - begin);
    vector<pair<int, int>> sorted_counts(end - begin);
    int mid = begin + (end - begin) / 2;
    int i = begin, j = mid, k = 0;
    while (i < mid && j < end) {
        if (nums[i] <= nums[j]) {
            sorted_nums[k] = nums[i];
            sorted_counts[k] = counts[i];
            sorted_counts[k].first += j - mid;
            ++i;
        } else {
            sorted_nums[k] = nums[j];
            sorted_counts[k] = counts[j];
            ++j;
        }
        ++k;
    }
    while (i < mid) {
        sorted_nums[k] = nums[i];
        sorted_counts[k] = counts[i];
        sorted_counts[k].first += j - mid;
        ++i;
        ++k;
    }
    while (j < end) {
        sorted_nums[k] = nums[j];
        sorted_counts[k] = counts[j];
        ++j;
        ++k;
    }
    for (k = 0; k < end - begin; ++k) {
        nums[begin + k] = sorted_nums[k];
        counts[begin + k] = sorted_counts[k];
    }
}

void sort_and_count(vector<int> &nums, vector<pair<int, int>> &counts, int begin, int end) {
    if (begin + 1 == end)
        return;
    int mid = begin + (end - begin) / 2;
    sort_and_count(nums, counts, begin, mid);
    sort_and_count(nums, counts, mid, end);
    merge(nums, counts, begin, end);
}

vector<int> CountSmaller(vector<int> nums) {
    if (nums.empty())
        return vector<int>();
    vector<pair<int, int>> counts(nums.size());
    for (int i = 0; i < counts.size(); ++i)
        counts[i].second = i;
    sort_and_count(nums, counts, 0, nums.size());
    vector<int> result(nums.size());
    for (int i = 0; i < counts.size(); ++i)
        result[counts[i].second] = counts[i].first;
    return result;
}
