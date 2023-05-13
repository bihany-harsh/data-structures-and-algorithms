#include <iostream>
#include <list>
#include <queue>
#include <limits.h>
using namespace std;

int WHITE = 0;
int GRAY = 1;
int BLACK = 2;

class Graph
{
public:
    int V;    // No. of vertices
    int time; // Global variable to keep track of time
    int dfn;
    list<int> *adjacency_list; // Adjacency lists
    int *color;                // To store color of vertices
    int *parent;               // To store parent of vertices
    int *d;                    // Discovery time
    int *f;                    // Finishing time
    int *DFN;

    // Constructor
    Graph(int V)
    {
        this->V = V;
        adjacency_list = new list<int>[V];
        color = new int[V];
        parent = new int[V];
        d = new int[V];
        f = new int[V];
        DFN = new int[V];
    }

    void add_edge(int u, int v);
    void display_graph();
    void BFS(int x);
    void DFS();
    void DFS_visit(int v);
    void display_dfs();
};

void Graph::add_edge(int u, int v)
{
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
}

void Graph::display_graph()
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (auto j = adjacency_list[i].begin(); j != adjacency_list[i].end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
}

void Graph::BFS(int x)
{
    int *distance = new int[V];
    int *visited = new int[V];
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    queue<int> q;
    q.push(x);
    distance[x] = 0;
    visited[x] = 1;
    cout << x << " (" << distance[x] << ")" << endl;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u = adjacency_list[v].begin(); u != adjacency_list[v].end(); u++)
        {
            if (!visited[*u])
            {
                distance[*u] = distance[v] + 1;
                visited[*u] = 1;
                q.push(*u);
                cout << *u << " (" << distance[*u] << ")" << endl;
            }
        }
    }
}

void Graph::DFS_visit(int v)
{
    {
        color[v] = 1; // GRAY
        time++;
        d[v] = time;
        DFN[v] = ++dfn;
        for (auto i = adjacency_list[v].begin(); i != adjacency_list[v].end(); ++i)
        {
            if (color[*i] == 0)
            { // WHITE
                parent[*i] = v;
                DFS_visit(*i);
            }
        }
        color[v] = 2; // BLACK
        time++;
        f[v] = time;
    }
}

void Graph::DFS()
{
    for (int i = 0; i < V; i++)
    {
        color[i] = 0;   // WHITE
        parent[i] = -1; // NIL
    }
    time = 0;
    for (int i = 0; i < V; i++)
    {
        if (color[i] == 0)
        { // WHITE
            DFS_visit(i);
        }
    }
}

void Graph::display_dfs()
{
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex: " << i << ", Discovery time: " << d[i]
             << ", Finishing time: " << f[i] << ", DFN: " << DFN[i] << endl;
    }
}

int main()
{
    Graph g(6);

    g.add_edge(0, 5);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(3, 5);

    g.display_graph();

    g.BFS(0);
    cout << endl;

    g.DFS();
    cout << endl;
    g.display_dfs();

    return 0;
}