// Find the contiguous subarray within an array (containing at least one number) which has the largest product.

// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.

#include <vector>
#include <algorithm>

using namespace std;

int MaxProduct(const vector<int> &nums) {
    if (nums.empty())
        return 0;
    int cur_max = nums[0], cur_min = nums[0], max_product = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int tmp = cur_max;
        cur_max = max(nums[i], max(nums[i] * tmp, nums[i] * cur_min));
        cur_min = min(nums[i], min(nums[i] * tmp, nums[i] * cur_min));
        max_product = max(cur_max, max_product);
    }
    return max_product;
}
