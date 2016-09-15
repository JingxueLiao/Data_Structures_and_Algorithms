// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// The algorithm should run in linear time and in O(1) space.

#include <vector>

using namespace std;

vector<int> MajorityElement(const vector<int> &nums) {
    int num1, num2;
    int times1 = 0, times2 = 0;
    for (auto p = nums.begin(); p != nums.end(); ++p) {
        if (*p == num1) {
            ++times1;
        } else if (*p == num2) {
            ++times2;
        } else if (times1 == 0) {
            num1 = *p;
            times1 = 1;
        } else if (times2 == 0) {
            num2 = *p;
            times2 = 1;
        } else {
            --times1;
            --times2;
        }
    }
    vector<int> result;
    times1 = 0;
    times2 = 0;
    for (auto p = nums.begin(); p != nums.end(); ++p) {
        if (*p == num1)
            ++times1;
        else if (*p == num2)
            ++times2;
    }
    if (times1 > nums.size() / 3)
        result.push_back(num1);
    if (times2 > nums.size() / 3)
        result.push_back(num2);
    return result;
}
