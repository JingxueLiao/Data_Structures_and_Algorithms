// Given a list of non negative integers, arrange them such that they form the largest number.

// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Comp {
public:
    bool operator()(const string &a, const string &b) const {
        return b + a < a + b;
    }
};

string LargestNumber(const vector<int> &nums) {
    if (nums.empty())
        return "0";
    vector<string> numbers(nums.size());
    for (int i = 0; i < nums.size(); ++i)
        numbers[i] = to_string(nums[i]);
    sort(numbers.begin(), numbers.end(), Comp());
    if (numbers[0] == "0")
        return "0";
    string number;
    for (int i = 0; i < numbers.size(); ++i)
        number += numbers[i];
    return number;
}
