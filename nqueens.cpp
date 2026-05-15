#include<iostream>
#include<vector>
using namespace std;

class NQueens {
private:
    int n;
    vector<vector<int>> board;

public:
    NQueens(int size) {
        n = size;
        board.assign(n, vector<int>(n, 0));
    }

    // Check if safe
    bool isSafe(int row, int col) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1)
                return false;
        }

        // Check left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1)
                return false;
        }

        // Check right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    // Backtracking function
    bool solve(int row) {
        if (row == n)
            return true;

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {

                board[row][col] = 1; // place queen

                if (solve(row + 1))
                    return true;

                board[row][col] = 0; // backtrack
            }
        }
        return false;
    }

    // Display board
    void display() {
        cout << "\nChessboard Solution (1 = Queen):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void solveNQueens() {
        if (solve(0)) {
            display();
        } else {
            cout << "\nNo solution exists!\n";
        }
    }
};

// ================= MAIN =================
int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    NQueens solver(n);

    int choice;

    do {
        cout << "\n===== N-QUEENS MENU =====\n";
        cout << "1. Solve N-Queens\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                solver.solveNQueens();
                break;

            case 2:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 2);

    return 0;
}