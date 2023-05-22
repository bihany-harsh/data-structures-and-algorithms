#include <iostream>
#include <string>
#include <climits>
using namespace std;

bool is_palindrome(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int palindrome_partitioning(string &s, int i, int j)
{
    if (i >= j)
        return 0;
    if (is_palindrome(s, i, j))
        return 0;
    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = 1 + palindrome_partitioning(s, i, k) + palindrome_partitioning(s, k + 1, j);
        if (temp < min)
            min = temp;
    }
    return min;
}

int main()
{
    string s = "ababbbabbababa";
    cout << palindrome_partitioning(s, 0, s.length() - 1) << endl;
    return 0;
}