#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int longest_palindromic_substring(string A)
// {
//     vector<vector<int>> dp(A.size() + 1, vector<int>(A.size() + 1, 0));
//     int max_length = 0;
//     for (int i = 0; i < A.size() + 1; i++)
//     {
//         for (int j = 0; j < A.size() + 1; j++)
//         {
//             if (i == 0 || j == 0)
//             {
//                 dp[i][j] = 0;
//             }
//             else if (A[i - 1] == A[A.size() - j])
//             {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//                 max_length = max(max_length, dp[i][j]);
//             }
//             else
//             {
//                 dp[i][j] = 0;
//             }
//         }
//     }
//     return max_length;
// }

string longest_palindromic_substring(string A)
{
    int n = A.size();
    if(n == 0) return "";
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)
        dp[i][i] = true;

    string ans = "";
    ans += A[0];

    for(int len = 2; len <= n; len++) {
        for(int start = 0; start < n; start++) {
            int end = start + len - 1;
            if(end >= n) // substring out of range
                break;
            if(len == 2) // substring length is 2
                dp[start][end] = (A[start] == A[end]);
            else // substring length > 2
                dp[start][end] = (A[start] == A[end]) && dp[start + 1][end - 1];

            // update longest palindromic substring
            if(dp[start][end] && len > ans.size())
                ans = A.substr(start, len);
        }
    }
    return ans;
}