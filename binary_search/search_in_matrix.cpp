#include <iostream>
#include <vector>
using namespace std;

int search(vector<vector<int>> &matrix, int key)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int i = 0;
    int j = m - 1;

    while (i < n && j >= 0)
    {
        if (matrix[i][j] == key)
            return 1;
        else if (matrix[i][j] > key)
            j--;
        else if (matrix[i][j] < key)
            i++;
    }

    return 0;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int key = 78;

    cout << search(matrix, key) << endl;

    return 0;
}