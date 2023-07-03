// given an array of elements, we can merge 2 adjacent cells, incurring a cost of the sum of these cells. Find min possible cost
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min_merger_memo_util(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = INT_MAX;
    int sum = 0;
    for (int k = i; k <= j; k++)
        sum += arr[k];
    for (int k = i + 1; k <= j; k++)
    {
        dp[i][j] = min(dp[i][j], sum + min_merger_memo_util(arr, i, k - 1, dp) + min_merger_memo_util(arr, k, j, dp));
    }
    return dp[i][j];
}

int min_merger_memo(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return min_merger_memo_util(arr, 0, n - 1, dp);
}

int main()
{
    vector<int> arr = {1, 3, 7};
    cout << min_merger_memo(arr) << endl;

    return 0;
}