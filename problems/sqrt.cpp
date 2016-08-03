// Implement int sqrt(int x).
// Compute and return the square root of x.

int Sqrt(int x) {
    if (x < 0)
        return -1;
    int low = 0, high = x;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid < x)
            low = mid + 1;
        else if (x < mid * mid)
            high = mid - 1;
        else
            return mid;
    }
    return high;
}
