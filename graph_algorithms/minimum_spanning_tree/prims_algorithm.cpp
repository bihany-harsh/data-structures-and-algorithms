#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

template <class T>
class Min_Heap
{
public:
    vector<T> heap;
    int heap_size;

    Min_Heap()
    {
        heap_size = 0;
    }

    void Insert(T key);
    void Create_Heap(T *arr, int size);
    void Delete_Min();
    T Min();
};

template <class T>
void Min_Heap<T>::Create_Heap(T *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        heap[i] = arr[i];
    }
    make_heap(heap.begin(), heap.end(), greater<T>());
    heap_size = size;
}

template <class T>
void Min_Heap<T>::Insert(T key)
{
    heap_size++;
    heap.push_back(key);
    push_heap(heap.begin(), heap.end(), greater<T>());
}

template <class T>
void Min_Heap<T>::Delete_Min()
{
    pop_heap(heap.begin(), heap.end(), greater<T>());
    heap.pop_back();
    heap_size--;
}

template <class T>
T Min_Heap<T>::Min()
{
    return heap[0];
}

class Graph
{
public:
    int V;
    list<pair<int, int>> *adj_list;

    Graph(int V)
    {
        this->V = V;
        adj_list = new list<pair<int, int>>[V];
    }

    void add_edge(int u, int v, int weight);
    void prims_algorithm();
};

void Graph::add_edge(int u, int v, int weight)
{
    adj_list[u].push_back(make_pair(weight, v));
    adj_list[v].push_back(make_pair(weight, u));
}

void Graph::prims_algorithm()
{
    int *parent = new int[V];
    int *key = new int[V];
    bool *in_mst = new bool[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        in_mst[i] = false;
    }

    // the heap will contain pairs of (key, vertex)
    Min_Heap<pair<int, int>> heap;
    heap.Insert(make_pair(0, 0));
    key[0] = 0;
    parent[0] = -1;

    while (heap.heap_size != 0)
    {
        pair<int, int> u = heap.Min();
        heap.Delete_Min();
        in_mst[u.second] = true;

        for (list<pair<int, int>>::iterator i = adj_list[u.second].begin(); i != adj_list[u.second].end(); i++)
        {
            if (in_mst[(*i).second] == false && (*i).first < key[(*i).second])
            {
                key[(*i).second] = (*i).first;
                parent[(*i).second] = u.second;
                heap.Insert(make_pair((*i).first, (*i).second));
            }
        }
    }

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
}

int main()
{
    Graph g(9);

    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);

    g.prims_algorithm();

    return 0;
}