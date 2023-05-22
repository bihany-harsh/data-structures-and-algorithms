#include <iostream>
#include <climits>
using namespace std;

int mcm_total_cost(int *arr, int L, int R)
{
    if (L >= R)
    {
        return 0;
    }
    int min_cost = INT_MAX;

    for (int k = L; k < R; k++)
    {
        int temp = mcm_total_cost(arr, L, k) + mcm_total_cost(arr, k + 1, R) + arr[L - 1] * arr[k] * arr[R];
        min_cost = min(min_cost, temp);
    }

    return min_cost;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mcm_total_cost(arr, 1, n - 1) << endl;
    return 0;
}