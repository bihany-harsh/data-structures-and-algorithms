#include <iostream>
#include <fstream>
using namespace std;
// SPARSE TABLE SOLUTION: Space = O(nlogn), Time = O(1)
void fill_array(int *arr, int n)
{
    // random number generator
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
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

void fill_sparse_table(int *arr, int **sparse_table, int n, int *log_array)
{
    // sparse_table[i][j] = stores minumu of range [i, i + 2^j - 1]
    for (int i = 0; i < n; i++)
    {
        sparse_table[i][0] = arr[i];
    }

    for (int j = 0; j < log_array[n]; j++)
    {
        for (int i = 0; i + (1 << j) < n; i++)
        {
            sparse_table[i][j + 1] = min(sparse_table[i][j], sparse_table[i + (1 << j)][j]);
        }
    }
}

int main()
{
    int n = 1000;

    int *arr = new int[n];
    fill_array(arr, n);

    // storing the output of display_array() in a file
    ofstream file;
    file.open("array.txt");
    streambuf *stream_buffer_cout = cout.rdbuf();
    cout.rdbuf(file.rdbuf());
    display_array(arr, n);
    cout.rdbuf(stream_buffer_cout);
    file.close();


    // precomputing the log_array
    int *log_array = new int[n + 1];

    log_array[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        log_array[i] = log_array[i / 2] + 1;
    }

    // precomputing the sparse table

    int **sparse_table = new int *[n];
    for (int i = 0; i < n; i++)
    {
        sparse_table[i] = new int[log_array[n] + 1];
    }

    fill_sparse_table(arr, sparse_table, n, log_array);

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int j = log_array[r - l + 1];

        int minimum = min(sparse_table[l][j], sparse_table[r - (1 << j) + 1][j]);

        cout << minimum << endl;
    }

    return 0;
}