#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class disjoint_sets
{
public:
    int N;
    int *parent;
    int *size;

    disjoint_sets(int N)
    {
        this->N = N;
        parent = new int[N];
        size = new int[N];
        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Find(int i);
    bool Is_same_set(int i, int j);
    void Union(int i, int j);
};

int disjoint_sets::Find(int i)
{
    if (parent[i] == i)
        return i;
    else
    {
        parent[i] = Find(parent[i]);
        return parent[i];
    }
}

void disjoint_sets::Union(int i, int j)
{
    int i_id = Find(i);
    int j_id = Find(j);
    if (i_id == j_id)
        return;
    if (size[i_id] > size[j_id])
    {
        parent[j_id] = i_id;
        size[i_id] += size[j_id];
        size[j_id] = 0;
    }
    else
    {
        parent[i_id] = j_id;
        size[j_id] += size[i_id];
        size[i_id] = 0;
    }
}

bool disjoint_sets::Is_same_set(int i, int j)
{
    return Find(i) == Find(j);
}

class Graph 
{
public:
    int V;
    vector<pair<int, pair<int, int>>> edges;
    vector<pair<int, pair<int, int>>> mst;
    int mst_weight = 0;

    Graph(int V)
    {
        this->V = V;
    }

    void add_edge(int u, int v, int w);
    void kruskals();
};

void Graph::add_edge(int u, int v, int weight)
{
    edges.push_back(make_pair(weight, make_pair(u, v)));
}

void Graph::kruskals()
{
    sort(edges.begin(), edges.end());
    disjoint_sets ds(V);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (!ds.Is_same_set(u, v))
        {
            mst.push_back(edges[i]);
            mst_weight += edges[i].first;
            ds.Union(u, v);
        }
    }
}

int main()
{
    Graph g(9);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    g.kruskals();
    cout << "MST weight: " << g.mst_weight << endl;
    for (int i = 0; i < g.mst.size(); i++)
    {
        cout << g.mst[i].second.first << " " << g.mst[i].second.second << " " << g.mst[i].first << endl;
    }
    return 0;
}
