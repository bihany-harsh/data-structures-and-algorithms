#include <iostream>
#include <vector>
#include <list>
using namespace std;

int is_bipartite (vector<list<int>> &adj_list)
{
    vector<int> color(adj_list.size(), -1);
    vector<int> visited(adj_list.size(), 0);
    for (int i = 0; i < adj_list.size(); i++)
    {
        if (!visited[i])
        {
            list<int> queue;
            queue.push_back(i);
            color[i] = 0;
            visited[i] = 1;
            while (!queue.empty())
            {
                int v = queue.front();
                queue.pop_front();
                for (list<int>::iterator i = adj_list[v].begin(); i != adj_list[v].end(); i++)
                {
                    if (!visited[*i])
                    {
                        queue.push_back(*i);
                        color[*i] = 1 - color[v];
                        visited[*i] = 1;
                    }
                    else if (color[*i] == color[v])
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int two_teams_possible(int N, vector<vector<int>> &enemies)
{
    // create the graph
    vector<list<int>> adj_list(N);
    for (int i = 0; i < enemies.size(); i++)
    {
        adj_list[enemies[i][0] - 1].push_back(enemies[i][1] - 1);
        adj_list[enemies[i][1] - 1].push_back(enemies[i][0] - 1);
    }

    return is_bipartite(adj_list);
}

int main()
{
    int N = 4;
    vector<vector<int>> enemies = {{1, 4}, {3, 1}, {4, 3}, {2, 1}};
    cout << two_teams_possible(N, enemies) << endl;
    return 0;
}