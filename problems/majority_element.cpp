// Given an array of size n, find the majority element.
// The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.

#include <vector>

using namespace std;

int MajorityElement(const vector<int> &nums) {
    int element = 0, time = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (time == 0 || nums[i] == element) {
            element = nums[i];
            ++time;
        } else {
            --time;
        }
    }
    return element;
}
