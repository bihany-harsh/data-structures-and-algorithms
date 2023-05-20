#include <iostream>
using namespace std;

int number_of_ways(int *denominations, int n, int sum)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int[sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
            if (i > 0 && j > 0)
            {
                if (denominations[i - 1] <= j)
                    dp[i][j] = dp[i][j - denominations[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int min_number_of_coins(int *denominations, int n, int sum)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int[sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (i == 1)
            {
                for (int j = 1; j < sum + 1; j++)
                {
                    if (j % denominations[0] == 0)
                        dp[1][j] = j / denominations[0];
                    else
                        dp[1][j] = INT_MAX - 1;
                }
            }
            else
            {
                if (denominations[i - 1] <= j)
                    dp[i][j] = min((1 + dp[i][j - denominations[i - 1]]), dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}