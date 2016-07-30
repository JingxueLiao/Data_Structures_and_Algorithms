// Implement pow(x, n).

double Pow(double x, int n) {
    long long exp = n;
    exp = exp < 0 ? -exp : exp;
    double result = 1;
    while (exp) {
        result = exp & 1 ? result * x : result;
        exp >>= 1;
        x = x * x;
    }
    result = n < 0 ? 1 / result : result;
    return result;
}
