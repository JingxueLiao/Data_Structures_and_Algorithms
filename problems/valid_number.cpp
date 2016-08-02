// Validate if a given string is numeric.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// Note: It is intended for the problem statement to be ambiguous.
// You should gather all requirements up front before implementing one.

#include <string>

using namespace std;

bool IsNumber(const string &s) {
    int i = 0;
    while (i < s.size() && s[i] == ' ')
        ++i;
    int stage = 0;
    while (i < s.size()) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (stage == 0 || stage == 1)
                stage = 2;
            else if (stage == 3 || stage == 4)
                stage = 5;
            else if (stage == 6 || stage == 7)
                stage = 8;
        } else if ((s[i] == '+' || s[i] == '-') && (stage == 0 || stage == 6)) {
            ++stage;
        } else if (s[i] == '.' && (stage == 0 || stage == 1 || stage == 2)) {
            if (stage == 0 || stage == 1)
                stage = 3;
            else
                stage = 4;
        } else if ((s[i] == 'e' || s[i] == 'E') && (stage == 2 || stage == 4 || stage == 5)) {
            stage = 6;
        } else {
            break;
        }
        ++i;
    }
    while (i < s.size() && s[i] == ' ')
        ++i;
    return i == s.size() && (stage == 2 || stage == 4 || stage == 5 || stage == 8);
}
