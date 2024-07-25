#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {

private:

    vector<vector<char>> board;
    char current_player;

public:

    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        current_player = 'X';
    }

    void print_board() {

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "-----" << endl;
        }
        
    }

    bool is_winner(char player) {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
        }
        // Check columns
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
                return true;
        }
        // Check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player){return true;}
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player){return true;}
        return false;
    }

    bool is_draw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    bool make_move(int row, int col) {

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            return false;
        }

        board[row][col] = current_player;

        if (is_winner(current_player)) {
            print_board();
            cout << "Player " << current_player << " wins!" << endl;
            return true;
        }
        
        if (is_draw()) {
            print_board();
            cout << "The game is a draw!" << endl;
            return true;
        }

        if(current_player == 'X'){current_player = 'O';}
        else{current_player = 'X';}

        return false;
    }

    void start() {
        while (true) {
            print_board();
            int row, col;
            cout << "Player " << current_player << ", enter the row (0, 1, or 2): ";
            cin >> row;
            cout << "Player " << current_player << ", enter the column (0, 1, or 2): ";
            cin >> col;
            if (make_move(row, col)) {
                break;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.start();
    return 0;
}
