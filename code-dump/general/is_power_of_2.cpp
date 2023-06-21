#include <iostream>
#include <string>
using namespace std;

bool is_divisible_2(const string &A)
{
    // We only need to check the last digit to know if the number is divisible by 2.
    int last_digit = A[A.size() - 1] - '0';
    return last_digit % 2 == 0;
}

string divide_by_2(const string &A)
{
    string result;
    int carry = 0;
    for (char c : A)
    {
        int current = carry * 10 + (c - '0');
        result += (current / 2) + '0';
        carry = current % 2;
    }
    // Remove leading zeros if any.
    while (result.size() > 1 && result[0] == '0')
    {
        result = result.substr(1);
    }
    return result;
}

bool is_power_of_2(string A)
{
    if (A == "1")
    {
        return true;
    }
    while (A != "1")
    {
        if (!is_divisible_2(A))
        {
            return false;
        }
        A = divide_by_2(A);
    }
    return true;
}

int main()
{
    string A = "89";
    cout << is_power_of_2(A) << endl;
    return 0;
}
