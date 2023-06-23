#include <iostream>
#include <vector>
#include <list>
using namespace std;

void DFS(vector<list<int>> &adj_list, int v, vector<int> &leafs, vector<int> &visited)
{
    for (list<int>::iterator i = adj_list[v].begin(); i != adj_list[v].end(); i++)
    {
        if (!visited[*i])
        {
            visited[*i] = 1;
            DFS(adj_list, *i, leafs, visited);
            leafs[v] += leafs[*i];
        }
    }
    if (leafs[v] == 0)
    {
        leafs[v] = 1;
    }
}

int main()
{
    int iterations;
    cin >> iterations;
    while (iterations--)
    {
        int n;
        cin >> n;
        vector<list<int>> tree(n);
        int u, v;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }
        vector<int> leafs(n, 0);
        vector<int> visited(n, 0);
        DFS(tree, 0, leafs, visited);
        int queries;
        cin >> queries;
        int x, y;
        while (queries--)
        {
            cin >> x >> y;
            cout << leafs[x - 1] * leafs[y - 1] << endl;
        }
    }
}