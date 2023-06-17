#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int valid_points(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> visited_blue(n, vector<int>(m, 0));
    vector<vector<int>> visited_red(n, vector<int>(m, 0));
    queue<pair<int, int>> q_blue;
    queue<pair<int, int>> q_red;
    for (int i = 0; i < m; i++)
    {
        q_blue.push(make_pair(0, i));
        q_red.push(make_pair(n - 1, i));
        visited_blue[0][i] = 1;
        visited_red[n - 1][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        q_blue.push(make_pair(i, 0));
        q_red.push(make_pair(i, m - 1));
        visited_blue[i][0] = 1;
        visited_red[i][m - 1] = 1;
    }

    while (!q_blue.empty())
    {
        pair<int, int> point = q_blue.front();
        q_blue.pop();
        int x = point.first;
        int y = point.second;

        // up
        if (x - 1 >= 0 && !visited_blue[x - 1][y])
        {
            if (heights[x - 1][y] >= heights[x][y])
            {
                q_blue.push(make_pair(x - 1, y));
                visited_blue[x - 1][y] = 1;
            }
        }
        // down
        if (x + 1 < n && !visited_blue[x + 1][y])
        {
            if (heights[x + 1][y] >= heights[x][y])
            {
                q_blue.push(make_pair(x + 1, y));
                visited_blue[x + 1][y] = 1;
            }
        }
        // left
        if (y - 1 >= 0 && !visited_blue[x][y - 1])
        {
            if (heights[x][y - 1] >= heights[x][y])
            {
                q_blue.push(make_pair(x, y - 1));
                visited_blue[x][y - 1] = 1;
            }
        }
        // right
        if (y + 1 < m && !visited_blue[x][y + 1])
        {
            if (heights[x][y + 1] >= heights[x][y])
            {
                q_blue.push(make_pair(x, y + 1));
                visited_blue[x][y + 1] = 1;
            }
        }
    }

    while (!q_red.empty())
    {
        pair<int, int> point = q_red.front();
        q_red.pop();
        int x = point.first;
        int y = point.second;

        // up
        if (x - 1 >= 0 && !visited_red[x - 1][y])
        {
            if (heights[x - 1][y] >= heights[x][y])
            {
                q_red.push(make_pair(x - 1, y));
                visited_red[x - 1][y] = 1;
            }
        }
        // down
        if (x + 1 < n && !visited_red[x + 1][y])
        {
            if (heights[x + 1][y] >= heights[x][y])
            {
                q_red.push(make_pair(x + 1, y));
                visited_red[x + 1][y] = 1;
            }
        }
        // left
        if (y - 1 >= 0 && !visited_red[x][y - 1])
        {
            if (heights[x][y - 1] >= heights[x][y])
            {
                q_red.push(make_pair(x, y - 1));
                visited_red[x][y - 1] = 1;
            }
        }
        // right
        if (y + 1 < m && !visited_red[x][y + 1])
        {
            if (heights[x][y + 1] >= heights[x][y])
            {
                q_red.push(make_pair(x, y + 1));
                visited_red[x][y + 1] = 1;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited_blue[i][j] && visited_red[i][j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    // vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> heights = {{2, 2}, {2, 2}};
    cout << valid_points(heights) << endl;
}