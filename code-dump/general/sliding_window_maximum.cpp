#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> sliding_window_size(vector<int> &arr, int win)
{
    vector<int> result;
    priority_queue<pair<int, int>> pq; // <value, index>
    for (int i = 0; i < win; i++)
    {
        pq.push(make_pair(arr[i], i));
    }
    result.push_back(pq.top().first);
    for (int i = win; i < arr.size(); i++)
    {
        pq.push(make_pair(arr[i], i));
        while (pq.top().second <= i - win)
        {
            pq.pop();
        }
        result.push_back(pq.top().first);
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result = sliding_window_size(arr, 3);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}