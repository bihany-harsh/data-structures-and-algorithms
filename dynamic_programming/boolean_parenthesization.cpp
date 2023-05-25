#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int number_of_true_evaluations_rec(string &s, int i, int j, bool is_true)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (is_true == true)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    int ans = 0;
    for (int k = i + 1; k < j; k = k + 2)
    {
        int left_T = number_of_true_evaluations_rec(s, i, k - 1, true);
        int left_F = number_of_true_evaluations_rec(s, i, k - 1, false);
        int right_T = number_of_true_evaluations_rec(s, k + 1, j, true);
        int right_F = number_of_true_evaluations_rec(s, k + 1, j, false);
        if (s[k] == '|')
        {
            if (is_true == true)
                ans = ans + left_T * right_T + left_T * right_F + left_F * right_T;
            else
                ans = ans + left_F * right_F;
        }
        else if (s[k] == '&')
        {
            if (is_true == true)
                ans = ans + left_T * right_T;
            else
                ans = ans + left_F * right_F + left_T * right_F + left_F * right_T;
        }
        else if (s[k] == '^')
        {
            if (is_true == true)
                ans = ans + left_T * right_F + left_F * right_T;
            else
                ans = ans + left_T * right_T + left_F * right_F;
        }
        else
        {
            cout << "Invalid operator" << endl;
            exit(0);
        }
    }
    return ans;
}

// ********************************** //

int number_of_true_evaluations_util(string &s, int i, int j, bool is_true, unordered_map<string, int> dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (is_true == true)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    string key = to_string(i) + " " + to_string(j) + " " + to_string(is_true);
    if (dp.find(key) != dp.end())
        return dp[key];
    int ans = 0;

    for (int k = i + 1; k < j; k = k + 2)
    {
        int left_T, left_F, right_T, right_F;
        if (dp.find(to_string(i) + " " + to_string(k - 1) + " " + to_string(true)) != dp.end())
            left_T = dp[to_string(i) + " " + to_string(k - 1) + " " + to_string(true)];
        else
        {
            left_T = number_of_true_evaluations_util(s, i, k - 1, true, dp);
            dp[to_string(i) + " " + to_string(k - 1) + " " + to_string(true)] = left_T;
        }
        if (dp.find(to_string(i) + " " + to_string(k - 1) + " " + to_string(false)) != dp.end())
            left_F = dp[to_string(i) + " " + to_string(k - 1) + " " + to_string(false)];
        else
        {
            left_F = number_of_true_evaluations_util(s, i, k - 1, false, dp);
            dp[to_string(i) + " " + to_string(k - 1) + " " + to_string(false)] = left_F;
        }
        if (dp.find(to_string(k + 1) + " " + to_string(j) + " " + to_string(true)) != dp.end())
            right_T = dp[to_string(k + 1) + " " + to_string(j) + " " + to_string(true)];
        else
        {
            right_T = number_of_true_evaluations_util(s, k + 1, j, true, dp);
            dp[to_string(k + 1) + " " + to_string(j) + " " + to_string(true)] = right_T;
        }
        if (dp.find(to_string(k + 1) + " " + to_string(j) + " " + to_string(false)) != dp.end())
            right_F = dp[to_string(k + 1) + " " + to_string(j) + " " + to_string(false)];
        else
        {
            right_F = number_of_true_evaluations_util(s, k + 1, j, false, dp);
            dp[to_string(k + 1) + " " + to_string(j) + " " + to_string(false)] = right_F;
        }
        if (s[k] == '|')
        {
            if (is_true == true)
                ans = ans + left_T * right_T + left_T * right_F + left_F * right_T;
            else
                ans = ans + left_F * right_F;
        }
        else if (s[k] == '&')
        {
            if (is_true == true)
                ans = ans + left_T * right_T;
            else
                ans = ans + left_F * right_F + left_T * right_F + left_F * right_T;
        }
        else if (s[k] == '^')
        {
            if (is_true == true)
                ans = ans + left_T * right_F + left_F * right_T;
            else
                ans = ans + left_T * right_T + left_F * right_F;
        }
        else
        {
            cout << "Invalid operator" << endl;
            exit(0);
        }
    }
    dp[key] = ans;
    return ans;
}

int number_of_true_evaluations_memoized(string &s, int i, int j, bool is_true)
{
    // either we manage a 3D dp array (i * j * is_true) or we use a map
    unordered_map<string, int> dp;

    return number_of_true_evaluations_util(s, i, j, is_true, dp);
}


int main()
{
    string s = "T^F&T";
    cout << number_of_true_evaluations_rec(s, 0, s.length() - 1, true) << endl;
    cout << number_of_true_evaluations_memoized(s, 0, s.length() - 1, true) << endl;
    return 0;
}