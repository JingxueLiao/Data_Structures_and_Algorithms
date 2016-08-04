// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

#include <string>
#include <vector>
#include <cstddef>

using namespace std;

string SimplifyPath(const string &path) {
    if (path.empty() || path[0] != '/')
        return string();
    vector<string> paths;
    size_t i = 0;
    while (i < path.size()) {
        while (i < path.size() && path[i] == '/')
            ++i;
        size_t j = i;
        while (j < path.size() && path[j] != '/')
            ++j;
        if (i == j)
            break;
        string cur = path.substr(i, j - i);
        if (cur != "." && cur != "..")
            paths.push_back(cur);
        else if (cur == ".." && !paths.empty())
            paths.pop_back();
        i = j;
    }
    string simplify_path;
    for (auto p = paths.begin(); p != paths.end(); ++p) {
        simplify_path.push_back('/');
        simplify_path += *p;
    }
    if (simplify_path.empty())
        simplify_path.push_back('/');
    return simplify_path;
}
