// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

// Note: You may assume that n is not less than 2 and not larger than 58.

#include <vector>
#include <algorithm>

using namespace std;

int IntegerBreak(int n) {
    if (n <= 0)
        return 0;
    vector<int> product(n + 1);
    product[1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            product[i] = max(product[i], j * max(i - j, product[i - j]));
    return product[n];
}
