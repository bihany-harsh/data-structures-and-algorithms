#include <iostream>
#include <algorithm>
using namespace std;

int partition (int *arr, int L, int R, int k);
int find_median(int *arr, int n)
{
    sort (arr, arr + n);
    return arr[n/2];
}

int Select (int *arr, int L, int R, int k)
{
    if (k > 0 && k < R - L + 1)
    {
        int n = R - L + 1;
        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
        {
            median[i] = find_median(arr + L + i * 5, 5);
        }
        if (i * 5 < n)
        {
            median[i] = find_median(arr + L + i * 5, n % 5);
            i++;
        }
        int median_of_medians = (i == 1) ? median[i - 1] : Select(median, 0, i - 1, i / 2);
        int pos = partition(arr, L, R, median_of_medians);
        if (pos - L == k - 1)
        {
            return arr[pos];
        }
        if (pos - L > k - 1)
        {
            return Select(arr, L, pos - 1, k);
        }
        return Select(arr, pos + 1, R, k - pos + L - 1);
    }
    return INT_MAX;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition (int *arr, int L, int R, int k)
{
    int i;
    for (i = L; i < R; i++)
    {
        if (arr[i] == k)
        {
            break;
        }
    }
    swap(arr[i], arr[R]);
    i = L;
    for (int j = L; j < R; j++)
    {
        if (arr[j] <= k)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[R]);
    return i;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << Select(arr, 0, n - 1, k) << endl;
    return 0;
}
