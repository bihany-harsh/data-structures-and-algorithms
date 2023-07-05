#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int longest_palin_subseq(string str1)
{
    string str2 = str1;
    int n = str1.size();
    reverse(str1.begin(), str1.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int main()
{
    cout << longest_palin_subseq("bebeeed") << endl;
    return 0;
}