#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void sort_solve(vector<int> &A, int k)
{
    int n = A.size();
    int size = (n == k) ? n : k + 1;
    priority_queue<int, vector<int>, greater<int>> min_heap(A.begin(), A.begin() + size);
    
    int index = 0;

    for (int i = k + 1; i < n; i++)
    {
        A[index++] = min_heap.top();
        min_heap.pop();
        min_heap.push(A[i]);
    }

    while (!min_heap.empty())
    {
        A[index++] = min_heap.top();
        min_heap.pop();
    }
}

int main()
{
    vector<int> A = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    sort_solve(A, k);

    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}