// Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

#include <vector>

using namespace std;

int HIndex(const vector<int> &citations) {
    int n = citations.size();
    int low = 0, high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (citations[n - mid] >= mid) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}
