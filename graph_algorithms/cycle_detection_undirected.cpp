#include <iostream>
#include <queue>
#include <list>
#include <limits.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adjancency_list;
    bool is_cycled = false;

    // subsidiary arrays
    int *visited = new int[V];
    int *distance = new int[V];
    int *parent = new int[V];

    Graph(int V)
    {
        this->V = V;
        adjancency_list = new list<int>[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = 0;
        }
    }

    void add_edge(int u, int v);
    void BFS(int x);
    void BFS_traversal();
};

void Graph::add_edge(int u, int v)
{
    adjancency_list[u].push_back(v);
    adjancency_list[v].push_back(u);
}

void Graph::BFS(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    distance[x] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto j = adjancency_list[v].begin(); j != adjancency_list[v].end(); j++)
        {
            if (visited[*j] == 0)
            {
                visited[*j] = 1;
                distance[*j] = distance[v] + 1;
                parent[*j] = v; // Set parent
                q.push(*j);
            }
            else if (parent[v] != *j) // if node is visited and not the parent of current node
            {
                is_cycled = true;
            }
        }
    }
}

void Graph::BFS_traversal()
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        distance[i] = INT_MAX;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            distance[i] = 0;
            BFS(i);
        }
    }
}

int main()
{
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    // g.add_edge(3, 0);

    g.BFS_traversal();

    if (g.is_cycled)
        cout << "Graph has a cycle." << endl;
    else
        cout << "Graph has no cycle." << endl;

    return 0;
}