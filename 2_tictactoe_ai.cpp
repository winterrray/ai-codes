#include <iostream>
#include <limits>

using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char player = 'X', ai = 'O';

void display() {
    for (int i=0; i<9; i++) {
        if (i==0) cout << "\n|";
        if (i==3 || i==6) cout << "\n-------------\n|";
        cout << " " << board[i] << " |";
    }
}

bool isBoardFull() {
    for (char c : board) {
        if (c == ' ') {
            return false;
        }
    }
    return true;
}

bool hasWon(char currentPlayer) {
    return (board[0] == currentPlayer && board[1] == currentPlayer && board[2] == currentPlayer) ||     // row
           (board[3] == currentPlayer && board[4] == currentPlayer && board[5] == currentPlayer) ||     // row
           (board[6] == currentPlayer && board[7] == currentPlayer && board[8] == currentPlayer) ||     // row
           (board[0] == currentPlayer && board[3] == currentPlayer && board[6] == currentPlayer) ||     // col
           (board[1] == currentPlayer && board[4] == currentPlayer && board[7] == currentPlayer) ||     // col
           (board[2] == currentPlayer && board[5] == currentPlayer && board[8] == currentPlayer) ||     // col
           (board[0] == currentPlayer && board[4] == currentPlayer && board[8] == currentPlayer) ||     // diag
           (board[2] == currentPlayer && board[4] == currentPlayer && board[6] == currentPlayer);       // diag
}

bool isGameOver() {
    cout << endl << endl;
    if (hasWon(player)) {
        cout << "Player wins!" << endl;
        return true;
    }
    if (hasWon(ai)) {
        cout << "AI wins!" << endl;
        return true;
    }
    if (isBoardFull()) {
        cout << "It's a tie!" << endl;
        return true;
    }
    return false;
}

int minimax(bool isMaximizing) {
    if (hasWon(ai)) return 1;
    if (hasWon(player)) return -1;
    if (isBoardFull()) return 0;

    int bestScore = isMaximizing ? INT_MIN : INT_MAX;

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = isMaximizing ? ai : player;
            int score = minimax(!isMaximizing);
            board[i] = ' ';
            bestScore = isMaximizing ? max(score, bestScore) : min(score, bestScore);
        }
    }
    return bestScore;
}

void aiMove() {
    int bestScore = INT_MIN;
    int move = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = ai;
            int score = minimax(false);
            board[i] = ' ';
            if (score > bestScore) {
                bestScore = score;
                move = i;
            }
        }
    }
    board[move] = ai;
    cout << "\n\nAI chose position " << (move + 1) << endl;
    display();
}

void playerMove() {
    int move;
    while (true) {
        cout << "\nEnter your move (1-9): ";
        cin >> move;
        move -= 1;
        if (move >= 0 && move < 9 && board[move] == ' ') {
            board[move] = player;
            break;
        }
        cout << "Invalid move, try again." << endl;
    }
    display();
}

int main() {
    cout << "\nTic Tac Toe - Player vs. Computer\n";
    cout << "---------------------------------\n";

    display();

    while (true) {
        // aiMove();
        // if (isGameOver()) break;

        // playerMove();
        // if (isGameOver()) break;

        playerMove();
        if (isGameOver()) break;

        aiMove();
        if (isGameOver()) break;
    }

    return 0;
}
