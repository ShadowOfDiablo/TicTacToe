#include <iostream>
#include <cstdlib>
using namespace std;

bool checkWin(char matrix[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player)
            return true;
        if (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player)
            return true;
    }

    // Check diagonals
    if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player)
        return true;
    if (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player)
        return true;

    return false;
}

bool isDraw(char matrix[3][3]) {
    // Check if the matrix is completely filled with 'X' and 'O'
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == '?')
                return false; // There's an empty cell, game is not a draw yet
        }
    }
    return true; // All cells are filled, it's a draw
}

int main() {
    char matrix[3][3];
    cout << "The number of the squares will go like this 1 2 , 3 3, 2 2 and so on" << endl;
    cout << "Use the row and column, for example 2 1 is 2nd row first column" << endl;
    bool Xturn = (rand() % 2 == 0); // Randomly choose who starts
    if (Xturn) {
        cout << "It's X's turn" << endl;
    }
    else {
        cout << "It's O's turn" << endl;
    }

    // Initialize the matrix with '?'
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = '?';
        }
    }

    while (true) {
        int r, c;
        cin >> r >> c;
        r -= 1;
        c -= 1;

        if (r >= 0 && r < 3 && c >= 0 && c < 3 && matrix[r][c] == '?') {
            matrix[r][c] = (Xturn) ? 'X' : 'O';

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << " | " << matrix[i][j];
                }
                cout << " | " << endl;
                cout << " -------------" << endl;
            }

            if (checkWin(matrix, (Xturn) ? 'X' : 'O')) {
                cout << ((Xturn) ? 'X' : 'O') << " wins!" << endl;
                break; // Exit the loop when the game is over
            }
            else if (isDraw(matrix)) {
                cout << "It's a draw!" << endl;
                break; // Exit the loop when the game is over
            }

            Xturn = !Xturn; // Switch turns
        }
        else {
            cout << "Pick a valid position" << endl;
        }
    }

    return 0;
}
