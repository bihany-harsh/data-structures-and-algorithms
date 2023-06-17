#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool DFS(vector<string>&board, string str, int i, int j, int index)
{
    if (index == str.size() - 1)
    {
        return true;
    }
    // up
    if (i - 1 >= 0 && board[i - 1][j] == str[index + 1])
    {
        if (DFS(board, str, i - 1, j, index + 1))
            return true;
    }
    // down
    if (i + 1 < board.size() && board[i + 1][j] == str[index + 1])
    {
        if (DFS(board, str, i + 1, j, index + 1))
            return true;
    }
    // left
    if (j - 1 >= 0 && board[i][j - 1] == str[index + 1])
    {
        if (DFS(board, str, i, j - 1, index + 1))
            return true;
    }
    // right
    if (j + 1 < board[0].size() && board[i][j + 1] == str[index + 1])
    {
        if (DFS(board, str, i, j + 1, index + 1))
            return true;
    }
    return false;
}

bool exists(vector<string> &board, string str)
{
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (board[i][j] == str[0])
            {
                if (DFS(board, str, i, j, 0))
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<string> board = {"ABCE", "SFCS", "ADEE"};
    string str = "ABCCED";
    cout << exists(board, str) << endl;
    return 0;
}
