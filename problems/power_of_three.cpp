// Given an integer, write a function to determine if it is a power of three.

// Follow up:
// Could you do it without using any loop / recursion?

bool IsPowerOfThree(int n) {
    return 1162261467 % n == 0;
}
