// Given an integer, convert it to a roman numeral.

#include <string>

using namespace std;

string IntegerToRoman(int num) {
    if (num <= 0 || num > 3999)
        return string();
    string thousands[] = { "", "M", "MM", "MMM" };
    string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
    return thousands[num / 1000] + hundreds[num /100 % 10] + tens[num / 10 % 10] + ones[num % 10];
}
