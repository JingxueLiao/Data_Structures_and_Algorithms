// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#include <vector>
#include <algorithm>

using namespace std;

int Rob(const vector<int> &nums) {
    if (nums.empty())
        return 0;
    int ppre = 0, pre = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int cur = max(ppre + nums[i], pre);
        ppre = pre;
        pre = cur;
    }
    return pre;
}
