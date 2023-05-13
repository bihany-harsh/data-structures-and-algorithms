#include <iostream>
#include <list>
#include <limits.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj_list;

    // arrays for dfs
    int *visited;
    int *articulation_points;
    int *DFN;
    int *parent;
    int *high_point;
    int dfn;

    Graph(int V)
    {
        this->V = V;
        adj_list = new list<int>[V];
        dfn = 0;
    }

    void add_edge(int u, int v);
    void DFS_visit(int x);
    void DFS();
    void bridges();
};

void Graph::add_edge(int u, int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void Graph::DFS_visit(int x)
{
    visited[x] = 1;
    DFN[x] = dfn++;
    high_point[x] = DFN[x];

    for (list<int>::iterator i = adj_list[x].begin(); i != adj_list[x].end(); i++)
    {
        if (visited[*i] == 0)
        {
            parent[*i] = x;
            DFS_visit(*i);
            high_point[x] = min(high_point[x], high_point[*i]);
            if (high_point[*i] >= DFN[x])
            {
                articulation_points[x] = 1;
            }
        }
        else if (*i != parent[x])
        {
            high_point[x] = min(high_point[x], DFN[*i]);
        }
    }
}

void Graph::DFS()
{
    visited = new int[V];
    articulation_points = new int[V];
    DFN = new int[V];
    parent = new int[V];
    high_point = new int[V];
    dfn = 0;

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            DFS_visit(i);
        }
    }
}

void Graph::bridges()
{
    DFS();
    for (int i = 0; i < V; i++)
    {
        for (list<int>::iterator j = adj_list[i].begin(); j != adj_list[i].end(); j++)
        {
            int degree_j = 0;
            int degree_i = 0;
            for (list<int>::iterator k = adj_list[*j].begin(); k != adj_list[*j].end(); k++)
                degree_j++;
            for (list<int>::iterator k = adj_list[i].begin(); k != adj_list[i].end(); k++)
                degree_i++;

            if ((articulation_points[i] == 1 && articulation_points[*j] == 1) || (articulation_points[i] == 1 && degree_j == 1) || (articulation_points[*j] == 1 && degree_i == 1))
                cout << "Edge between " << i << " and " << *j << " is a bridge." << endl;
        }
    }
}

int main()
{
    Graph g(7);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 6);
    g.add_edge(6, 4);

    // g.DFS();

    // for (int i = 0; i < g.V; i++)
    // {
    //     cout << i << " (" << g.articulation_points[i] << ")" << endl;
    // }
    g.bridges();

    return 0;
}