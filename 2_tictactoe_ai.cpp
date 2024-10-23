#include <iostream>
#include <time.h>
using namespace std;

void display(char board[3][3]) {
    cout << endl << "|";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " |";
        }
        cout << endl;
        if (i != 2) {
            cout << "-------------\n|";
        }
    }
    cout <<endl;
}

int isGameOver(char board[3][3], char symbol) {
    for (int i = 0; i < 3; i++) {   // row
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return 1;
    }

    for (int i = 0; i < 3; i++) {   // col
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return 1;
    }

    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))  // diag
        return 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return -1;  // Game is a tie
}

void playerMove(char board[3][3]) {
    int row, col;
    cout << "Enter your move (row [0-2] and column [0-2]): ";
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        cout << "Invalid move. Try again.\n";
        playerMove(board);
        return;
    }

    board[row][col] = 'X';
}

int minimax(char board[3][3], int depth, int isMaximizingPlayer) {
    int result = isGameOver(board, 'X');
    if (result != 0) {
        return result * depth;
    }

    result = isGameOver(board, 'O');
    if (result != 0) {
        return result * depth;
    }

    if (isMaximizingPlayer) {
        int bestScore = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, 0);
                    board[i][j] = ' ';
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;

    } else {
        int bestScore = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, 1);
                    board[i][j] = ' ';
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

void compMove(char board[3][3]) {
    int bestScore = INT_MIN;
    int bestRow, bestCol;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax(board, 0, 0);
                board[i][j] = ' ';

                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    board[bestRow][bestCol] = 'O';
}

int main() {
    char board[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    cout << "Tic Tac Toe - Player vs. Computer\n";
    cout << "---------------------------------\n";

    int currentPlayer = 0;

    while (true) {
        display(board);

        if (currentPlayer == 0)
            playerMove(board);
        else
            compMove(board);

        int result = isGameOver(board, currentPlayer == 0 ? 'X' : 'O');
        if (result == 1) {
            display(board);
            if (currentPlayer == 0)
                cout << "Player wins!\n";
            else
                cout << "Computer wins!\n";
            break;
        } else if (result == -1) {
            display(board);
            cout << "It's a tie!\n";
            break;
        }
        currentPlayer = 1 - currentPlayer;
    }
    return 0;
}
