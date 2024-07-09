#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initBoard() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = '1' + 3 * i + j;
    currentPlayer = 'X';
}

void displayBoard() {
    cout << "Current board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

bool isWinner() {
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
    for (int j = 0; j < 3; ++j)
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer)
            return true;
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O')
        board[row][col] = currentPlayer;
    else {
        cout << "Invalid move! Try again.\n";
        makeMove();
    }
}

void playGame() {
    initBoard();
    while (true) {
        displayBoard();
        makeMove();
        if (isWinner()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
        switchPlayer();
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y');
    return 0;
}
