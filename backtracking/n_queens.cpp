#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

bool N_Queens(vector<vector<int>> &board, int N, int col)
{
    if (col == N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, col, i))
        {
            board[i][col] = 1;
            if (N_Queens(board, N, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int N = 16;
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (N_Queens(board, N, 0))
    {
        for (auto i : board)
        {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
    }
    else
        cout << "No solution exists" << endl;
    return 0;
}