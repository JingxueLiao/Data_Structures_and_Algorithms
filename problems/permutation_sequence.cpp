// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"

// Given n and k, return the kth permutation sequence.

// Note: Given n will be between 1 and 9 inclusive.

#include <string>
#include <vector>

using namespace std;

string GetPermutation(int n, int k) {
    if (n <= 0 || k <= 0)
        return string();
    int amount = 1;
    for (int i = 1; i <= n; ++i)
        amount *= i;
    k = (k - 1) % amount;
    vector<bool> used(n);
    string permutation(n, '1');
    for (int i = n; i > 0; --i) {
        amount /= i;
        int j = k / amount;
        for (int k = 0; k < n; ++k) {
            if (used[k])
                continue;
            if (j-- == 0) {
                permutation[n - i] += k;
                used[k] = true;
            }
        }
        k = k % amount;
    }
    return permutation;
}
