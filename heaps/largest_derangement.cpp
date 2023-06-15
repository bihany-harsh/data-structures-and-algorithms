#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<int> largest_derangement(vector<int> &array)
{
    priority_queue<int> pq;
    vector<int> result(array.size());

    for (int i = 0; i < array.size(); i++)
        pq.push(array[i]);

    for (int i = 0; i < array.size(); i++)
    {
        int d = pq.top();
        pq.pop();
        if (d != array[i] || i == array.size() - 1)
        {
            result[i] = d;
        }
        else
        {
            result[i] = pq.top();
            pq.pop();
            pq.push(d);
        }
    }

    if (result[array.size() - 1] == array[array.size() - 1])
    {
        result[array.size() - 1] = result[array.size() - 2];
        result[array.size() - 2] = array[array.size() - 1];
    }

    return result;
}

int main()
{
    vector<int> array = {5, 4, 3, 2, 1};
    vector<int> result = largest_derangement(array);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}