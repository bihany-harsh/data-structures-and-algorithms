#include <iostream>
#include <list>
#include <queue>
#include <limits.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adjacency_list;
    bool is_directed;

    // subsidiary arrays for DFS related algos
    int *visited = new int[V];
    int *parent = new int[V];
    int *DFN = new int[V];
    int dfn = 0;
    //

    Graph(int V, bool is_directed)
    {
        this->V = V;
        adjacency_list = new list<int>[V];
        this->is_directed = is_directed;
    }

    void add_edge(int u, int v);
    void display_graph();
    void BFS(int x);
    void DFS(int x);
    void DFS_traversal();
};

void Graph::add_edge(int u, int v)
{
    adjacency_list[u].push_back(v);
    if (!is_directed)
        adjacency_list[v].push_back(u);
}

void Graph::display_graph()
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (auto j = adjacency_list[i].begin(); j != adjacency_list[i].end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
}

void Graph::BFS(int x)
{
    int *distance = new int[V];
    int *visited = new int[V];
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    queue<int> q;
    q.push(x);
    distance[x] = 0;
    visited[x] = 1;
    cout << x << " (" << distance[x] << ")" << endl;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u = adjacency_list[v].begin(); u != adjacency_list[v].end(); u++)
        {
            if (!visited[*u])
            {
                distance[*u] = distance[v] + 1;
                visited[*u] = 1;
                q.push(*u);
                cout << *u << " (" << distance[*u] << ")" << endl;
            }
        }
    }
}

void Graph::DFS(int x)
{
    visited[x] = 1;
    DFN[x] = dfn++;

    cout << x << " (" << DFN[x] << ")" << endl;

    for (auto v = adjacency_list[x].begin(); v != adjacency_list[x].end(); v++)
    {
        if (visited[*v] == 0)
        {
            parent[*v] = x;
            DFS(*v);
        }
    }
}

void Graph::DFS_traversal()
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS(i);
    }
}

int main()
{
    Graph g(6, false);

    g.add_edge(0, 5);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(3, 5);

    g.display_graph();

    g.BFS(0);

    g.DFS_traversal();

    return 0;
}