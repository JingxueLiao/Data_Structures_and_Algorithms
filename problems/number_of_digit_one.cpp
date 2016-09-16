// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

// For example:
// Given n = 13,
// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

int CountDigitOne(int n) {
	if (n <= 0)
		return 0;
    int total = 0;
    int base = 1;
    while (n / base) {
        total += n / base / 10 * 10;
        if (n / base % 10 == 1)
            total += n % base + 1;
        else if (n / base % 10 > 1)
            total += base;
        base *= 10;
    }
    return total;
}
