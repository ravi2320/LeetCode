/*
37. Sudoku Solver
Solved
Hard
Topics
Companies
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/

/*
Approach:
- This is a backtracking approach to solve the Sudoku puzzle.
- The function `solve()` attempts to place numbers in empty cells ('.') and recursively tries to solve the board.
- The `isValid()` function checks if placing a specific number 'c' in a particular cell is valid according to Sudoku rules:
  - The number must not already exist in the current row, column, or 3x3 subgrid.
- If a valid number can be placed, it continues solving. If no number fits, it backtracks (sets the cell back to empty '.') and tries the next possibility.

Time Complexity: O(9^(n^2)) where n is the size of the board (for a 9x9 board, n=9). In the worst case, we might have to try all possible values for each empty cell.
Space Complexity: O(n^2), due to the recursion stack and the board itself.
*/

class Solution {
public:
    // Function to solve the Sudoku board using backtracking
    bool solve(vector<vector<char>>& board){
        int n = board.size();  // number of rows (9)
        int m = board[0].size();  // number of columns (9)

        // Traverse each cell in the board
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                // If the cell is empty ('.')
                if(board[i][j] == '.'){
                    
                    // Try placing numbers '1' to '9'
                    for(char c = '1'; c <= '9'; c++){

                        // Check if placing 'c' is valid
                        if(isValid(i, j, c, board)){

                            board[i][j] = c;  // Place 'c' in the cell

                            // Recursively try solving the board
                            if(solve(board))
                                return true;  // Found a solution
                            else
                                board[i][j] = '.';  // Backtrack if no solution
                        }
                    }

                    return false;  // If no valid number can be placed, backtrack
                }
            }
        }

        return true;  // Return true if the entire board is solved
    }

    // Function to check if placing 'c' at board[row][col] is valid
    bool isValid(int row, int col, char &c, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){

            // Check if 'c' is already in the same column
            if(board[i][col] == c)
                return false;

            // Check if 'c' is already in the same row
            if(board[row][i] == c)
                return false;

            // Check if 'c' is already in the 3x3 subgrid
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }

        return true;  // Return true if it's valid to place 'c' here
    }

    // Function to initiate solving the Sudoku board
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);  // Call the backtracking function
    }
};
