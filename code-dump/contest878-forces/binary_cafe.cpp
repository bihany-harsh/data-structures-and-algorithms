#include <iostream>
using namespace std;

int num_of_bits (int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n >>= 1;
    }
    return count;
}

int solve (int n, int k)
{
    int bits = num_of_bits(n);
    if (bits <= k)
        return n + 1;
    else
        return (1 << k);
}

int main()
{
    int iter;
    cin >> iter;
    while (iter--)
    {
        int n, k;
        cin >> n >> k;

        cout << solve(n, k) << endl;
    }
}