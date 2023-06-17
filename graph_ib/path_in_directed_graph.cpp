#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// to return whether a path from 1 to n
int is_path(int N, vector<vector<int>> &edges)
{
    // making the adjacency list
    vector<list<int>> adj_list(N);
    for (int i = 0; i < edges.size(); i++)
    {
        adj_list[edges[i][0] - 1].push_back(edges[i][1] - 1);
    }

    // BFS
    vector<int> visited(N, 0);
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        visited[v] = 1;
        for (list<int>::iterator i = adj_list[v].begin(); i != adj_list[v].end(); i++)
        {
            if (*i == N - 1)
                return 1;
            if (!visited[*i])
            {
                q.push(*i);
            }
        }
    }

    return 0;
}

int main()
{
    int N = 5;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << is_path(N, edges) << endl;
    return 0;
}