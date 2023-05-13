#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int WHITE = 0;
int GRAY = 1;
int BLACK = 2;

class Graph
{
public:
    int V;
    list<int> *adj_list;
    int time;
    vector<int> scc;

    // dfs related lists
    pair<int, int> *finishing_time;
    pair<int, int> *discovery_time;
    int *order_for_dfs;
    int *color;
    int *parent;

    Graph(int V)
    {
        this->V = V;
        adj_list = new list<int>[V];
        finishing_time = new pair<int, int>[V];
        discovery_time = new pair<int, int>[V];
        color = new int[V];
        parent = new int[V];
        order_for_dfs = new int[V];
        for (int i = 0; i < V; i++)
            order_for_dfs[i] = i;
    }

    void add_edge(int u, int v);
    void DFS_visit(int u, bool to_print);
    void DFS(bool to_print);
    void print_scc();
};

void Graph::add_edge(int u, int v)
{
    adj_list[u].push_back(v);
}

void Graph::DFS_visit(int u, bool to_print)
{
    color[u] = GRAY;
    time++;
    discovery_time[u] = make_pair(u, time);
    if(to_print)
        cout << u << " ";
    for (list<int>::iterator v = adj_list[u].begin(); v != adj_list[u].end(); v++)
    {
        if (color[*v] == WHITE)
        {
            parent[*v] = u;
            DFS_visit(*v, to_print);
        }
    }
    color[u] = BLACK;
    time++;
    finishing_time[u] = make_pair(u, time);
}

void Graph::DFS(bool to_print)
{
    for (int i = 0; i < V; i++)
    {
        color[i] = WHITE;
        parent[i] = -1;
    }
    time = 0;
    for (int i = 0; i < V; i++)
    {
        if (color[order_for_dfs[i]] == WHITE)
        {
            DFS_visit(i, to_print);
        }
    }
}

void Graph::print_scc()
{
    for (int i = 0; i < V; i++)
    {
        if (color[i] == WHITE)
        {
            DFS_visit(i, true);
            cout << "\n";
        }
    }
}

bool custom_comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

void find_scc(Graph &g)
{
    g.DFS(false);
    Graph g_T(g.V);
    for (int i = 0; i < g.V; i++)
    {
        for (list<int>::iterator j = g.adj_list[i].begin(); j != g.adj_list[i].end(); j++)
        {
            g_T.adj_list[*j].push_back(i);
        }
    }
    sort(g.finishing_time, g.finishing_time + g.V, custom_comp);
    for (int i = 0; i < g.V; i++)
    {
        g_T.order_for_dfs[i] = g.finishing_time[i].first;
    }
    g_T.print_scc();
}

int main() 
{
    Graph g(8); // Creating a graph with 8 vertices
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 0);
    g.add_edge(4, 5);
    g.add_edge(5, 6);
    g.add_edge(6, 4);
    g.add_edge(6, 7);

    cout << "Following are strongly connected components in the given graph \n";
    find_scc(g);
  
    return 0;
}

