#include <iostream>
#include <stack>
#include <string>
using namespace std;

string shortest_commom_supersequence(string &s1, string &s2, int n, int m)
{
    int **dp = new int* [n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = new int [m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // filling the stack
    stack<char> s;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s.push(s1[i - 1]);
            i--;
            j--;
        }
        else 
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                s.push(s1[i - 1]);
                i--;
            }
            else 
            {
                s.push(s2[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        s.push(s1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        s.push(s2[j - 1]);
        j--;
    }
    string ans = "";
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << shortest_commom_supersequence(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}