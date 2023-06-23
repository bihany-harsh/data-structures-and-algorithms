#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> d_nums(vector<int> &arr, int win)
{
    vector<int> result;
    unordered_map<int, int> map;
    int dist_count = 0;
    for (int i = 0; i < win; i++)
    {
        if (map[arr[i]] == 0)
            dist_count++;
        map[arr[i]]++;
    }
    result.push_back(dist_count);

    for (int i = win; i < arr.size(); i++)
    {
        if (map[arr[i - win]] == 1)
            dist_count--;
        map[arr[i - win]]--;
        if (map[arr[i]] == 0)
            dist_count++;
        map[arr[i]]++;
        result.push_back(dist_count);
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    vector<int> result = d_nums(arr, 4);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}