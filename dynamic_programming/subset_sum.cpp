#include <iostream>
using namespace std;

bool subset_sum_exists(int *arr, int sum, int n)
{
    bool **dp = new bool *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new bool[sum + 1];
    
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
            if (i > 0 && j > 0)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int count_subset_sum(int *arr, int sum, int n)
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
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    // subset sum problem
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subset_sum_exists(arr, sum, n) << " Number of subsets: " << count_subset_sum(arr, sum, n) << endl;
    return 0;
}