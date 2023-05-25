#include <iostream>
#include <climits>
using namespace std;

int optimal_bst_cost_rec_util(int *keys, int *freq, int i, int j)
{
    if (i > j)
        return 0;

    if (i == j)
        return freq[i];

    int freq_sum = 0;
    for (int k = i; k <= j; k++)
        freq_sum += freq[k];

    int min = INT_MAX;

    for (int r = i; r <= j; r++)
    {
        int cost_new = optimal_bst_cost_rec_util(keys, freq, i, r - 1) + optimal_bst_cost_rec_util(keys, freq, r + 1, j) + freq_sum;
        if (min > cost_new)
            min = cost_new;
    }

    return min;
}

int optimal_bst_cost_rec(int *keys, int *freq, int n)
{
    return optimal_bst_cost_rec_util(keys, freq, 0, n - 1);
}

// ***************************************************************

int optimal_bst_cost_memoized_util(int *keys, int *freq, int i, int j, int **dp)
{
    if (i > j)
        return 0;

    if (i == j)
        return freq[i];

    if (dp[i][j] != -1)
        return dp[i][j];

    int freq_sum = 0;
    for (int k = i; k <= j; k++)
        freq_sum += freq[k];

    int min = INT_MAX;

    for (int r = i; r <= j; r++)
    {
        int cost_new = optimal_bst_cost_memoized_util(keys, freq, i, r - 1, dp) + optimal_bst_cost_memoized_util(keys, freq, r + 1, j, dp) + freq_sum;
        if (min > cost_new)
        {
            dp[i][j] = cost_new;
            min = cost_new;
        }
    }

    return dp[i][j];
}

int optimal_bst_cost_memoized(int *keys, int *freq, int n)
{
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }

    return optimal_bst_cost_memoized_util(keys, freq, 0, n - 1, dp);
}

int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    cout << optimal_bst_cost_rec(keys, freq, n) << endl;
    cout << optimal_bst_cost_memoized(keys, freq, n) << endl;

    return 0;
}