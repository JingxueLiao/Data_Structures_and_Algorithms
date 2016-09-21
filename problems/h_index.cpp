// Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
// According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
// For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.
// Note: If there are several possible values for h, the maximum one is taken as the h-index.

#include <vector>

using namespace std;

int HIndex(const vector<int> &citations) {
    int n = citations.size();
    vector<int> counts(n + 1);
    for (auto p = citations.begin(); p != citations.end(); ++p) {
        if (*p > n)
            ++counts[n];
        else
            ++counts[*p];
    }
    int sum = 0, h = n;
    while (h >= 0) {
        sum += counts[h];
        if (sum >= h)
            break;
        --h;
    }
    return h;
}
