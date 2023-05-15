#include <iostream>
#include <utility>
#include <vector>
#include <limits.h>
using namespace std;

class Graph
{
public:
    int V;
    vector<pair<pair<int, int>, int>> edges;

    // arrays for bellman ford
    int *parent;
    int *distance;

    Graph(int V)
    {
        this->V = V;
        parent = new int[V];
        distance = new int[V];
    }

    void add_edge(int u, int v, int weight);
    void initialize_single_source(int source);
    void relax(pair<pair<int, int>, int> edge);
    bool bellman_ford(int source);
};

void Graph::add_edge(int u, int v, int weight)
{
    edges.push_back(make_pair(make_pair(u, v), weight));
}

void Graph::initialize_single_source(int source)
{
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[source] = 0;
}

void Graph::relax(pair<pair<int, int>, int> edge)
{
    int u = edge.first.first;
    int v = edge.first.second;
    int weight = edge.second;

    if (distance[v] > distance[u] + weight)
    {
        distance[v] = distance[u] + weight;
        parent[v] = u;
    }
}

bool Graph::bellman_ford(int source)
{
    initialize_single_source(source);
    for (int i = 1; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            relax(edge);
        }
    }
    for (auto edge : edges)
    {
        if (distance[edge.first.first] + edge.second < distance[edge.first.second])
            return false;
    }
    return true;
}

int main()
{
    Graph g(5);
    g.add_edge(0, 1, -1);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 3, -3);
    g.add_edge(3, 4, 5);
    g.add_edge(0, 4, 4);
    g.add_edge(1, 4, 3);
    g.add_edge(1, 3, 2);
    g.add_edge(3, 1, 1);

    bool flag = g.bellman_ford(0);
    if (flag)
    {
        for (int i = 0; i < g.V; i++)
            cout << i << " distance (" << g.distance[i] << ") and parent: (" << g.parent[i] << ")"  << endl;
    }
    else
    {
        cout << "Graph has a negative cycle." << endl;
    }
}