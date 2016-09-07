// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Example 1:
// Input: k = 3, n = 7
// Output:
// [[1,2,4]]

// Example 2:
// Input: k = 3, n = 9
// Output:
// [[1,2,6], [1,3,5], [2,3,4]]

#include <vector>

using namespace std;

void BackTracking(vector<vector<int>> &combinations, vector<int> &cur, int k, int n, int begin) {
    if (k == 0 || begin == 10) {
        if (k == 0 && n == 0)
            combinations.push_back(cur);
        return;
    }
    --k;
    for (int i = begin; i < 10; ++i) {
        cur.push_back(i);
        BackTracking(combinations, cur, k, n - i, i + 1);
        cur.pop_back();
    }
}

vector<vector<int>> CombinationSumIII(int k, int n) {
    vector<vector<int>> combinations;
    vector<int> cur;
    BackTracking(combinations, cur, k, n, 1);
    return combinations;
}
