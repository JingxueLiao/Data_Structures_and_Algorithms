// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows

#include <string>

using namespace std;

string Convert(const string &s, int numRows) {
    if (numRows == 1)
        return s;
    string result(s.size(), 0);
    int period = numRows * 2 - 2;
    int i = 0;
    for (int j = 0; j < numRows; ++j) {
        int k = j;
        while (k < s.size()) {
            result[i++] = s[k];
            k += period - 2 * j;
            if (k < s.size() && j != 0 && j != numRows - 1)
                result[i++] = s[k];
            k += 2 * j;
        }
    }
    return result;
}
