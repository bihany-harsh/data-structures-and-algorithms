#include <iostream>
using namespace std;

int majority_element(int *arr, int n)
{
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = arr[i];
            count = 1;
        }
        else if (arr[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    if (count > n / 2)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << majority_element(arr, n) << endl;
    return 0;
}