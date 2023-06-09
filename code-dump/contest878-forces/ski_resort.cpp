#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long solve(vector<int> temps, int min_days, int max_temp)
{
    vector<int> spanned(temps.size(), 0);
    long long ways = 0;
    int current_span = 0;

    for (int i = 0; i < temps.size(); i++)
    {
        if (temps[i] > max_temp)
        {
            current_span = 0;
        }
        else
        {
            current_span++;
        }

        if (current_span >= min_days)
        {
            ways += (current_span - min_days + 1);
        }
    }

    return ways;
}

int main()
{
    int iter;
    cin >> iter;
    while (iter--)
    {
        int n, min_days, max_temp;
        cin >> n >> min_days >> max_temp;

        vector<int> temps(n);
        for (int i = 0; i < n; i++)
            cin >> temps[i];

        cout << solve(temps, min_days, max_temp) << endl;
    }

    return 0;
}
