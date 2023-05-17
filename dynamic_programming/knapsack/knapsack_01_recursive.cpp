#include <iostream>
using namespace std;

int knapsack_recursive_01(int *val, int *wt, int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= W)
    {
        return max((knapsack_recursive_01(val, wt, W - wt[n - 1], n - 1) + val[n - 1]),
                   (knapsack_recursive_01(val, wt, W, n - 1)));
    }
    else
    {
        return knapsack_recursive_01(val, wt, W, n - 1);
    }
}

int main()
{
    int n, W;
    cin >> n >> W;
    int *wt = new int [n];
    int *val = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << knapsack_recursive_01(val, wt, W, n) << endl;
      

    return 0;
}