#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool DFS(vector<list<int>> &adj_list, vector<bool> &visited, vector<int> &parent, int v)
{
    visited[v] = true;

    for (int i : adj_list[v])
    {
        if (!visited[i])
        {
            parent[i] = v;
            if (DFS(adj_list, visited, parent, i))
                return true;
        }
        else if (parent[v] != i)
            return true;
    }
    return false;
}

int is_cyclic(int N, vector<vector<int>> &edges)
{
    vector<list<int>> adj_list(N);
    for (int i = 0; i < edges.size(); i++)
    {
        adj_list[edges[i][0] - 1].push_back(edges[i][1] - 1);
        adj_list[edges[i][1] - 1].push_back(edges[i][0] - 1);
    }

    // to detect cycle in undirected graph

    vector<bool> visited(N, false);
    vector<int> parent(N, -1);

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            if (DFS(adj_list, visited, parent, i))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int N = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}, {1, 4}, {4, 5}};
    cout << is_cyclic(N, edges) << endl;
    return 0;
}