#include <iostream>
using namespace std;

int unbounded_knapsack(int *val, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[n + 1];
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j >= i)
            {
                dp[i][j] = max((val[i - 1] + dp[i][j - i]), dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][n];
}

int main()
{
    int n;
    cin >> n;
    int *val = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << unbounded_knapsack(val, n) << endl;
    return 0;
}