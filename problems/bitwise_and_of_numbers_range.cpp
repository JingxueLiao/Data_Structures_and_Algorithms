// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

// For example, given the range [5, 7], you should return 4.

int RangeBitwiseAnd(int m, int n) {
    int result = 0;
    for (int i = 31; i >= 0; --i) {
        if (m >> i & n >> i & 1) {
            result |= 1 << i;
        } else if (m >> i & 1 ^ n >> i & 1) {
            break;
        }
    }
    return result;
}
