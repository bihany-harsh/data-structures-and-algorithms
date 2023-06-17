#include <iostream>
#include <vector>
#include <list>
using namespace std;

void DFS(vector<list<int>> &adj_list, vector<int> &dfn, vector<int> &visited, int DFN, int v)
{
    visited[v] = 1;
    dfn[v] = DFN++;
    for (list<int>::iterator i = adj_list[v].begin(); i != adj_list[v].end(); i++)
    {
        if (!visited[*i])
        {
            DFS(adj_list, dfn, visited, DFN, *i);
        }
    }
}

int largest_dist(vector<int> &parents)
{
    vector<list<int>> adj_list(parents.size());
    for (int i = 0; i < parents.size(); i++)
    {
        if (parents[i] != -1)
        {
            adj_list[parents[i]].push_back(i);
            adj_list[i].push_back(parents[i]);
        }
    }
    // to calculate the farthest distance between two nodes

    // first DFS to find the farthest node from the root

    vector<int> dfn(parents.size(), 0);
    vector<int> visited(parents.size(), 0);
    int DFN = 1;
    DFS(adj_list, dfn, visited, DFN, 0);

    int farthest_node = 0;
    for (int i = 0; i < dfn.size(); i++)
    {
        if (dfn[i] > dfn[farthest_node])
            farthest_node = i;
    }

    // second DFS to find the farthest node from the farthest node from the root
    dfn = vector<int>(parents.size(), 0);
    visited = vector<int>(parents.size(), 0);
    DFN = 1;
    DFS(adj_list, dfn, visited, DFN, farthest_node);

    int farthest_node2 = 0;
    for (int i = 0; i < dfn.size(); i++)
    {
        if (dfn[i] > dfn[farthest_node2])
            farthest_node2 = i;
    }

    return dfn[farthest_node2] - 1;
}

int main()
{
    vector<int> parents = {-1, 0, 0, 0, 3};
    cout << largest_dist(parents) << endl;
    return 0;
}