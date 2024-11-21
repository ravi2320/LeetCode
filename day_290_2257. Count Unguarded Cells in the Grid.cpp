/*
2257. Count Unguarded Cells in the Grid
Solved
Medium
Topics
Companies
Hint
You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.

 

Example 1:


Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
Output: 7
Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
There are a total of 7 unguarded cells, so we return 7.
Example 2:


Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
Output: 4
Explanation: The unguarded cells are shown in green in the above diagram.
There are a total of 4 unguarded cells, so we return 4.
 

Constraints:

1 <= m, n <= 105
2 <= m * n <= 105
1 <= guards.length, walls.length <= 5 * 104
2 <= guards.length + walls.length <= m * n
guards[i].length == walls[j].length == 2
0 <= rowi, rowj < m
0 <= coli, colj < n
All the positions in guards and walls are unique.
*/

/*
Approach:
1. We need to determine the number of unguarded cells in a grid after placing guards and walls. A guard's vision extends in all four directions (up, down, left, right) until blocked by a wall or another guard.
2. The grid is initialized with the following values:
   - `0` for an empty cell.
   - `1` for a cell that is guarded.
   - `2` for a guard.
   - `3` for a wall.
3. First, mark the cells where guards and walls are located.
4. For each guard, update its vision in the four directions. If a guard can see a cell (i.e., it's not blocked), mark it as guarded (`1`).
5. Count the cells that remain as `0` (ungoverned) after processing all guards.

Time Complexity:
- O(m * n) — Each cell is processed a constant number of times based on the guard's vision.

Space Complexity:
- O(m * n) — Additional grid storage to keep track of guarded, guard, and wall positions.

*/

class Solution {
public:
    // Function to mark cells that are guarded by a guard at (row, col)
    void makeGuarded(int row, int col, vector<vector<int>> &grid, int m, int n) {
        // Check upwards direction
        for (int i = row - 1; i >= 0; i--) {
            // Stop if a wall or another guard is encountered
            if (grid[i][col] == 2 || grid[i][col] == 3)
                break;
            // Mark as guarded
            grid[i][col] = 1;
        }

        // Check downwards direction
        for (int i = row + 1; i < m; i++) {
            if (grid[i][col] == 2 || grid[i][col] == 3)
                break;
            grid[i][col] = 1;
        }

        // Check left direction
        for (int j = col - 1; j >= 0; j--) {
            if (grid[row][j] == 2 || grid[row][j] == 3)
                break;
            grid[row][j] = 1;
        }

        // Check right direction
        for (int j = col + 1; j < n; j++) {
            if (grid[row][j] == 2 || grid[row][j] == 3)
                break;
            grid[row][j] = 1;
        }
    }

    // Function to count the number of unguarded cells in the grid
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize the grid with 0 (empty cells)
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Place guards in the grid (mark as 2)
        for (auto &guard : guards) {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 2;
        }

        // Place walls in the grid (mark as 3)
        for (auto &wall : walls) {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 3;
        }

        // For each guard, update the guarded cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    makeGuarded(i, j, grid, m, n);
                }
            }
        }

        // Count the number of unguarded cells
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
