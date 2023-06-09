#include <iostream>
#include <string>
using namespace std;

string decode(string s, int n)
{
    // ccooddeeffoorrcceess -> codeforces
    // qzxcq -> q
    // abacabac -> ac

    string res = "";

    int i = 0;
    while (i < n)
    {
        res += s[i];

        char temp = s[i];
        i++;
        // move forward till you find the same character
        while (i < n && s[i] != temp)
        {
            // cout << temp << " " << i << endl;
            i++;
        }
        i++;
    }

    return res;
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << decode(s, n) << endl;
    }

    return 0;
}