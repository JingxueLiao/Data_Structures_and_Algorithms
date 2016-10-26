// Write a program to find the nth super ugly number.

// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

// Note:
// (1) 1 is a super ugly number for any given primes.
// (2) The given numbers in primes are in ascending order.
// (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Comp {
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return b.first < a.first;
    }
};

int NthSuperUglyNumber(int n, const vector<int> &primes) {
    if (n <= 0 || primes.empty())
        return 0;
    vector<int> superUglyNumbers(n);
    vector<int> indexes(primes.size());
    superUglyNumbers[0] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> candidates;
    for (int i = 0; i < primes.size(); ++i)
        candidates.push(make_pair(primes[i], i));
    for (int i = 1; i < n; ++i) {
        superUglyNumbers[i] = candidates.top().first;
        while (candidates.top().first == superUglyNumbers[i]) {
            int j = candidates.top().second;
            candidates.pop();
            candidates.push(make_pair(primes[j] * superUglyNumbers[++indexes[j]], j));
        }
    }
    return superUglyNumbers[n - 1];
}
