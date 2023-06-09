#include <iostream>
#include <string>
using namespace std;

int ways_to_decode_recursive(string A)
{
    if (A.length() == 0)
        return 1;
    if (A[0] == '0')
        return 0;
    int n = A.length();
    int count = 0;
    if (n >= 2 && stoi(A.substr(0, 2)) <= 26)
        count += ways_to_decode_recursive(A.substr(2));
    count += ways_to_decode_recursive(A.substr(1));
    return count;
}

int ways_to_decode_dp(string A)
{
    int n = A.length();
    int *dp = new int[n + 1];

    dp[0] = 1;

    for(int i = 1; i < n + 1; i++)
    {
        dp[i] = 0;
        if (A[i - 1] != '0')
            dp[i] = dp[i - 1];
        if (i >= 2 && stoi(A.substr(i - 2, 2)) <= 26 && stoi(A.substr(i - 2, 2)) >= 10)
            dp[i] += dp[i - 2];
    }

    return dp[n];
}

int main()
{
    string A = "12";
    cout << ways_to_decode_recursive(A) << endl;
    cout << ways_to_decode_dp(A) << endl;
    return 0;
}