#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int longest_palindromic_subsequence(string &s, int n)
{
    string s2 = s;
    reverse(s.begin(), s.end());
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < n + 1; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int main()
{
    string s;
    cin >> s;
    cout << longest_palindromic_subsequence(s, s.length()) << endl;
    return 0;
}