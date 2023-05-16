#include <iostream>
#include <list>
#include <queue>
#include <utility>
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
    bool isEmpty();
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

template <class T>
bool Min_Heap<T>::isEmpty()
{
    return heap.empty();
}

class Graph
{
public:
    int V;
    list<pair<int, int>> *adj_list;

    // utility arrays
    int *distance;
    int *parent;

    // for dijkstra algo
    int *done_vertices;

    Graph(int V)
    {
        this->V = V;
        adj_list = new list<pair<int, int>>[V];
    }

    void add_edge(int u, int v, int weight);
    void initialize_single_source(int source);
    void relax(int u, int v, int weight);
    void dijkstra(int source);
};

void Graph::add_edge(int u, int v, int weight)
{
    adj_list[u].push_back(make_pair(v, weight));
    // the adjacency list has pairs (vertex, weight)
}

void Graph::initialize_single_source(int source)
{
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
        done_vertices[i] = 0;
    }
    distance[source] = 0;
}

void Graph::relax(int u, int v, int weight)
{
    if (distance[v] > distance[u] + weight)
    {
        distance[v] = distance[u] + weight;
        parent[v] = u;
    }
}

void Graph::dijkstra(int source)
{
    distance = new int[V];
    parent = new int[V];
    done_vertices = new int[V];
    initialize_single_source(source);

    Min_Heap<pair<int, int>> S;
    S.Insert(make_pair(0, source));

    while (!S.isEmpty())
    {
        pair<int, int> u = S.Min();
        S.Delete_Min();

        if (done_vertices[u.second] == 1)
            continue;

        done_vertices[u.second] = 1;

        for (auto& edge : adj_list[u.second])
        {
            int v = edge.first;
            int weight = edge.second;

            if (done_vertices[v] == 0 && distance[v] > distance[u.second] + weight)
            {
                relax(u.second, v, weight);
                S.Insert(make_pair(distance[v], v));
            }
        }
    }
}

int main()
{
    Graph g(5);
    g.add_edge(0, 1, 10);
    g.add_edge(0, 4, 5);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 4, 2);
    g.add_edge(2, 3, 4);
    g.add_edge(3, 0, 7);
    g.add_edge(3, 2, 6);
    g.add_edge(4, 1, 3);
    g.add_edge(4, 2, 9);
    g.add_edge(4, 3, 2);

    g.dijkstra(0);

    for (int i = 0; i < g.V; ++i)
    {
        cout << "Distance from 0 to " << i << " is " << g.distance[i] << endl;
    }

    return 0;
}