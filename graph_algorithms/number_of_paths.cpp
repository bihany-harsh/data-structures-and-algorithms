#include <iostream>
#include <list>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj_list;
    bool *visited;

    Graph(int V)
    {
        this->V = V;
        adj_list = new list<int>[V];
        visited = new bool[V];
    }

    void add_edge(int u, int v);
    void DFS_visit(int u, int v, int &count);
    int count_paths(int u, int v);
};

void Graph::add_edge(int u, int v)
{
    adj_list[u].push_back(v);
}

void Graph::DFS_visit(int u, int v, int &count)
{
    if (u == v)
        count++;
    else
    {
        for (list<int>::iterator i = adj_list[u].begin(); i != adj_list[u].end(); i++)
        {
            DFS_visit(*i, v, count);
        }
    }
}

int Graph::count_paths(int u, int v)
{
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    DFS_visit(u, v, count);
    return count;
}

int main()
{
    Graph g(6);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 3);
    // g.add_edge(2, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);

    cout << g.count_paths(0, 3) << endl;
}