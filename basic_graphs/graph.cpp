#include <iostream>
#include <queue>
#include <list>
#include <limits.h>
using namespace std;

// adjacency list representation of graph
class Graph
{
public:
    int V;

    int *DFN = new int[V];
    int *High_point = new int[V];
    int *visited = new int[V];
    int *parent = new int[V];
    int *articulation_point = new int[V];
    int dfn = 0;

    list<int> *adj;

    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void BFS(int x);
    bool isBipartite();
    void DFS_traversal();
    void DFS_for_biconnectedness(int x);
};

void Graph::BFS(int x)
{
    queue<int> q;
    int *distance = new int[V];
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;

    cout << "BFS:" << endl;

    distance[x] = 0;
    q.push(x);

    cout << x << " (" << distance[x] << ")" << endl;
    while (!q.empty())
    {
        // dequeuing
        int v = q.front();
        q.pop();
        for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (distance[*i] == INT_MAX)
            {
                distance[*i] = distance[v] + 1;
                q.push(*i);
                cout << *i << " (" << distance[*i] << ")" << endl;
            }
        }
    }
}

bool Graph::isBipartite()
{
    int *visited = new int[V];
    int *color = new int[V];

    queue<int> q;
    // make sure that all nodes are visited

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        color[i] = -1;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            q.push(i);
            visited[i] = 1;
            color[i] = 0;

            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (auto i = adj[v].begin(); i != adj[v].end(); i++)
                {
                    if (visited[*i] == 0)
                    {
                        visited[*i] = 1;
                        color[*i] = 1 - color[v];
                        q.push(*i);
                    }
                    else if (color[*i] == color[v])
                        return false;
                }
            }
        }
    }
    return true;
}

void Graph::DFS_for_biconnectedness(int x)
{
    visited[x] = 1;
    DFN[x] = dfn++;
    High_point[x] = INT_MAX;

    cout << x << endl;
    for (auto i = adj[x].begin(); i != adj[x].end(); i++)
    {
        if (visited[*i] == 0)
        {
            parent[*i] = x;
            DFS_for_biconnectedness(*i);
            High_point[x] = min(High_point[x], High_point[*i]);
            if (High_point[*i] >= DFN[x])
            {
                articulation_point[x] = 1;
            }
        }
        else if (*i != parent[x])
        {
            High_point[x] = min(High_point[x], DFN[*i]);
        }
    }
}

void Graph::DFS_traversal()
{
    int *visited = new int[V];
    int *articulation_points = new int[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            DFS_for_biconnectedness(i);
        }
    }
}

int main()
{
    Graph g(6);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 5);

    cout << "BFS: " << endl;
    g.BFS(0);
    cout << endl
         << "Is Bipartite: " << g.isBipartite() << endl;
    cout << endl
         << "DFS: " << endl;

    g.DFS_traversal();

    int *AP = g.articulation_point;
    cout << endl
         << "Articulation Points: " << endl;
    for (int i = 0; i < g.V; i++)
    {
        cout << i << " (" << AP[i] << ")" << " ";
    }

    return 0;
}