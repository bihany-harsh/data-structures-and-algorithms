#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Max_Heap
{
public:
    vector<int> heap;
    int size;

    int left(int index) { return 2 * index + 1; }
    int right(int index) { return 2 * index + 2; }

    Max_Heap();
    void Max_heapify(int index);
    void build_max_heap(vector<int> &A);
    // functions for a max priority queue
    int heap_maximum();
    int heap_extract_max();
    void heap_increase_key(int index, int key);
};

Max_Heap::Max_Heap()
{
    size = 0;
    heap = {};
}

void Max_Heap::Max_heapify(int index)
{
    int largest = index;
    int L = left(index);
    int R = right(index);

    if (L < size && heap[L] > heap[largest])
        largest = L;
    if (R < size && heap[R] > heap[largest])
        largest = R;

    if (largest != index)
    {
        swap(heap[index], heap[largest]);
        Max_heapify(largest);
    }
}

void Max_Heap::build_max_heap(vector<int> &A)
{
    heap = A;
    size = heap.size();

    for (int i = size / 2 - 1; i >= 0; i--)
        Max_heapify(i);
}

int Max_Heap::heap_maximum()
{
    return heap[0];
}

int Max_Heap::heap_extract_max()
{
    if (size < 1)
    {
        cout << "heap underflow" << endl;
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;
    Max_heapify(0);
    return max;
}

void Max_Heap::heap_increase_key(int index, int key)
{
    if (heap[index] > key)
    {
        cout << "new key is smaller than current key" << endl;
        return;
    }
    heap[index] = key;
    while (index > 0 && heap[index] > heap[(index - 1) / 2])
    {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void Heapsort(vector<int> &A)
{
    Max_Heap heap;
    heap.build_max_heap(A);

    for (int i = heap.size - 1; i >= 0; i--)
    {
        swap(heap.heap[0], heap.heap[i]);
        heap.size--;
        heap.Max_heapify(0);
    }

    A = heap.heap;
}

int main()
{
    // Max_Heap heap;
    // heap.heap = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    // heap.size = heap.heap.size();

    // heap.Max_heapify(1);

    // for (int i = 0; i < heap.size; i++)
    //     cout << heap.heap[i] << " ";
    // cout << endl;

    // vector<int> A = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};


    // Heapsort(A);

    // for (int i = 0; i < A.size(); i++)
    //     cout << A[i] << " ";
    // cout << endl;



    // USING STL
    vector<int> A = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    make_heap(A.begin(), A.end());
    priority_queue<int, vector<int>> pq(A.begin(), A.end());

    int max_ = pq.top();
    pq.pop();

    cout << max_ << endl;
    pq.push(18);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}