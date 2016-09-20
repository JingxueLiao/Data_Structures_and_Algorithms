// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

// For example,
// 123 -> "One Hundred Twenty Three"
// 12345 -> "Twelve Thousand Three Hundred Forty Five"
// 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

#include <string>
#include <vector>

using namespace std;

string NumberToWords(int num) {
    if (num == 0)
        return "Zero";
    static vector<string> below_twenty{ "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
    static vector<string> below_hundred{ "", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety" };
    static vector<string> thousands{ "", " Thousand", " Million", " Billion" };
    string number;
    int i = 0;
    while (num) {
        int cur = num % 1000;
        if (cur)
            number = (cur / 100 ? below_twenty[cur / 100] + " Hundred" : "") + (cur % 100 < 20 ? below_twenty[cur % 100] : below_hundred[cur % 100 / 10] +  below_twenty[cur % 10]) + thousands[i] + number;
        num /= 1000;
        ++i;
    }
    return number.substr(1);
}
