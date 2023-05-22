#include <iostream>
#include <climits>
#include <utility>
using namespace std;

pair<int **, int **> MCM(int *arr, int n)
{
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[n];

    int **s = new int *[n];
    for (int i = 0; i < n; i++)
        s[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
        s[i][i] = 0;
    }

    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    return make_pair(dp, s);
}

void printOptimalParenthesis(int **s, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int arr[] = {5, 10, 3, 12, 5, 50, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    pair<int **, int **> p = MCM(arr, n);
    printOptimalParenthesis(p.second, 1, n - 1);
    cout << endl;

    // Remember to free allocated memory.
    for (int i = 0; i < n; ++i) {
        delete [] p.first[i];
        delete [] p.second[i];
    }
    delete [] p.first;
    delete [] p.second;

    return 0;
}
