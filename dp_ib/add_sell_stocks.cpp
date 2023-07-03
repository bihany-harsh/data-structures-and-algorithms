#include <iostream>
#include <vector>
using namespace std;

int max_profit_rec_util (const vector<int> &prices, int index, bool buy)
{
    if (index >= prices.size())
        return 0;
    if (buy)
        return max(max_profit_rec_util(prices, index + 1, false) - prices[index], max_profit_rec_util(prices, index + 1, true));
    else
        return max(max_profit_rec_util(prices, index + 1, true) + prices[index], max_profit_rec_util(prices, index + 1, false));
}

int max_profit_rec(const vector<int> &prices)
{
    int index = 0;
    bool buy = true;
    return max_profit_rec_util(prices, index, buy);
}

int max_profit_memo_util(const vector<int> &prices, int index, bool buy, vector<vector<int>> &dp)
{
    if (index >= prices.size())
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];
    if (buy)
        dp[index][buy] = max(max_profit_memo_util(prices, index + 1, false, dp) - prices[index], max_profit_memo_util(prices, index + 1, true, dp));
    else
        dp[index][buy] = max(max_profit_memo_util(prices, index + 1, true, dp) + prices[index], max_profit_memo_util(prices, index + 1, false, dp));
    return dp[index][buy];
}

int max_profit_memo(const vector<int> &prices)
{
    int index = 0;
    bool buy = true;
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    return max_profit_memo_util(prices, index, buy, dp);
}

int main()
{
    vector<int> prices = {5, 2, 10};
    cout << max_profit_rec(prices) << endl;
    cout << max_profit_memo(prices) << endl;
    return 0;
}
