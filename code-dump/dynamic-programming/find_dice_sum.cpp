#include <iostream>
using namespace std;

int number_of_ways_rec(int num_of_dice, int sides_in_die, int sum)
{
    if (sum < 0)
        return 0;
    if (sum < num_of_dice)
        return 0;
    if (num_of_dice == 0)
        return sum == 0 ? 1 : 0;
    if (num_of_dice == 1)
    {
        if (sum <= sides_in_die)
            return 1;
        else
            return 0;
    }

    int total_ways = 0;

    for (int i = 1; i <= sides_in_die; i++)
    {
        total_ways += number_of_ways_rec(num_of_dice - 1, sides_in_die, sum - i);
    }

    return total_ways;
}

int number_of_ways_dp(int num_of_dice, int sides_in_dice, int sum)
{
    const int mod = 1e9 + 7;
    int **dp = new int *[num_of_dice + 1];
    for (int i = 0; i < num_of_dice + 1; i++)
        dp[i] = new int[sum + 1];

    for (int i = 0; i < num_of_dice + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = i == 0 ? 1 : 0;
            else if (i == 1)
                dp[i][j] = j <= sides_in_dice ? 1 : 0;
            else
            {
                int total_ways = 0;
                for (int k = 1; k <= sides_in_dice; k++)
                {
                    if (j - k >= 0)
                        total_ways = (total_ways % mod + dp[i - 1][j - k] % mod) % mod;
                }
                dp[i][j] = total_ways;
            }
        }
    }

    return dp[num_of_dice][sum] % mod;
}

int main()
{
    cout << number_of_ways_rec(2, 4, 5) << endl;
    cout << number_of_ways_dp(68, 75, 81) << endl;

    return 0;
}