// Note: This is an extension of House Robber.

// After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention.
// This time, all houses at this place are arranged in a circle.
// That means the first house is the neighbor of the last one.
// Meanwhile, the security system for these houses remain the same as for those in the previous street.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#include <vector>
#include <algorithm>

using namespace std;

int Rob(const vector<int> &nums) {
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int ppre = 0, pre = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        int cur = max(ppre + nums[i], pre);
        ppre = pre;
        pre = cur;
    }
    int first = pre;
    ppre = 0;
    pre = 0;
    for (int i = 1; i < nums.size(); ++i) {
        int cur = max(ppre + nums[i], pre);
        ppre = pre;
        pre = cur;
    }
    return max(first, pre);
}
