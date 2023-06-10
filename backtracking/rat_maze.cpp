#include <iostream>
#include <vector>
using namespace std;

bool rat_maze_util(vector<vector<int>> &maze, vector<vector<int>> &sol, int x, int y)
{
    int n = maze.size();
    if (x == (n - 1) && y == (n - 1))
    {
        sol[x][y] = 1;
        return true;
    }
    sol[x][y] = 1;
    for (int i = 1; i <= maze[x][y]; i++)
    {
        if (x + i < n && maze[x + i][y] != 0)
        {
            if (rat_maze_util(maze, sol, x + i, y))
                return true;
        }
        if (y + i < n && maze[x][y + i] != 0)
        {
            if (rat_maze_util(maze, sol, x, y + i))
                return true;
        }
    }
    sol[x][y] = 0;
    return false;
}

vector<vector<int>> rat_maze(vector<vector<int>> &maze)
{
    int n = maze.size();
    vector<vector<int>> sol(n, vector<int>(n, 0));

    if (maze[0][0] == 0)
        return sol;

    if (rat_maze_util(maze, sol, 0, 0))
    {
        return sol;
    }
    else
    {
        return vector<vector<int>>();
    }
}

void print(vector<vector<int>> &sol)
{
    for (auto i : sol)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> maze = {{2, 1, 0, 0},
                                {3, 0, 0, 1},
                                {0, 1, 0, 1},
                                {0, 0, 0, 1}};
    vector<vector<int>> sol = rat_maze(maze);
    if (sol.size() == 0)
        cout << "No solution exists" << endl;
    else
        print(sol);
    return 0;
}