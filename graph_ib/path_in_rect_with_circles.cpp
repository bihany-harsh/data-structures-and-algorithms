#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int is_possible(int n, int m, int num_of_circles, int radius, vector<int> &x_coord, vector<int> &y_coord)
{
    vector<vector<int>> grid(n, vector<int>(m, 0));

    // marking blocked cells
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < num_of_circles; k++)
            {
                if ((i - x_coord[k]) * (i - x_coord[k]) + (j - y_coord[k]) * (j - y_coord[k]) <= radius * radius)
                {
                    grid[i][j] = -1;
                }
            }
        }
    }

    if (grid[0][0] == -1 || grid[n - 1][m - 1] == -1)
        return 0;

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while(!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();

        // top-left
        if (v.first - 1 >= 0 && v.second - 1 >= 0 && grid[v.first - 1][v.second - 1] == 0)
        {
            q.push(make_pair(v.first - 1, v.second - 1));
            grid[v.first - 1][v.second - 1] = 1;
        }
        // top
        if (v.first - 1 >= 0 && grid[v.first - 1][v.second] == 0)
        {
            q.push(make_pair(v.first - 1, v.second));
            grid[v.first - 1][v.second] = 1;
        }
        // top-right
        if (v.first - 1 >= 0 && v.second + 1 < m && grid[v.first - 1][v.second + 1] == 0)
        {
            q.push(make_pair(v.first - 1, v.second + 1));
            grid[v.first - 1][v.second + 1] = 1;
        }
        // right
        if (v.second + 1 < m && grid[v.first][v.second + 1] == 0)
        {
            q.push(make_pair(v.first, v.second + 1));
            grid[v.first][v.second + 1] = 1;
        }
        // bottom-right
        if (v.first + 1 < n && v.second + 1 < m && grid[v.first + 1][v.second + 1] == 0)
        {
            q.push(make_pair(v.first + 1, v.second + 1));
            grid[v.first + 1][v.second + 1] = 1;
        }
        // bottom
        if (v.first + 1 < n && grid[v.first + 1][v.second] == 0)
        {
            q.push(make_pair(v.first + 1, v.second));
            grid[v.first + 1][v.second] = 1;
        }
        // bottom-left
        if (v.first + 1 < n && v.second - 1 >= 0 && grid[v.first + 1][v.second - 1] == 0)
        {
            q.push(make_pair(v.first + 1, v.second - 1));
            grid[v.first + 1][v.second - 1] = 1;
        }
        // left
        if (v.second - 1 >= 0 && grid[v.first][v.second - 1] == 0)
        {
            q.push(make_pair(v.first, v.second - 1));
            grid[v.first][v.second - 1] = 1;
        }
    }

    if (grid[n - 1][m - 1] == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int n = 2, m = 3, num_of_circles = 1, radius = 1;
    vector<int> x_coord = {2}, y_coord = {3};

    cout << is_possible(n, m, num_of_circles, radius, x_coord, y_coord) << endl;

    return 0;
}