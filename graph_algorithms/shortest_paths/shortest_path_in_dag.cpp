#include <iostream>
#include <list>
#include <stack>
#include <limits.h>
#include <utility>
using namespace std;

class Graph
{
public:
    int V;
    list<pair<int, int>> *adj_list;

    // topologically sorted stack
    stack<int> top_sorted_stack;

    int *visited;

    // for shortest paths
    int *parent;
    int *distance;

    Graph(int V)
    {
        this->V = V;
        adj_list = new list<pair<int, int>>[V];
    }

    void add_edge(int u, int v, int weight);
    void DFS(int v);
    void topological_sort();
    void initialize_single_source(int source);
    void relax (int u, int v, int weight);
    void dag_shortest_path(int source);
};

void Graph::add_edge(int u, int v, int weight)
{
    adj_list[u].push_back(make_pair(v, weight));
}

void Graph::DFS(int v)
{
    visited[v] = 1;

    for (list<pair<int, int>>::iterator i = adj_list[v].begin(); i != adj_list[v].end(); i++)
    {
        if(!visited[i->first])
        {
            DFS(i->first);
        }
    }
    top_sorted_stack.push(v);
}

void Graph::topological_sort()
{
    visited = new int[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
}

void Graph::initialize_single_source(int source)
{
    parent = new int [V];
    distance = new int [V];

    for(int i = 0; i < V; i++)
    {
        parent[i] = -1;
        distance[i] = INT_MAX;
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

void Graph::dag_shortest_path(int source)
{
    topological_sort();
    initialize_single_source(source);
    while (!top_sorted_stack.empty())
    {
        int u = top_sorted_stack.top();
        top_sorted_stack.pop();
        for (list<pair<int, int>>::iterator i = adj_list[u].begin(); i != adj_list[u].end(); i++)
        {
            relax(u, i->first, i->second);
        }
    }
}

int main()
{
    Graph g(6); 

    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 5, 1);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);

    int source = 0;
    g.dag_shortest_path(source);

    for(int i = 0; i < g.V; i++)
    {
        cout << "Distance from " << source << " to " << i << " is " << g.distance[i] << " parent being: " << g.parent[i] << endl;
    }

    return 0;
}
