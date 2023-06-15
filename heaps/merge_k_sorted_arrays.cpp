#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Custom_compare
{
public:
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first > b.first;
    }
};

vector<int> merge_k_sorted_arrays(vector<vector<int>> &arrays)
{
    vector<int> result;
    int k = arrays.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Custom_compare> min_heap;

    for (int i = 0; i < k; i++)
    {
        min_heap.push(make_pair(arrays[i][0], make_pair(i, 0)));
    }

    while (!min_heap.empty())
    {
        pair<int, pair<int, int>> top = min_heap.top();
        min_heap.pop();
        result.push_back(top.first);
        int i = top.second.first;
        int j = top.second.second;
        if (j + 1 < arrays[i].size())
        {
            min_heap.push(make_pair(arrays[i][j + 1], make_pair(i, j + 1)));
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> arrays{{2, 6, 12},
                               {1, 9},
                               {23, 34, 90, 2000}};
    vector<int> result = merge_k_sorted_arrays(arrays);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}