// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

#include <vector>
#include <unordered_set>

using namespace std;

bool ContainsNearbyDuplicate(const vector<int> &nums, int k) {
    if (k < 0 || nums.empty())
        return false;
    unordered_set<int> appeared;
    for (int i = 0; i < nums.size(); ++i) {
        if (appeared.find(nums[i]) != appeared.end())
            return true;
        appeared.insert(nums[i]);
        if (i - k >= 0)
            appeared.erase(nums[i - k]);
    }
    return false;
}
