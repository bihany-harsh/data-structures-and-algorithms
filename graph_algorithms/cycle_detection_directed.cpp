#include <iostream>
#include <list>
#include <limits.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adjacency_list;

    Graph(int V)
    {
        this->V = V;
        adjacency_list = new list<int>[V];
    }

    void add_edge(int u, int v);

    // DFS type algo for edge detection
    bool DFS_for_cycle_detection();
    bool DFS_util(int v, bool *visited, bool *in_rec_stack);
};

void Graph::add_edge(int u, int v)
{
    adjacency_list[u].push_back(v);
}

bool Graph::DFS_util(int v, bool *visited, bool *in_rec_stack)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        in_rec_stack[v] = true;
        for (list<int>::iterator i = adjacency_list[v].begin(); i != adjacency_list[v].end(); i++)
        {
            if (!visited[*i] && DFS_util(*i, visited, in_rec_stack))
            {
                return true;
            }
            else if (in_rec_stack[*i])
            {
                return true;
            }
        }
    }
    in_rec_stack[v] = false;
    return false;
}

bool Graph::DFS_for_cycle_detection()
{
    bool *visited = new bool[V];
    bool *in_rec_stack = new bool[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        in_rec_stack[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (DFS_util(i, visited, in_rec_stack))
            return true;
    }
    return false;
}

int main()
{
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    // g.add_edge(2, 0);
    g.add_edge(2, 3);

    if (g.DFS_for_cycle_detection())
        cout << "There is a cycle" << endl;
    else
        cout << "There is no cycle" << endl;

    return 0;
}