//#include <iostream>
//using namespace std;
//
//const int SIZE = 3;
//const char PLAYER_X = 'X';
//const char PLAYER_O = 'O';
//const char EMPTY = ' ';
//
//void displayBoard(char board[SIZE][SIZE]) {
//    cout << "\nCurrent Board:\n";
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            cout << " " << board[i][j] << " ";
//            if (j < SIZE - 1) {
//                cout << "|";
//            }
//        }
//        cout << endl;
//        if (i < SIZE - 1) {
//            cout << "-----------" << endl;
//        }
//    }
//}
//bool checkWin(char board[SIZE][SIZE], char player) {
//    for (int i = 0; i < SIZE; i++) {
//        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
//            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
//            return true;
//        }
//    }
//    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
//        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
//        return true;
//    }
//    return false;
//}
//bool checkDraw(char board[SIZE][SIZE]) {
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            if (board[i][j] == EMPTY) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//int getValidNumber(const string& prompt) {
//    int value;
//    while (true) {
//        cout << prompt;
//        cin >> value;
//        if (cin.fail() || value < 0 || value >= SIZE) {
//            cout << "Invalid input! Please enter a number between 0 and " << SIZE - 1 << ".\n";
//            cin.clear();
//            cin.ignore();
//        }
//        else {
//            cin.ignore();
//            return value;
//        }
//    }
//}
//void makeMove(char board[SIZE][SIZE], char player) {
//    int row, col;
//    bool validMove = false;
//    while (!validMove) {
//        row = getValidNumber("\nPlayer " + string(1, player) + ", enter row (0-2): ");
//        col = getValidNumber("Player " + string(1, player) + ", enter column (0-2): ");
//        if (board[row][col] == EMPTY) {
//            board[row][col] = player;
//            validMove = true;
//        }
//        else {
//            cout << "That spot is already taken. Try again.\n";
//        }
//    }
//}
//
//int main() {
//    char board[SIZE][SIZE] = { {EMPTY, EMPTY, EMPTY},
//                               {EMPTY, EMPTY, EMPTY},
//                               {EMPTY, EMPTY, EMPTY} };
//    char player = PLAYER_X;
//    bool gameOver = false;
//    cout << "===== TIC TAC TOE GAME =====" << endl;
//    while (!gameOver) {
//        displayBoard(board);
//        makeMove(board, player);
//        if (checkWin(board, player)) {
//            displayBoard(board);
//            cout << "\n Player " << player << " wins! \n";
//            gameOver = true;
//        }
//        else if (checkDraw(board)) {
//            displayBoard(board);
//            cout << "\nIt's a draw! No spaces left.\n";
//            gameOver = true;
//        }
//        else {
//            player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X; 
//        }
//    }
//    cout << "\nGame Over. Thanks for playing!\n";
//    return 0;
//}