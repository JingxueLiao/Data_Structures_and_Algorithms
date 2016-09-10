// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include <vector>
#include <unordered_set>

using namespace std;

bool ContainsDuplicate(const vector<int> &nums) {
    unordered_set<int> appeared;
    for (auto p = nums.begin(); p != nums.end(); ++p) {
        if (appeared.find(*p) != appeared.end())
            return true;
        appeared.insert(*p);
    }
    return false;
}
