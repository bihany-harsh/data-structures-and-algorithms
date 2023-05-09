#include <iostream>
#include <fstream>
using namespace std;

int max_sum_subarray(int *arr, int n)
{
    int *S = new int[n];
    S[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (S[i - 1] > 0)
            S[i] = S[i - 1] + arr[i];
        else
            S[i] = arr[i];
    }

    int max_sum = S[0];
    for (int i = 1; i < n; i++)
    {
        if (S[i] > max_sum)
            max_sum = S[i];
    }

    return max_sum;
}

void fill_array(int *arr, int n)
{
    // random number generator with negative numbers as well
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000 - 400;
    }
}

void display_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    int n = 10;

    int *arr = new int[n];
    fill_array(arr, n);
    ofstream file;
    file.open("array.txt");
    streambuf *stream_buffer_cout = cout.rdbuf();
    cout.rdbuf(file.rdbuf());
    display_array(arr, n);
    cout.rdbuf(stream_buffer_cout);
    file.close();

    cout << max_sum_subarray(arr, n) << endl;

    return 0;
}