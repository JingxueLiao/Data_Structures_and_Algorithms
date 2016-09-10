// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

#include <vector>
#include <set>

using namespace std;

bool ContainsNearbyAlmostDuplicate(const vector<int> &nums, int k, int t) {
    if (nums.empty() || k <= 0 || t < 0)
        return false;
    set<int> appeared;
    for (int i = 0; i < nums.size(); ++i) {
        auto p = appeared.lower_bound(nums[i] - t);
        if (p != appeared.end() && *p - nums[i] <= t)
            return true;
        appeared.insert(nums[i]);
        if (i - k >= 0)
            appeared.erase(nums[i - k]);
    }
    return false;
}
