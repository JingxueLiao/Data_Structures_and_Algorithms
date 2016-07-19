// Determine whether an integer is a palindrome.
// Do this without extra space.

bool IsPalindrome(int x) {
    if (x < 0 || x != 0 && x % 10 == 0)
        return false;
    int left = x, right = 0;
    while (right <= left) {
        if (left == right || left / 10 == right)
            return true;
        right = right * 10 + left % 10;
        left /= 10;
    }
    return false;
}
