// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
// 
// For example:
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 

#include <string>
#include <algorithm>

using namespace std;

string ConvertToTitle(int n) {
    if (n <= 0)
        return "";
    string title;
    while (n) {
        title.push_back('A' + (n - 1) % 26);
        n = (n - 1) / 26;
    }
    reverse(title.begin(), title.end());
    return title;
}
