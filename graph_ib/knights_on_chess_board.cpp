#include <iostream>
#include <utility>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int min_possible_steps(int n, int m, int x_init, int y_init, int x_fin, int y_fin)
{
    vector<vector<int>> visited_grid(n, vector<int>(m, 0));
    vector<vector<int>> dist_grid(n, vector<int>(m, INT_MAX));

    int row_init = y_init - 1;
    int col_init = x_init - 1;

    int row_fin = y_fin - 1;
    int col_fin = x_fin - 1;

    queue<pair<int, int>> q;
    q.push(make_pair(row_init, col_init));
    visited_grid[row_init][col_init] = 1;
    dist_grid[row_init][col_init] = 0;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();
        // all nodes reachable

        // up-up-left
        if ((v.first + 2 < n) && (v.second + 1 < m) && !visited_grid[v.first + 2][v.second + 1])
        {
            visited_grid[v.first + 2][v.second + 1] = 1;
            dist_grid[v.first + 2][v.second + 1] = dist_grid[v.first][v.second] + 1;
            q.push(make_pair(v.first + 2, v.second + 1));
        }

        // left-left-up
        if ((v.first + 1 < n) && (v.second + 2 < m) && !visited_grid[v.first + 1][v.second + 2])
        {
            visited_grid[v.first + 1][v.second + 2] = 1;
            dist_grid[v.first + 1][v.second + 2] = dist_grid[v.first][v.second] + 1;
            q.push(make_pair(v.first + 1, v.second + 2));
        }

        // left-left-down
        if ((v.first - 1 >= 0) && (v.second + 2 < m) && !visited_grid[v.first - 1][v.second + 2])
        {
            visited_grid[v.first - 1][v.second + 2] = 1;
            dist_grid[v.first - 1][v.second + 2] = dist_grid[v.first][v.second] + 1;
            q.push(make_pair(v.first - 1, v.second + 2));
        }

        // down-down-left
        if ((v.first - 2 >= 0) && (v.second + 1 < m) && !visited_grid[v.first - 2][v.second + 1])
        {
            visited_grid[v.first - 2][v.second + 1] = 1;
            dist_grid[v.first - 2][v.second + 1] = dist_grid[v.first][v.second] + 1;
            q.push(make_pair(v.first - 2, v.second + 1));
        }

        // down-down-right
        if ((v.first - 2 >= 0) && (v.second - 1 >= 0) && !visited_grid[v.first - 2][v.second - 1])
        {
            visited_grid[v.first - 2][v.second - 1] = 1;
            dist_grid[v.first - 2][v.second - 1] = dist_grid[v.first][v.second] + 1;
            q.push(make_pair(v.first - 2, v.second - 1));
        }

        // right-right-down
        if ((v.first - 1 >= 0) && (v.second - 2 >= 0) && !visited_grid[v.first - 1][v.second - 2])
        {
            visited_grid[v.first - 1][v.second - 2] = 1;
            dist_grid[v.first - 1][v.second - 2] = dist_grid[v.first][v.second] + 1;
            q.push(make_pair(v.first - 1, v.second - 2));
        }

        // right-right-up
        if ((v.first + 1 < n) && (v.second - 2 >= 0) && !visited_grid[v.first + 1][v.second - 2])
        {
            visited_grid[v.first + 1][v.second - 2] = 1;
            dist_grid[v.first + 1][v.second - 2] = dist_grid[v.first][v.second] + 1;
            q.push(make_pair(v.first + 1, v.second - 2));
        }

        // up-up-right
        if ((v.first + 2 < n) && (v.second - 1 >= 0) && !visited_grid[v.first + 2][v.second - 1])
        {
            visited_grid[v.first + 2][v.second - 1] = 1;
            dist_grid[v.first + 2][v.second - 1] = dist_grid[v.first][v.second] + 1;
            q.push(make_pair(v.first + 2, v.second - 1));
        }

        if (visited_grid[row_fin][col_fin])
        {
            return dist_grid[row_fin][col_fin];
        }
    }

    return -1;
}

int main()
{
    int n = 4, m = 7, y_init = 2, x_init = 6, y_fin = 2, x_fin = 4;

    cout << min_possible_steps(n, m, x_init, y_init, x_fin, y_fin) << endl;

    return 0;
}