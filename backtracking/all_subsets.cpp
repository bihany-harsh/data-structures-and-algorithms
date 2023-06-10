#include <iostream>
#include <vector>
using namespace std;

void Subsets_util(vector<int> &arr, vector<vector<int>> &subsets, vector<int> &subset, int index)
{
    subsets.push_back(subset);

    for (int i = index; i < arr.size(); i++)
    {
        subset.push_back(arr[i]);
        Subsets_util(arr, subsets, subset, i + 1);
        subset.pop_back();
    }

    return;
}

vector<vector<int>> Subsets(vector<int> &arr)
{
    vector<vector<int>> subsets;
    vector<int> subset;

    Subsets_util(arr, subsets, subset, 0);

    return subsets;
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> subsets = Subsets(arr);

    for (int i = 0; i < subsets.size(); i++)
        print(subsets[i]);

    return 0;
}