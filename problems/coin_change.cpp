// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)

// Example 2:
// coins = [2], amount = 3
// return -1.

// Note:
// You may assume that you have an infinite number of each kind of coin.

#include <vector>
#include <algorithm>

using namespace std;

int CoinChange(const vector<int> &coins, int amount) {
    if (amount <= 0)
        return 0;
    vector<int> minimum_coins(amount + 1, -1);
    minimum_coins[0] = 0;
    for (int i = 0; i < coins.size(); ++i) {
        int coin = coins[i];
        for (int j = coin; j <= amount; ++j) {
            if (minimum_coins[j] != -1 && minimum_coins[j - coin] != -1) {
                minimum_coins[j] = min(minimum_coins[j], minimum_coins[j - coin] + 1);
            } else if (minimum_coins[j - coin] != -1) {
                minimum_coins[j] = minimum_coins[j - coin] + 1;
            }
        }
    }
    return minimum_coins[amount];
}
