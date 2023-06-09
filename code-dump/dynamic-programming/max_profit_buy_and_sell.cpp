#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

unordered_map<string, int> dp_;

int max_profit_util2(int *arr, int n, int k, int index, int buy)
{
    if (k == 0)
        return 0;
    if (index == n)
        return 0;

    string key = to_string(index) + "_" + to_string(buy) + "_" + to_string(k);
    if (dp_.find(key) != dp_.end())
        return dp_[key];

    int profit = 0;

    if (buy == 0)
    {
        profit = max(max_profit_util2(arr, n, k, index + 1, 0),
                     max_profit_util2(arr, n, k, index + 1, 1) - arr[index]);
    }
    else
    {
        profit = max(max_profit_util2(arr, n, k - 1, index + 1, 0) + arr[index],
                     max_profit_util2(arr, n, k, index + 1, 1));
    }

    dp_[key] = profit;
    return profit;
}

// ############################################
int max_profit_util(int *arr, int n, int k, int index, int buy)
{
    if (k == 0)
        return 0;
    if (index == n)
        return 0;

    int profit = 0;

    if (buy == 0)
    {
        profit = max(max_profit_util(arr, n, k, index + 1, 0),
                     max_profit_util(arr, n, k, index + 1, 1) - arr[index]);
    }
    else
    {
        profit = max(max_profit_util(arr, n, k - 1, index + 1, 0) + arr[index],
                     max_profit_util(arr, n, k, index + 1, 1));
    }

    return profit;
}

int max_profit(int *arr, int n, int k)
{
    return max_profit_util2(arr, n, k, 0, 0);
}

// ############################################

unordered_map<string, int> dp;

int max_profit_util2_alt(vector<int>&arr, int n, int k, int index, int buy)
{
    if (k == 0)
        return 0;
    if (index == n)
        return 0;

    string key = to_string(index) + "_" + to_string(buy) + "_" + to_string(k);
    if (dp.find(key) != dp.end())
        return dp[key];

    int profit = 0;

    if (buy == 0)
    {
        profit = max(max_profit_util2_alt(arr, n, k, index + 1, 0),
                     max_profit_util2_alt(arr, n, k, index + 1, 1) - arr[index]);
    }
    else
    {
        profit = max(max_profit_util2_alt(arr, n, k - 1, index + 1, 0) + arr[index],
                     max_profit_util2_alt(arr, n, k, index + 1, 1));
    }

    dp[key] = profit;
    return profit;
}

int solve(vector<int> &A, int k) {   

    return max_profit_util2_alt(A, A.size(), k, 0, 0);
}


// ############################################

int max_profit_dp_util(int *arr, int n, int k, int index, int buy, int ***dp)
{
    if (k == 0)
        return 0;
    if (index == n)
        return 0;

    if (dp[index][k][buy] != -1)
        return dp[index][k][buy];

    int profit = 0;

    if (buy == 0)
    {
        profit = max(max_profit_dp_util(arr, n, k, index + 1, 0, dp),
                     max_profit_dp_util(arr, n, k, index + 1, 1, dp) - arr[index]);
    }
    else
    {
        profit = max(max_profit_dp_util(arr, n, k - 1, index + 1, 0, dp) + arr[index],
                     max_profit_dp_util(arr, n, k, index + 1, 1, dp));
    }

    dp[index][k][buy] = profit;
    return profit;
}

int max_profit_dp(int *arr, int n, int k)
{
    int ***dp = new int **[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int *[k + 1];
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = new int[2];
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }

    return max_profit_dp_util(arr, n, k, 0, 0, dp);
}

int main()
{
    int arr[] = {1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << max_profit(arr, n, k) << endl;
    cout << max_profit_dp(arr, n, k) << endl;

    vector<int> A = {1, 2};

    cout << solve(A, k) << endl;

    return 0;
}