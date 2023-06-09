#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int interleaving_string(string A, string B, string C)
{
    if (C.length() != A.length() + B.length())
        return 0;
    int n = A.length();
    int m = B.length();

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (A[i - 1] == C[i - 1])
            dp[i][0] = dp[i - 1][0];
    }

    for (int j = 1; j <= m; j++)
    {
        if (B[j - 1] == C[j - 1])
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m ; j++)
        {
            if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
                dp[i][j] = dp[i - 1][j];
            else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
                dp[i][j] = dp[i][j - 1];
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }

    return dp[n][m];
}

int main()
{
    string A = "aab";
    string B = "axy";
    string C = "aaxaby";
    cout << interleaving_string(A, B, C) << endl;
    return 0;
}