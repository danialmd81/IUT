#include <iostream>
#include <vector>

using namespace std;

bool isValidMove(vector<vector<int>>& board, int row, int col, int num) {
    int x = 0;
    while (x < 9) {
        if (board[row][x] == num) {
            return false;
        }
        x++;
    }

    x = 0;
    while (x < 9) {
        if (board[x][col] == num) {
            return false;
        }
        x++;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    int i = 0;
    while (i < 3) {
        int j = 0;
        while (j < 3) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
            j++;
        }
        i++;
    }

    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    int row = 0;
    while (row < 9) {
        int col = 0;
        while (col < 9) {
            if (board[row][col] == 0) {
                int num = 1;
                while (num <= 9) {
                    if (isValidMove(board, row, col, num)) {
                        board[row][col] = num;

                        if (solveSudoku(board)) {
                            return true;
                        }

                        board[row][col] = 0;
                    }
                    num++;
                }
                return false;
            }
            col++;
        }
        row++;
    }
    return true;
}

void printBoard(vector<vector<int>>& board) {
    int i = 0;
    while (i < 9) {
        int j = 0;
        while (j < 9) {
            cout << board[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

int main() {
    vector<vector<int>> board(9, vector<int>(9));

    int i = 0;
    while (i < 9) {
        int j = 0;
        while (j < 9) {
            cin >> board[i][j];
            j++;
        }
        i++;
    }

    if (solveSudoku(board)) {
        cout << endl;
        printBoard(board);
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
