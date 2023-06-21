#include <iostream>
#include <string>
using namespace std;

string multiply(string A, string B)
{
    int n = A.size();
    int m = B.size();

    string result(n + m, '0');

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int current = (A[i] - '0') * (B[j] - '0') + (result[i + j + 1] - '0');
            result[i + j + 1] = (current % 10) + '0';
            result[i + j] += current / 10;
        }
    }

    while (result.size() > 1 && result[0] == '0')
    {
        result = result.substr(1);
    }

    return result;
}

int main()
{
    string A = "123";
    string B = "456";
    cout << multiply(A, B) << endl;
    return 0;
}