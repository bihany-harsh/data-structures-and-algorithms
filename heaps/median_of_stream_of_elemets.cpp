#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<float> median_of_stream(vector<int> &array)
{
    vector<float> medians;
    float median = 0;

    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>> max_heap;

    int n = array.size();

    for (int i = 0; i < n; i++)
    {
        if (max_heap.size() == min_heap.size())
        {
            if (array[i] > median)
            {
                min_heap.push(array[i]);
                median = min_heap.top();
                medians.push_back(median);
            }
            else
            {
                max_heap.push(array[i]);
                median = max_heap.top();
                medians.push_back(median);
            }
        }
        else if (max_heap.size() > min_heap.size())
        {
            if (array[i] > median)
            {
                min_heap.push(array[i]);
            }
            else
            {
                int top_max_heap = max_heap.top();
                max_heap.pop();
                min_heap.push(top_max_heap);
                max_heap.push(array[i]);
            }
            median = (max_heap.top() + min_heap.top()) / 2.0;
            medians.push_back(median);
        }
        else
        {
            if (array[i] > median)
            {
                int top_min_heap = min_heap.top();
                min_heap.pop();
                max_heap.push(top_min_heap);
                min_heap.push(array[i]);
            }
            else
            {
                max_heap.push(array[i]);
            }
            median = (max_heap.top() + min_heap.top()) / 2.0;
            medians.push_back(median);
        }
    }

    return medians;
}

int main()
{
    vector<int> array = {2, 3, 6, 8, 1, 4, 5};
    vector<float> medians = median_of_stream(array);

    for (int i = 0; i < medians.size(); i++)
        cout << medians[i] << " ";
    cout << endl;

    return 0;
}