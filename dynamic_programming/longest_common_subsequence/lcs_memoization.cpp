#include <iostream>
#include <string>
using namespace std;

int length_of_lcs(string &s1, string &s2, int n, int m)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[m + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
    {
        dp[n][m] = length_of_lcs(s1, s2, n - 1, m - 1) + 1;
        return dp[n][m];
    }
    else
    {
        dp[n][m] = max(length_of_lcs(s1, s2, n - 1, m), length_of_lcs(s1, s2, n, m - 1));
        return dp[n][m];
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << length_of_lcs(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}