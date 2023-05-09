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
    while(!q.empty())
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
                cout << *i << " (" << distance[*i] << ")"<< endl;
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

            while(!q.empty())
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

    g.BFS(0);
    cout << endl << "Is Bipartite: " << g.isBipartite() << endl;


    return 0;
}