// problem is to find the min number of jumps to reach the last index of an array,
// given initial position is the first index, and the amount one can jump is
// equal to the value at that position of the array
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min_jumps_array_rec_util(vector<int> &arr, int index)
{
    int n = arr.size();
    if (index >= n)
        return INT_MAX - 1;
    if (index == n - 1)
        return 0;
    int min_ = INT_MAX - 1;
    for (int i = 1; i <= arr[index]; i++)
    {
        min_ = min(min_, 1 + min_jumps_array_rec_util(arr, index + i));
    }
    return min_;
}

int min_jumps_array_rec(vector<int> &arr)
{
    int index = 0;
    int res = min_jumps_array_rec_util(arr, index);
    if (res >= INT_MAX - 1)
        return -1;
    else
        return res;
}

int min_jumps_array_memo_util(vector<int> &arr, int index, vector<int> &dp)
{
    int n = arr.size();
    if (index >= n)
        return INT_MAX - 1;
    if (index == n - 1)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    dp[index] = INT_MAX - 1;
    for (int i = 1; i <= arr[index]; i++)
    {
        dp[index] = min(dp[index], 1 + min_jumps_array_memo_util(arr, index + i, dp));
    }
    return dp[index];
}

int min_jumps_array_memo(vector<int> &arr)
{
    int index = 0;
    vector<int> dp(arr.size(), -1);
    int res = min_jumps_array_memo_util(arr, index, dp);
    if (res >= INT_MAX - 1)
        return -1;
    else 
        return res;
}

int main()
{
    // vector<int> arr = {33, 21, 50, 0, 0, 46, 34, 3, 0, 12, 33, 0, 31, 37, 15, 17, 34, 18, 0, 4, 12, 41, 18, 35, 37, 34, 0, 47, 0, 39, 32, 49, 5, 41, 46, 26, 0, 2, 49, 35, 4, 19, 2, 27, 23, 49, 19, 38, 0, 33, 47, 1, 21, 36, 18, 33, 0, 1, 0, 39, 0, 22, 0, 9, 36, 45, 31, 4, 14, 48, 2, 33, 0, 39, 0, 37, 48, 44, 0, 11, 24, 16, 10, 23, 22, 41, 32, 14, 22, 16, 23, 38, 42, 16, 15, 0, 39, 23, 0, 42, 15, 25, 0, 41, 2, 48, 28};
    vector<int> arr = {0};
    // cout << min_jumps_array_rec(arr) << endl;
    cout << min_jumps_array_memo(arr) << endl;
    return 0;
}