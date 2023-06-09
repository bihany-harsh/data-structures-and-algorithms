#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int solve_rec_util(int N, int S, bool first_time)
{
    if (S < 0)
        return 0;
    if (N == 0 || N == 1)
        return N;
    if (S == 0)
        return 1;
    if (9 * N < S)
        return 0;

    int count = 0;

    if (first_time)
    {
        for (int i = 1; i <= 9; i++)
            count += solve_rec_util(N - 1, S - i, false);
    }
    else
    {
        for (int i = 0; i <= 9; i++)
            count += solve_rec_util(N - 1, S - i, false);
    }

    return count;
}

int solve_rec(int N, int S)
{
    // N -> number of digits
    // S -> sum
    // return the number of N digit numbers with sum S
    return solve_rec_util(N, S, true);
}

// ############################

int solve_rec_memo_util(int N, int S, bool first_time, int **dp)
{
    if (S < 0)
        return 0;
    if (N == 0 || N == 1)
        return N;
    if (S == 0)
        return 1;
    if (9 * N < S)
        return 0;

    if (dp[N][S] != -1)
        return dp[N][S] % mod;

    int count = 0;

    if (first_time)
    {
        for (int i = 1; i <= 9; i++)
            count = (count % mod + solve_rec_memo_util(N - 1, S - i, false, dp) % mod) % mod;
    }
    else
    {
        for (int i = 0; i <= 9; i++)
            count = (count % mod + solve_rec_memo_util(N - 1, S - i, false, dp) % mod) % mod;
    }

    dp[N][S] = count % mod;
    return count % mod;
}

int solve_rec_memo(int N, int S)
{
    int **dp = new int *[N + 1];
    for (int i = 0; i <= N; i++)
        dp[i] = new int[S + 1];

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= S; j++)
            dp[i][j] = -1;

    return solve_rec_memo_util(N, S, true, dp);
}

int main()
{
    int N = 75, S = 22;
    // cout << solve_rec(N, S) << endl;
    cout << solve_rec_memo(N, S) << endl;
    
    return 0;
}