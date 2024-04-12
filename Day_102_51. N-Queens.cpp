/*
51. N-Queens
Solved
Hard
Topics
Companies
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9

*/

/*
Intuition:
- The problem is solved using backtracking.
- We use a recursive function `solve` to place queens on the chessboard.
- At each column, we iterate through each row and try to place a queen.
- We check if the current position is valid by ensuring that no other queen threatens it.
- We maintain vectors `leftrow`, `upperDiagonal`, and `lowerDiagonal` to keep track of occupied rows and diagonals.
- If a valid position is found, we recursively explore the next column.
- Once all columns are filled, we add the current configuration of the board to the answer vector.

Time Complexity: O(N!)
- In the worst-case scenario, where all possible configurations of queens are explored, the time complexity is factorial, O(N!).

Space Complexity: O(N^2)
- The space complexity is O(N^2) due to the board configuration and auxiliary vectors.
*/

class Solution {
public:
    // Recursive function to solve the N-Queens problem
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, 
               vector<int>& leftrow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
        
        // Base case: All columns filled, add current board configuration to answer
        if (col == n) {
            ans.push_back(board);
            return;
        }
        
        // Try placing queen in each row of current column
        for (int row = 0; row < n; row++) {
            // Check if position is valid
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                // Place queen and update auxiliary vectors
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                
                // Recur to next column
                solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
                
                // Backtrack: Remove queen and reset auxiliary vectors
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    // Function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize board with empty squares
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); // Initialize auxiliary vectors
        solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n); // Start recursive backtracking
        return ans;
    }
};
