
#include <iostream>
#include <limits>

using namespace std;

char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

void drawBoard() { //отрисовка игрового поля
    cout << "
";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "
";
    cout << "---|---|---
";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "
";
    cout << "---|---|---
";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "
";
    cout << "
";
}

bool isMovesLeft() { //проверка правмльности хода
    for (int i = 0; i < 9; i++)
        if (board[i] == ' ')
            return true;
    return false;
}

int evaluate() {
    // Rows
    for (int row = 0; row < 9; row += 3)
        if (board[row] == board[row + 1] && board[row + 1] == board[row + 2]) {
            if (board[row] == 'O') return +10;
            if (board[row] == 'X') return -10;
        }

    // Columns
    for (int col = 0; col < 3; col++)
        if (board[col] == board[col + 3] && board[col + 3] == board[col + 6]) {
            if (board[col] == 'O') return +10;
            if (board[col] == 'X') return -10;
        }

    // Diagonals
    if (board[0] == board[4] && board[4] == board[8]) {
        if (board[0] == 'O') return +10;
        if (board[0] == 'X') return -10;
    }
    if (board[2] == board[4] && board[4] == board[6]) {
        if (board[2] == 'O') return +10;
        if (board[2] == 'X') return -10;
    }

    return 0;
}

int minimax(bool isMax) { //функция минимакса
    int score = evaluate();

    if (score == 10 || score == -10)
        return score;

    if (!isMovesLeft())
        return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'O';
                best = max(best, minimax(!isMax));
                board[i] = ' ';
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'X';
                best = min(best, minimax(!isMax));
                board[i] = ' ';
            }
        }
        return best;
    }
}

int findBestMove() { //нахождение лучшего хода
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = 'O';
            int moveVal = minimax(false);
            board[i] = ' ';

            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}

bool isGameOver() { //окончание игры
    int score = evaluate();
    if (score == 10) {
        cout << "Computer wins!
";
        return true;
    } else if (score == -10) {
        cout << "You win!
";
        return true;
    } else if (!isMovesLeft()) {
        cout << "It's a draw!
";
        return true;
    }
    return false;
}

int main() {
    cout << "Tic Tac Toe Game vs AI
";
    drawBoard();

    while (true) {
        int move;
        cout << "Enter your move (0-8): ";
        cin >> move;

        while (cin.fail() || move < 0 || move > 8 || board[move] != ' ') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '
');
            cout << "Invalid input. Try again: ";
            cin >> move;
        }

        board[move] = 'X';
        drawBoard();

        if (isGameOver()) break;

        int aiMove = findBestMove();
        board[aiMove] = 'O';
        cout << "Computer played: " << aiMove << "
";
        drawBoard();

        if (isGameOver()) break;
    }

    return 0;
}
