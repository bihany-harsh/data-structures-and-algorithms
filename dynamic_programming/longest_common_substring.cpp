#include <iostream>
#include <string>
using namespace std;

int longest_common_substring(string &s1, string &s2, int n, int m)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int [m + 1];
    int max_length = 0;
    
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_length = max(max_length, dp[i][j]);
            }
            else 
            {
                dp[i][j] = 0;
            }
        }
    }
    return max_length;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longest_common_substring(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}