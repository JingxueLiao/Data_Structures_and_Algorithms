// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit.
// You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <vector>
#include <algorithm>

using namespace std;

int MaxProfit(int k, const vector<int> &prices) {
    if (k <= 0 || prices.empty())
        return 0;
    if (prices.size() <= k) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
            profit += max(0, prices[i] - prices[i - 1]);
        return profit;
    } else {
        vector<int> profits(prices.size());
        for (int i = 0; i < k; ++i) {
            int buy = -prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                buy = max(buy, profits[j] - prices[j]);
                profits[j] = max(profits[j - 1], buy + prices[j]);
            }
        }
        return profits.back();
    }
}
