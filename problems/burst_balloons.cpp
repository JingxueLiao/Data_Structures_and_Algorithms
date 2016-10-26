// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.

// Note: 
// (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

// Example:

// Given [3, 1, 5, 8]

// Return 167

//    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

#include <vector>
#include <algorithm>

using namespace std;

int MaxCoins(const vector<int> &nums) {
    if (nums.empty())
        return 0;
    int n = nums.size();
    vector<vector<int>> coins(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            for (int k = j; k <= j + i; ++k) {
                int left = j <= k - 1 ? coins[j][k - 1] : 0;
                int right = k + 1 <= j + i ? coins[k + 1][j + i] : 0;
                coins[j][j + i] = max(coins[j][j + i], left + right + (j == 0 ? 1 : nums[j - 1]) * nums[k] * (j + i == n - 1 ? 1 : nums[j + i + 1]));
            }
        }
    }
    return coins[0][n - 1];
}
