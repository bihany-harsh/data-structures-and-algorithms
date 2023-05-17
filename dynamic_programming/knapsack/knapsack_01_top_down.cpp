#include <iostream>
using namespace std;

int knapsack_01_dp(int *val, int *wt, int W, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[W + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max((val[i - 1] + dp[i - 1][j - wt[i - 1]]), dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
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
    cout << knapsack_01_dp(val, wt, W, n) << endl;
    return 0;
}