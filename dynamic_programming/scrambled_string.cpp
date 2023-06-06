#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool is_scrambled_string_rec(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    
    if (s1.length() == 0)
        return true;
    
    if (s1 == s2)
        return true;

    int n = s1.length();

    for (int i = 1; i < n; i++)
    {
        if (is_scrambled_string_rec(s1.substr(0, i), s2.substr(0, i)) && is_scrambled_string_rec(s1.substr(i, n - i), s2.substr(i, n - i)))
            return true;
        if (is_scrambled_string_rec(s1.substr(0, i), s2.substr(n - i, i)) && is_scrambled_string_rec(s1.substr(i, n - i), s2.substr(0, n - i)))
            return true;        
    }

    return false;
}

// ***********************************

bool is_scrambled_string_util(string s1, string s2, unordered_map<string, bool> dp)
{
    if (s1.length() != s2.length())
        return false;
    
    if (s1.length() == 0)
        return true;
    
    if (s1 == s2)
        return true;
    
    string key = s1 + " " + s2;

    if (dp.find(key) != dp.end())
        return dp[key];
    
    int n = s1.length();

    for (int i = 1; i < n; i++)
    {
        if (is_scrambled_string_rec(s1.substr(0, i), s2.substr(0, i)) && is_scrambled_string_rec(s1.substr(i, n - i), s2.substr(i, n - i)))
        {
            dp[key] = true;
            return true;
        }
        if (is_scrambled_string_rec(s1.substr(0, i), s2.substr(n - i, i)) && is_scrambled_string_rec(s1.substr(i, n - i), s2.substr(0, n - i)))
        {
            dp[key] = true;
            return true;
        }
    }
    dp[key] = false;
    return false;
}

bool is_scrambled_string_memoized(string s1, string s2)
{
    unordered_map<string, bool> dp;
    return is_scrambled_string_util(s1, s2, dp);
}

int main()
{
    string s1, s2;
    s1 = "coder";
    s2 = "ocred";
    cout << is_scrambled_string_rec(s1, s2) << endl;
    cout << is_scrambled_string_memoized(s1, s2) << endl;
    return 0;
}