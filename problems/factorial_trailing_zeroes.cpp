// Given an integer n, return the number of trailing zeroes in n!.
// Note: Your solution should be in logarithmic time complexity.

int TrailingZeroes(int n) {
    int zeroes = 0;
    while (n) {
        n /= 5;
        zeroes += n;
    }
    return zeroes;
}
