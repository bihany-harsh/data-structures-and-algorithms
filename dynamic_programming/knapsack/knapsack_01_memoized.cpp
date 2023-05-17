#include <iostream>
using namespace std;

int knapsack_01_rec(int *val, int *wt, int W, int n, int **dp)
{
    if (n <= 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (wt[n] <= W)
    {
        dp[n][W] = max((val[n] + knapsack_01_rec(val, wt, W - wt[n], n - 1, dp)),
                       knapsack_01_rec(val, wt, W, n - 1, dp));
        return dp[n][W];
    }
    else
    {
        dp[n][W] = knapsack_01_rec(val, wt, W, n - 1, dp);
        return dp[n][W];
    }
}

int knapsack_01(int *val, int *wt, int W, int n)
{
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[W + 1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            dp[i][j] = -1;
        }
    }

    return knapsack_01_rec(val, wt, W, n - 1, dp);
}

int main()
{
    int n, W;
    cin >> n >> W;
    int *wt = new int [n];
    int *val = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << knapsack_01(val, wt, W, n) << endl;
    return 0;
}