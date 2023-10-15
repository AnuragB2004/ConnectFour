#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

char board[ROWS][COLS];

void initializeBoard()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-----------------------------" << endl;
    }
    cout << "  1   2   3   4   5   6   7" << endl;
}

bool isColumnFull(int col)
{
    return board[0][col] != ' ';
}

bool makeMove(int col, char player)
{
    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (board[i][col] == ' ')
        {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

bool checkWin(char player)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
            {
                return true;
            }
        }
    }
    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player)
            {
                return true;
            }
        }
    }
    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
            {
                return true;
            }
        }
    }
    for (int i = 3; i < ROWS; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    initializeBoard();
    int currentPlayer = 1;
    bool gameEnd = false;
    while (!gameEnd)
    {
        printBoard();
        int column;
        cout << "Player " << currentPlayer << ", enter a column (1-7): ";
        cin >> column;
        if (column < 1 || column > 7)
        {
            cout << "Invalid input. Please enter a number between 1 and 7." << endl;
            continue;
        }
        if (isColumnFull(column - 1))
        {
            cout << "Column is full. Choose another one." << endl;
            continue;
        }
        if (!makeMove(column - 1, currentPlayer == 1 ? 'X' : 'O'))
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        if (checkWin(currentPlayer == 1 ? 'X' : 'O'))
        {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameEnd = true;
        }
        else
        {
            currentPlayer = currentPlayer == 1 ? 2 : 1;
        }
    }
    return 0;
}
