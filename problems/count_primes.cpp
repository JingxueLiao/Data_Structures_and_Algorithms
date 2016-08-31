// Count the number of prime numbers less than a non-negative number, n.

#include <vector>

using namespace std;

int CountPrimes(int n) {
    vector<int> primes;
    vector<bool> is_prime(n, true);
    for (int i = 2; i < n; ++i) {
        if (is_prime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
            is_prime[i * primes[j]] =false;
            if (i & primes[j] == 0)
                break;
        }
    }
    return primes.size();
}
