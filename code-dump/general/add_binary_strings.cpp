#include <iostream>
#include <string>
using namespace std;

string add_binary(string A, string B)
{
    int n = A.size();
    int m = B.size();
    int carry = 0;
    string ans = "";

    int i = n - 1, j = m - 1;

    while (i >= 0 && j >= 0)
    {
        int sum = (A[i] - '0') + (B[j] - '0') + carry;
        ans = to_string(sum % 2) + ans;
        carry = sum / 2;
        i--;
        j--;
    }

    if (i > j)
    {
        while (i >= 0)
        {
            int sum = (A[i] - '0') + carry;
            ans = to_string(sum % 2) + ans;
            carry = sum / 2;
            i--;
        }
    }
    else
    {
        while (j >= 0)
        {
            int sum = (B[j] - '0') + carry;
            ans = to_string(sum % 2) + ans;
            carry = sum / 2;
            j--;
        }
    }

    if (carry)
    {
        ans = to_string(carry) + ans;
    }

    return ans;
}