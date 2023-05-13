#include <iostream>
#include <queue>
#include <stack>
#include <list>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj_list;

    Graph(int V)
    {
        this->V = V;
        adj_list = new list<int>[V];
    }

    void add_edge(int u, int v);
    void topological_sort();
};

void Graph::add_edge(int u, int v)
{
    adj_list[u].push_back(v);
}

void Graph::topological_sort()
{
    int *in_degree = new int[V];
    for (int i = 0; i < V; i++)
    {
        for (list<int>::iterator j = adj_list[i].begin(); j != adj_list[i].end(); j++)
        {
            in_degree[*j] = in_degree[*j] + 1;
        }
    }

    queue<int> q;
    queue<int> topological_order;

    for (int i = 0; i < V; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    int num_visited = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        num_visited++;
        topological_order.push(u);
        for (list<int>::iterator v = adj_list[u].begin(); v != adj_list[u].end(); v++)
        {
            in_degree[*v] = in_degree[*v] - 1;
            if (in_degree[*v] == 0)
                q.push(*v);
        }
    }

    if (num_visited != V)
    {
        cout << "Graph has a cycle" << endl;
        return;
    }

    while (!topological_order.empty())
    {
        cout << topological_order.front() << " ";
        topological_order.pop();
    }
    cout << endl;
}

int main()
{
    // Graph g(6);
    // g.add_edge(5, 2);
    // g.add_edge(5, 0);
    // g.add_edge(4, 0);
    // g.add_edge(4, 1);
    // g.add_edge(2, 3);
    // g.add_edge(3, 1);

    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    // g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.topological_sort();
    return 0;
}