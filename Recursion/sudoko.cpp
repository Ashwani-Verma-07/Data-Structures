#include <bits/stdc++.h>
using namespace std;
bool isVal(vector<vector<int>> &board, int row, int col, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;
        if (board[row][i] == c)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool solveSudoko(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isVal(board, i, j, k))
                    {
                        board[i][j] = k;
                        if (solveSudoko(board) == true)
                            return true;
                        else
                            board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<int>> &board)
{
    return solveSudoko(board);
}

int main()
{
    int flag = 1;
    vector<vector<int>> board{
        {0, 7, 0, 0, 1, 5, 0, 0, 3},
        {2, 6, 0, 0, 0, 3, 5, 0, 9},
        {3, 5, 0, 0, 0, 6, 1, 4, 0},
        {0, 2, 5, 8, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 0, 0, 1, 2, 9, 0},
        {0, 1, 2, 6, 0, 0, 0, 8, 4},
        {9, 0, 3, 1, 0, 0, 0, 5, 6},
        {5, 0, 0, 3, 4, 0, 0, 2, 0}};
    if (solve(board))
        for (int i = 0; i < 9; i++)
        {
            cout << "\t";
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    else
        cout << "Entered Sudoko is Wrong" << endl;
}
//output:
//         4 7 9 2 1 5 8 6 3 
//         2 6 1 4 8 3 5 7 9 
//         3 5 8 9 7 6 1 4 2 
//         1 2 5 8 9 4 6 3 7 
//         6 9 7 5 3 2 4 1 8 
//         8 3 4 7 6 1 2 9 5 
//         7 1 2 6 5 9 3 8 4 
//         9 4 3 1 2 8 7 5 6 
//         5 8 6 3 4 7 9 2 1 
