#include <iostream>
using namespace std;

int merge_and_count_split_inversions(int *arr, int L, int mid, int R)
{
    int merge_inversions = 0;
    int *temp = new int[R - L + 1];
    int index = 0;
    int i = L;
    int j = mid + 1;
    while (i <= mid && j <= R)
    {
        if (arr[i] <= arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
            merge_inversions += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        temp[index++] = arr[i++];
    }
    while (j <= R)
    {
        temp[index++] = arr[j++];
    }
    for (int i = L; i <= R; i++)
    {
        arr[i] = temp[i - L];
    }
    delete[] temp;
    return merge_inversions;
}

int sort_and_count_inversions(int *arr, int L, int R)
{
    if (L == R)
    {
        return 0;
    }
    int mid = (L + R) / 2;
    int left_inversions = sort_and_count_inversions(arr, L, mid);
    int right_inversions = sort_and_count_inversions(arr, mid + 1, R);
    int merge_inversions = merge_and_count_split_inversions(arr, L, mid, R);

    return left_inversions + right_inversions + merge_inversions;
}

int main()
{
    int arr[] = {1, 3, 5, 2, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << sort_and_count_inversions(arr, 0, n - 1) << endl;

    return 0;
}