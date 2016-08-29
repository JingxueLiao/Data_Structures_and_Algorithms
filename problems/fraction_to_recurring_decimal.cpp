// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
// If the fractional part is repeating, enclose the repeating part in parentheses.

// For example,
// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".

#include <string>
#include <unordered_map>

using namespace std;

string FractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
        return "0";
    if (denominator == 0)
        return "";
    string result;
    if (numerator < 0 ^ denominator < 0)
        result.push_back('-');
    long long numer = numerator, denom = denominator;
    numer = numer < 0 ? - numer : numer;
    denom = denom < 0 ? - denom : denom;
    result += to_string(numer / denom);
    if (numer % denom == 0)
        return result;
    result.push_back('.');
    unordered_map<int, int> positions;
    numer %= denom;
    while (numer) {
        positions[numer] = result.size();
        numer *= 10;
        result.push_back('0' + numer / denom);
        numer %= denom;
        if (positions.find(numer) != positions.end()) {
            result.insert(result.begin() + positions[numer], '(');
            result.push_back(')');
            break;
        }
    }
    return result;
}
