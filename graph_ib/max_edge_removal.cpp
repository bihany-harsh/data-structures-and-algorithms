// given a tree of even nodes, maximum edges that can be removed such that the constituting subtrees also have even nodes
#include <iostream>
#include <vector>
using namespace std;

void DFS_for_size(vector<vector<int>> &adj_list, vector<int> &size, vector<bool> &visited, int node)
{
    visited[node] = true;
    size[node] = 1;
    for (auto neighbour: adj_list[node])
    {
        if (!visited[neighbour])
        {
            DFS_for_size(adj_list, size, visited, neighbour);
            size[node] += size[neighbour];
        }
    }
}

void DFS_for_removal(vector<vector<int>> &adj_list, vector<int> &size, vector<bool>& visited, int node, int &count)
{
    visited[node] = true;
    for (auto neighbour: adj_list[node])
    {
        if (!visited[neighbour])
        {
            if (size[neighbour] % 2 == 0)
                count++;
            DFS_for_removal(adj_list, size, visited, neighbour, count);
        }
    }
}

vector<int> size_of_tree(vector<vector<int>> &adj_list)
{
    // the function returns the array of the size of the subtree rooted at each node
    vector<int> size(adj_list.size(), 0);
    vector<bool> visited(adj_list.size(), false);
    DFS_for_size(adj_list, size, visited, 0);
    return size;
}

int max_edge_removal(int V, vector<vector<int>> &edges)
{
    // let us create the graph
    vector<vector<int>> adj_list(V);
    for (auto edge: edges)
    {
        adj_list[edge[0] - 1].push_back(edge[1] - 1);
        adj_list[edge[1] - 1].push_back(edge[0] - 1);
    }
    vector<int> size = size_of_tree(adj_list);
    int count = 0;

    vector<bool> visited(V, false);
    DFS_for_removal(adj_list, size, visited, 0, count);

    return count;
}