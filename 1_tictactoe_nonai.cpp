#include <iostream>
using namespace std;

char p1 = 'X';
char p2 = 'O';

bool check(char board[], char p) {
    // diagonal
    if(    (board[0] == p && board[4] == p && board[8] == p) 
        || (board[2] == p && board[4] == p && board[6] == p) )
        return true;

    // rows
    else if(   (board[0] == p && board[1] == p && board[2] == p) 
            || (board[3] == p && board[4] == p && board[5] == p)  
            || (board[6] == p && board[7] == p && board[8] == p) )
        return true;

    // columns
    else if(   (board[0] == p && board[3] == p && board[6] == p) 
            || (board[1] == p && board[4] == p && board[7] == p)  
            || (board[2] == p && board[5] == p && board[8] == p) )
        return true;
    return false;
}

void display(char board[]){
    for (int i=0; i<9; i++) {
        if (i == 0) cout << "\n|";
        if (i == 3) cout << "\n-------------\n|";
        if (i == 6) cout << "\n-------------\n|";
        cout << " " << board[i] << " |";
    }
}

int main() {
    char board[9];
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
    
    
    for (int i=1; i<10; i++) {
        int place;

        if (i % 2 != 0) {
            label1:
            cout << "\n\nPlayer 1: ";
            cout << "Enter your move: ";
            cin >> place;
            if (board[place] == p1 || board[place] == p2) {
                cout << "\nAlready used :(\n";
                goto label1;
            }
            board[place] = p1;
            display(board);
            if (check(board, p1)) {
                cout << "\n\tPlayer 1 wins!";
                break;
            }
        }
        else {
            label2:
            cout << "\n\nPlayer 2: ";
            cout << "Enter your move: ";
            cin >> place;
            if(board[place] == p1 || board[place] == p2){
                cout << "\nAlready used :(";
                goto label2;
            }
            board[place] = p2;
            display(board);
            if (check(board, p2)) {
                cout << "\n\tPlayer 2 wins!";
                break;
            }
        }
        if (i == 9)
            cout << "\n\t\nGAME DRAW!";
    }
    return 0;
}