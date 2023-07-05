#include <iostream>
#include <string>
#include <vector>
using namespace std;

// the number of ways the second sequence is a part of the first sequence
int ways_rec_util(string A, string B, int i, int j)
{
    if (j >= B.size())
        return 1;
    if (i >= A.size())
        return 0;

    if (A[i] == B[j])
        return ways_rec_util(A, B, i + 1, j + 1) + ways_rec_util(A, B, i + 1, j);

    return ways_rec_util(A, B, i + 1, j);    
}

int ways_rec(string A, string B)
{
    return ways_rec_util(A, B, 0, 0);
}

int ways_dp(string A, string B)
{
    int n = A.size();
    int m = B.size();

    if (n < m)
        return 0;
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}

int main()
{
    cout << ways_rec("abbbac", "abc") << endl;
    cout << ways_dp("abbbac", "abc") << endl;
    return 0;
}