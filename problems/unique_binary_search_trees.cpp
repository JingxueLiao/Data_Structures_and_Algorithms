// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

// For example,
// Given n = 3, there are a total of 5 unique BST's.

//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

#include <vector>

using namespace std;

int NumTrees(int n) {
    if (n <= 0)
        return 0;
    vector<int> nums(n + 1);
    nums[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            nums[i] += nums[j - 1] * nums[i - j];
    return nums[n];
}
