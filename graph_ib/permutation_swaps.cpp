#include <iostream>
#include <vector>
using namespace std;

int find_par(int node, vector<int> &parent)
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = find_par(parent[node], parent);
}

void union_set(int u, int v, vector<int> &rank, vector<int> &parent)
{
    u = find_par(u, parent);
    v = find_par(v, parent);

    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[v] > rank[u])
    {
        parent[u] = v;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int is_permute_possible(vector<int> &A, vector<int> &B, vector<vector<int>> &edges)
{

    int n = A.size();
    vector<int> parent(n, 0);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < edges.size(); i++)
    {
        int u = A[edges[i][0] - 1] - 1;
        int v = A[edges[i][1] - 1] - 1;

        union_set(u, v, rank, parent);
    }

    for (int i = 0; i < A.size(); i++)
    {
        if (find_par(A[i] - 1, parent) != find_par(B[i] - 1, parent))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {1, 4, 2, 3};
    vector<vector<int>> edges = {{3, 4}};
    cout << is_permute_possible(A, B, edges) << endl;
    return 0;
}