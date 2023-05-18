#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min_subset_diff(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];  

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

    vector<int> v;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n][i])
            v.push_back(i);
    }

    int min_diff = INT_MAX;

    for (int i = 0; i < v.size(); i++)
    {
        min_diff = min(min_diff, sum - 2 * v[i]);
    }

    return min_diff;
}

int main()
{
    int arr[] = {1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << min_subset_diff(arr, n) << endl;
    return 0;
}