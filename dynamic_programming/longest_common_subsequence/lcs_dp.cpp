#include <iostream>
#include <string>
using namespace std;

int longest_lcs(string &s1, string &s2, int n, int m)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[m + 1];
    }
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < m + 1; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longest_lcs(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}