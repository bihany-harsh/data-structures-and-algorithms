#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adjacency_list;
    void DFS(int v, bool *visited, stack<int> &rec_stack);

    Graph(int V)
    {
        this->V = V;
        adjacency_list = new list<int>[V];
    }
    void add_edge(int v, int w);
    void topological_sort();
};

void Graph::add_edge(int v, int w)
{
    adjacency_list[v].push_back(w);
}

void Graph::DFS(int v, bool *visited, stack<int> &rec_stack)
{
    visited[v] = true;
    for (list<int>::iterator i = adjacency_list[v].begin(); i != adjacency_list[v].end(); i++)
    {
        if (!visited[*i])
            DFS(*i, visited, rec_stack);
    }
    rec_stack.push(v);
}

void Graph::topological_sort()
{
    stack <int> rec_stack;

    bool *visited = new bool [V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false)
        {
            DFS(i, visited, rec_stack);
        }
    }
    while (!rec_stack.empty())
    {
        cout << rec_stack.top() << " ";
        rec_stack.pop();
    }
    cout << endl;
}

int main()
{
    Graph g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);

    g.topological_sort();

    return 0;
}