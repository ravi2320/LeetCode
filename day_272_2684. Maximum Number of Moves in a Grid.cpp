/*
2684. Maximum Number of Moves in a Grid
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.

 

Example 1:


Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.
Example 2:


Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
Output: 0
Explanation: Starting from any cell in the first column we cannot perform any moves.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
1 <= grid[i][j] <= 106
*/

/*
Approach:
1. This solution is a depth-first search (DFS) with memoization for an optimal pathfinding problem on a grid.
2. The `solve` function recursively checks all valid paths from each cell at (row, col) in the grid.
3. Recursive Base Case:
   - If `row` or `col` are out of bounds, or if the current cell value is not greater than `prev`, it returns 0 (end of path).
4. Memoization:
   - If the result for a cell is already computed, it returns the cached result in `memo`.
5. Recursive Calls:
   - Checks three possible moves to the right column from the current cell: 
     - Up-right, right, and down-right.
   - Tracks the maximum moves possible in these directions.
6. Finally, the `maxMoves` function initiates the search from each cell in the first column to find the maximum possible path.
   
Time Complexity: O(n * m), where n is the number of rows and m is the number of columns, as each cell is visited only once.
Space Complexity: O(n * m) due to the memoization matrix.

*/

class Solution {
public:
    // Recursive function to find the longest path with increasing values in the grid
    int solve(int row, int col, int prev, vector<vector<int>> &grid, int &m, int &n, vector<vector<int>>& memo) {
        // Base case: out of bounds or value not greater than previous cell
        if (row < 0 || row >= n || col >= m || prev >= grid[row][col])
            return 0;

        // Return cached result if already computed for this cell
        if (memo[row][col] != -1)
            return memo[row][col];

        // Initialize moves count
        int moves = 0;

        // Explore all three possible moves to the next column
        moves = max(moves, 1 + solve(row-1, col+1, grid[row][col], grid, m, n, memo)); // Up-right
        moves = max(moves, 1 + solve(row, col+1, grid[row][col], grid, m, n, memo));   // Right
        moves = max(moves, 1 + solve(row+1, col+1, grid[row][col], grid, m, n, memo)); // Down-right

        // Store result in memoization table and return
        return memo[row][col] = moves;
    }

    // Main function to find the maximum moves possible in the grid
    int maxMoves(vector<vector<int>>& grid) {
        int maxResult = 0, prev = -1;
        int n = grid.size(), m = grid[0].size();

        // Memoization table
        vector<vector<int>> memo(n, vector<int>(m, -1));

        // Start DFS from each row in the first column
        for (int i = 0; i < n; i++) {
            maxResult = max(maxResult, solve(i, 0, prev, grid, m, n, memo));
        }

        // Subtract 1 from result to get moves instead of total cells
        return maxResult - 1;
    }
};
