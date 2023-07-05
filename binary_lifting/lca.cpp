// to find the lowest common ancestor in a N-ary tree
// https://youtu.be/dOAxrhAUIhA
#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj,
         vector<bool> &visited, vector<vector<int>> &up,
         vector<int> &depth, int LOG)
{
    visited[node] = true;
    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            depth[child] = depth[node] + 1;
            up[child][0] = node;
            for (int j = 1; j < LOG; j++)
                up[child][j] = up[up[child][j - 1]][j - 1];

            dfs(child, adj, visited, up, depth, LOG);
        }
    }
}

vector<int> lca(vector<int> &parent, vector<vector<int>> &queries)
{
    int n = parent.size();
    int LOG = 0;
    while ((1 << LOG) <= n)
        LOG++;

    vector<vector<int>> up(n, vector<int>(LOG));
    vector<int> depth(n, 0);
    vector<vector<int>> adj(n);

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = i;
        } else {
            adj[parent[i]].push_back(i);
        }
    }
    
    vector<bool> visited(n, false);
    dfs(root, adj, visited, up, depth, LOG);

    vector<int> ans;

    for (auto query : queries)
    {
        int u = query[0];
        int v = query[1];
        if (depth[u] > depth[v])
            swap(u, v);

        // making v as the deeper node

        int diff = depth[v] - depth[u];

        for (int i = 0; i < LOG; i++)
            if ((diff >> i) & 1)
                v = up[v][i];

        // making the depth of v same as that of u

        if (u == v) // important case, as otherwise we will get the parent of lca
        {
            ans.push_back(u);
            continue;
        }

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (up[u][i] != up[v][i])
            {
                u = up[u][i]; // going up closest to lca
                v = up[v][i];
            }
        }

        ans.push_back(up[u][0]);
    }

    return ans;
}

int main()
{
    int n = 9;
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2, 3, 3};
    vector<vector<int>> queries = {{4, 5}, {4, 6}, {4, 7}, {4, 8}, {4, 0}};

    vector<int> ans = lca(parent, queries);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
