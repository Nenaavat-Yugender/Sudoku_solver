# Sudoku Solver

## Description
A C++ program that allows users to solve Sudoku puzzles using a backtracking algorithm. Users can either input their own Sudoku puzzles or start with a pre-filled grid and let the solver complete it.

## Features
- Allows manual input of Sudoku puzzles.
- Provides a pre-filled Sudoku grid option.
- Validates user input to ensure the puzzle remains solvable.
- Implements a backtracking algorithm to solve Sudoku puzzles.
- Displays the Sudoku grid in a structured format.

## How to Use
1. Compile the C++ program using a compiler like `g++`.
2. Run the program and choose an option:
   - **Option 1:** Start with an empty grid and input numbers manually.
   - **Option 2:** Use a pre-filled Sudoku puzzle and let the solver complete it.
3. If starting with an empty grid, input numbers in the format: `row column number` (e.g., `1 1 5`).
4. Once satisfied with the input, the program checks if the puzzle is solved.
5. If the puzzle is incomplete, the program offers to solve it automatically.

## Input Formats

### Option 1: Empty Grid
```
-------------------------
| . . . | . . . | . . . |
| . . . | . . . | . . . |
| . . . | . . . | . . . |
-------------------------
| . . . | . . . | . . . |
| . . . | . . . | . . . |
| . . . | . . . | . . . |
-------------------------
| . . . | . . . | . . . |
| . . . | . . . | . . . |
| . . . | . . . | . . . |
-------------------------
```

### Option 2: Pre-Filled Grid
```
-------------------------
| 5 3 . | . 7 . | . . . |
| 6 . . | 1 9 5 | . . . |
| . 9 8 | . . . | . 6 . |
-------------------------
| 8 . . | . 6 . | . . 3 |
| 4 . . | 8 . 3 | . . 1 |
| 7 . . | . 2 . | . . 6 |
-------------------------
| . 6 . | . . . | 2 8 . |
| . . . | 4 1 9 | . . 5 |
| . . . | . 8 . | . 7 9 |
-------------------------
```

## Compilation and Execution
```
g++ sudoku_solver.cpp -o main.exe
./main.exe
```

## Dependencies
- C++ Compiler (GCC, Clang, etc.)

## Author
Nenaavath Yugender 
IIT Madras
