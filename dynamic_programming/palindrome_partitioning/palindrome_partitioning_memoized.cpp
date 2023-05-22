#include <iostream>
#include <string>
#include <climits>
using namespace std;

bool is_palindrome(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int palindrome_partitioning_util(string &s, int i, int j, int **dp)
{
    if (i >= j)
        return 0;
    if (is_palindrome(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = 1 + palindrome_partitioning_util(s, i, k, dp) + palindrome_partitioning_util(s, k + 1, j, dp);
        if (temp < min)
            min = temp;
    }
    dp[i][j] = min;
    return dp[i][j];
}

int palindrome_partitioning(string &s, int i, int j)
{
    int n = s.length();
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            dp[i][j] = -1;
    }

    int res = palindrome_partitioning_util(s, i, j, dp);

    return res;
}

int main()
{
    string s = "ababbbabbababa";
    cout << palindrome_partitioning(s, 0, s.length() - 1) << endl;
    return 0;
}