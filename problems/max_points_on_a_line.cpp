// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

#include <vector>
#include <utility>
#include <functional>
#include <unordered_map>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) { }
    Point(int a, int b) : x(a), y(b) { }
};

class PairHash {
public:
    size_t operator()(const pair<int, int> &x) const {
        return handler(x.first) ^ handler(x.second);
    }

private:
    hash<int> handler;
};

int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int MaxPoints(const vector<Point> &points) {
    int max_points = 0;
    for (int i = 0; i < points.size(); ++i) {
        unordered_map<pair<int, int>, int, PairHash> nums;
        int overlap = 1;
        int cur_max = 0;
        for (int j = i + 1; j < points.size(); ++j) {
            int x = points[i].x - points[j].x;
            int y = points[i].y - points[j].y;
            if (x == 0 && y == 0) {
                ++overlap;
                continue;
            } else if (x == 0) {
                y = 1;
            } else if (y == 0) {
                x = 1;
            } else {
                int d = gcd(x, y);
                x /= d;
                y /= d;
            }
            if (cur_max < ++nums[make_pair(x, y)])
                cur_max = nums[make_pair(x, y)];
        }
        if (max_points < cur_max + overlap)
            max_points = cur_max + overlap;
    }
    return max_points;
}
