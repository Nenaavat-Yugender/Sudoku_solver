#include <iostream>
#include <vector>

using namespace std;

#define N 9 // Size of the Sudoku grid

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
    cout << "\nSudoku Grid:\n";
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0) cout << "-------------------------\n";
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0) cout << "| ";
            if (grid[i][j] == 0) // Empty cells
                cout << ". ";
            else
                cout << grid[i][j] << " ";
            if (j == 8) cout << "|";
        }
        cout << endl;
    }
    cout << "-------------------------\n";
}


// Function to check if a move is valid
bool isValidMove(vector<vector<int>>& grid, int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) return false;
    }

    // Check 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

// Function to check if the Sudoku is completely solved
bool isSolved(vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) return false; // If any cell is empty, return false
        }
    }
    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValidMove(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid)) return true;
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Function to manually enter numbers in Sudoku
void inputSudoku(vector<vector<int>>& grid) {
    int row, col, num;
    while (true) {
        cout << "Enter row (1-9), column (1-9), and number (1-9) (Enter 0 0 0 to finish): ";
        cin >> row >> col >> num;
        if (row == 0 && col == 0 && num == 0) break;

        if (row >= 1 && row <= 9 && col >= 1 && col <= 9 && num >= 1 && num <= 9) {
            if (grid[row - 1][col - 1] == 0 && isValidMove(grid, row - 1, col - 1, num)) {
                grid[row - 1][col - 1] = num;
                printGrid(grid);
            } else {
                cout << "Invalid move! Try again.\n";
            }
        } else {
            cout << "Invalid input! Enter numbers between 1 and 9.\n";
        }
    }
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N, 0));

    int choice;
    cout << "Choose an option:\n";
    cout << "1. Start with an empty grid\n";
    cout << "2. Start with a pre-filled puzzle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 2) {
        grid = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
    }

    printGrid(grid);
    inputSudoku(grid);

    cout << "\nChecking solution...\n";
    if (isSolved(grid)) {
        cout << "Congratulations! You solved the puzzle.\n";
    } else {
        cout << "The Sudoku is not yet fully solved. Do you want me to solve it? (y/n): ";
        char solveChoice;
        cin >> solveChoice;
        if (solveChoice == 'y' || solveChoice == 'Y') {
            if (solveSudoku(grid)) {
                cout << "\nSolved Sudoku:\n";
                printGrid(grid);
            } else {
                cout << "No solution exists for this Sudoku.\n";
            }
        }
    }

    return 0;
}
