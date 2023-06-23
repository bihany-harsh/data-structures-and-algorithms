#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;;

int BFS(vector<vector<int>> &map, vector<int> &query)
{
    if (map.size() == 0)
        return -1;
    if (map[query[0] - 1][query[1] - 1] == 1)
        return 0;
    int n = map.size(), m = map[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push(make_pair(query[0] - 1, query[1] - 1));
    visited[query[0] - 1][query[1] - 1] = 1;
    vector<vector<int>> distance(n, vector<int>(m, 0));
    while (!q.empty())
    {
        pair<int, int> point = q.front();
        q.pop();
        // up
        if (point.first - 1 >= 0 && !visited[point.first - 1][point.second])
        {
            q.push(make_pair(point.first - 1, point.second));
            visited[point.first - 1][point.second] = 1;
            distance[point.first - 1][point.second] = distance[point.first][point.second] + 1;

            if (map[point.first - 1][point.second] == 1)
                return distance[point.first - 1][point.second];
        }
        // down
        if (point.first + 1 < n && !visited[point.first + 1][point.second])
        {
            q.push(make_pair(point.first + 1, point.second));
            visited[point.first + 1][point.second] = 1;
            distance[point.first + 1][point.second] = distance[point.first][point.second] + 1;

            if (map[point.first + 1][point.second] == 1)
                return distance[point.first + 1][point.second];
        }
        // left
        if (point.second - 1 >= 0 && !visited[point.first][point.second - 1])
        {
            q.push(make_pair(point.first, point.second - 1));
            visited[point.first][point.second - 1] = 1;
            distance[point.first][point.second - 1] = distance[point.first][point.second] + 1;

            if (map[point.first][point.second - 1] == 1)
                return distance[point.first][point.second - 1];
        }
        // right
        if (point.second + 1 < m && !visited[point.first][point.second + 1])
        {
            q.push(make_pair(point.first, point.second + 1));
            visited[point.first][point.second + 1] = 1;
            distance[point.first][point.second + 1] = distance[point.first][point.second] + 1;

            if (map[point.first][point.second + 1] == 1)
                return distance[point.first][point.second + 1];
        }
    }
    return -1;
}

vector<int> nearest_hotel(vector<vector<int>> &map, vector<vector<int>> &queries)
{
    vector<int> result;
    for (int i = 0; i < queries.size(); i++)
    {
        result.push_back(BFS(map, queries[i]));
    }
    return result;
}

int main()
{
    vector<vector<int>> map = {{1, 0, 0, 1}};
    vector<vector<int>> queries = {{1, 2}, {1, 3}};
    vector<int> result = nearest_hotel(map, queries);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;

    return 0;
}