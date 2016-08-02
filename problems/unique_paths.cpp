// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?

int UniquePaths(int m, int n) {
    if (m <= 0 || n <= 0)
        return 0;
    if (m == 1 && n == 1)
        return 1;
    m -= 1;
    n -= 1;
    long long path = 1;
    int t = m < n ? m : n;
    for (int i = 0; i < t; ++i)
        path *= m + n - i;
    for (int i = 1; i <= t; ++i)
        path /= i;
    return path;
}
