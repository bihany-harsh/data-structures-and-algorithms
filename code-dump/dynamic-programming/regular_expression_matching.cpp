#include <iostream>
#include <cstring>
using namespace std;

int reg_match_util(string A, string B, int index1, int index2)
{
    int n = A.length();
    int m = B.length();
    if (A.substr(index1, n - index1) == B.substr(index2, m - index2))
        return 1;
    if (index1 >= n || index2 >= m)
        return 0;
    
    if (A[index1] == B[index2])
        return reg_match_util(A, B, index1 + 1, index2 + 1);
    else if (B[index2] == '?')
        return reg_match_util(A, B, index1 + 1, index2 + 1);
    else if (B[index2] == '*')
    {
        if (index2 == m - 1)
            return 1;
        else 
        {
            for (int i = index1; i < n; i++)
            {
                if (reg_match_util(A, B, i, index2 + 1))
                    return 1;
            }
            return 0;
        }
    }
    else
        return 0;
}

int reg_match(string A, string B)
{
    return reg_match_util(A, B, 0, 0);
}

// ############################################

int reg_match_dp(string A, string B)
{
    int n = A.length();
    int m = B.length();

    int **dp = new int*[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[m + 1];
        memset(dp[i], 0, sizeof(int) * (m + 1));
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (j == 0)
                dp[i][j] = 0;
            else if (i == 0)
            {
                if (B[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
            else 
            {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (B[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (B[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
    }

    return dp[n][m];
}


int main()
{
    string A = "baaabab";
    string B = "****";

    cout << reg_match(A, B) << endl;
    cout << reg_match_dp(A, B) << endl;
}