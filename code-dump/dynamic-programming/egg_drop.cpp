#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int egg_drop_rec(int eggs, int height)
{
    if (eggs == 1)
        return height;
    if (height <= 1)
        return height;

    int min_ = INT_MAX;

    for (int k = 1; k <= height; k++)
    {
        int res = 1 + max(egg_drop_rec(eggs - 1, k - 1), egg_drop_rec(eggs, height - k));
        if (res < min_)
            min_ = res;
    }
    return min_;
}

int egg_drop_memo_util(int eggs, int height, vector<vector<int>> &dp)
{
    if (eggs == 1)
        return height;
    if (height <= 1)
        return height;
    if (dp[eggs][height] != -1)
        return dp[eggs][height];
    
    dp[eggs][height] = INT_MAX;
    for (int k = 1; k <= height; k++)
    {
        int l, h;

        if (dp[eggs - 1][k - 1] != -1)
            l = dp[eggs - 1][k - 1];
        else
        {
            l = egg_drop_memo_util(eggs - 1, k - 1, dp);
            dp[eggs - 1][k - 1] = l;
        }
        if (dp[eggs][height - k] != -1)
            h = dp[eggs][height - k];
        else
        {
            h = egg_drop_memo_util(eggs, height - k, dp);
            dp[eggs][height - k] = h;
        }

        int res = 1 + max(l, h);
        if (res < dp[eggs][height])
            dp[eggs][height] = res;
    }
    return dp[eggs][height];
}

int egg_drop_memo(int eggs, int height)
{
    vector<vector<int>> dp(eggs + 1, vector<int>(height + 1, -1));
    for (int j = 0; j <= height; j++)
    {
        dp[0][j] = INT_MAX;
        dp[1][j] = j;
    }
    for (int i = 0; i <= eggs; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    return egg_drop_memo_util(eggs, height, dp);
}

int main()
{
    int eggs = 100;
    int height = 10000;
    // cout << egg_drop_rec(eggs, height) << endl;
    cout << egg_drop_memo(eggs, height) << endl;

    return 0;
}