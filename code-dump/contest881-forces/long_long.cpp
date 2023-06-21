#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int iterations;
    cin >> iterations;
    while (iterations--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        long long abs_sum = 0;
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] < 0)
                abs_sum += -v[i];
            else
                abs_sum += v[i];
        }

        int count_swaps = 0;

        for (int i = 0; i < n;)
        {
            if (v[i] < 0)
            {
                count_swaps++;
                while (i < n && v[i] <= 0)
                    i++;
            }
            else if (v[i] == 0)
            {
                while (i < n && v[i] == 0)
                    i++;
            }
            else
            {
                i++;
            }
        }

        cout << abs_sum << " " << count_swaps << endl;
    }
}