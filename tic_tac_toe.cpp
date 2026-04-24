#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(const vector<string>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to check for a win
bool checkWin(const vector<string>& board, char player) {
    // Check rows, columns, and diagonals
    return ((board[0] == board[1] && board[1] == board[2] && board[0] == string(1, player)) ||
            (board[3] == board[4] && board[4] == board[5] && board[3] == string(1, player)) ||
            (board[6] == board[7] && board[7] == board[8] && board[6] == string(1, player)) ||
            (board[0] == board[3] && board[3] == board[6] && board[0] == string(1, player)) ||
            (board[1] == board[4] && board[4] == board[7] && board[1] == string(1, player)) ||
            (board[2] == board[5] && board[5] == board[8] && board[2] == string(1, player)) ||
            (board[0] == board[4] && board[4] == board[8] && board[0] == string(1, player)) ||
            (board[2] == board[4] && board[4] == board[6] && board[2] == string(1, player)));
}

// Function to check if the board is full
bool checkTie(const vector<string>& board) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] != "X" && board[i] != "O") {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> board = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int player = 1;
    int choice;
    char mark;

    do {
        // Draw the board
        drawBoard(board);

        // Determine current player's mark
        if (player % 2 == 1) {
            mark = 'X';
        } else {
            mark = 'O';
        }

        // Get player's choice
        cout << "Player " << mark << ", enter a number (1-9): ";
        cin >> choice;

        // Update the board
        if (board[choice - 1] != "X" && board[choice - 1] != "O") {
            board[choice - 1] = mark;
            player++;
        } else {
            cout << "Invalid move. Please try again." << endl;
        }

        // Check for a win or tie
        if (checkWin(board, mark)) {
            drawBoard(board);
            cout << "Player " << mark << " wins!" << endl;
            break;
        } else if (checkTie(board)) {
            drawBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

    } while (true);

    return 0;
}
