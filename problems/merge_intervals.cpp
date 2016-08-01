// Given a collection of intervals, merge all overlapping intervals.

// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Comp {
public:
    bool operator()(const Interval &a, const Interval &b) const {
        return a.start < b.start;
    }
};

vector<Interval> Merge(vector<Interval> &intervals) {
    if (intervals.empty())
        return vector<Interval>();
    sort(intervals.begin(), intervals.end(), Comp());
    vector<Interval> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (result.back().end < intervals[i].start) {
            result.push_back(intervals[i]);
        } else if (result.back().end < intervals[i].end) {
            result.back().end = intervals[i].end;
        }
    }
    return result;
}
