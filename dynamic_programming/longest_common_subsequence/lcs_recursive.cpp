#include <iostream>
#include <string>
using namespace std;

int length_of_lcs(string &s1, string &s2, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (s1[n - 1] == s2[m - 1])
    {
        return length_of_lcs(s1, s2, n - 1, m - 1) + 1;
    }
    else
    {
        return max(length_of_lcs(s1, s2, n - 1, m), length_of_lcs(s1, s2, n, m - 1));
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << length_of_lcs(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}