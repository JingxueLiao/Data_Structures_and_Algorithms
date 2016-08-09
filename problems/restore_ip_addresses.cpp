// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// For example:
// Given "25525511135",
// return ["255.255.11.135", "255.255.111.35"].

#include <string>
#include <vector>

using namespace std;

void helper(vector<string> &addresses, string cur, const string &s, int begin, int index) {
    if (begin == s.size() && index == 5)
        addresses.push_back(cur);
    if (begin == s.size() || index == 5)
        return;
    if (index != 1)
        cur.push_back('.');
    for (int i = 1; i <= 3 && begin + i <= s.size(); ++i) {
        if (i < 3 || stoi(s.substr(begin, i)) <= 255)  
            helper(addresses, cur + s.substr(begin, i), s, begin + i, index + 1);
        if (i == 1 && s[begin] == '0')
            break;
    }
    if (index != 1)
        cur.pop_back();
}

vector<string> RestoreIpAddresses(const string &s) {
    vector<string> addresses;
    string cur;
    helper(addresses, cur, s, 0, 1);
    return addresses;
}
