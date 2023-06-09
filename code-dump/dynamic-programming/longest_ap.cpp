#include <iostream>
#include <vector>
using namespace std;

int longest_ap_brute(vector<int> arr)
{
    int n = arr.size();
    if (n <= 2)
        return n;

    int max_len = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = arr[j] - arr[i];
            int next_elem = arr[j] + diff;
            int len = 2;
            for (int k = j + 1; k < n; k++)
            {
                if (arr[k] == next_elem)
                {
                    len++;
                    next_elem += diff;
                }
            }
            max_len = max(max_len, len);
        }
    }

    return max_len;
}

int longest_ap_dp(vector<int> arr)
{
    int n = arr.size();

    if (n <= 2)
        return n;

    // dp[i][j] stores the length of the longest AP with arr[i] and arr[j] as the first two elements of the AP
    vector<vector<int> > dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
        dp[n - 1][j] = 2;
    
    int max_len = 2;
    
    for (int j = n - 2; j >= 1; j--)
    {
        int i = j - 1;
        int k = j + 1;
        while (i >= 0 && k < n)
        {
            if (arr[i] + arr[k] < 2 * arr[j])
                k++;
            else if (arr[i] + arr[k] > 2 * arr[j])
            {
                dp[i][j] = 2;
                i--;
            }
            else
            {
                dp[i][j] = dp[j][k] + 1;
                max_len = max(max_len, dp[i][j]);
                i--;
                k++;
            }
        }

        while (i >= 0)
        {
            dp[i][j] = 2;
            i--;
        }
    }

    return max_len;
}

int main()
{
    vector<int> arr = {9, 4, 7, 2, 10};
    cout << longest_ap_brute(arr) << endl;
    cout << longest_ap_dp(arr) << endl;
    return 0;
}