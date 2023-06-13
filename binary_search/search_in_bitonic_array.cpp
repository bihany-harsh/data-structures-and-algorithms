#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;
    int bitonic_index = -1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            bitonic_index = mid;
            break;
        }
        else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            left = mid + 1;
        else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
            right = mid - 1;
    }

    left = 0;
    right = bitonic_index - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            right = mid - 1;
        else if (arr[mid] < key)
            left = mid + 1;
    }

    left = bitonic_index;
    right = arr.size() - 1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            left = mid + 1;
        else if (arr[mid] < key)
            right = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 3, 8, 12, 4, 2};
    int key = 4;

    cout << search(arr, key) << endl;

    return 0;
}