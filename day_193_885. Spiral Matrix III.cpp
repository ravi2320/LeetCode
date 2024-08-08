/*
885. Spiral Matrix III
Solved
Medium
Topics
Companies
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

 

Example 1:


Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
Example 2:


Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 

Constraints:

1 <= rows, cols <= 100
0 <= rStart < rows
0 <= cStart < cols
*/

// Intuition: 
// The problem requires traversing a matrix in a spiral order starting from a given 
// starting point (rStart, cStart). The traversal involves moving in a specific order:
// right (east), down (south), left (west), and up (north). The number of steps 
// taken in each direction increases as we complete full circles around the matrix.

// Time Complexity: O(rows * cols), as every cell in the matrix is visited exactly once.
// Space Complexity: O(rows * cols), which is used to store the result of the spiral order.

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // Define the directions for movement: east, south, west, and north
        vector<vector<int>> directions = {
                                            {0, 1},  // east
                                            {1, 0},  // south
                                            {0, -1}, // west
                                            {-1, 0}  // north
                                         };

        vector<vector<int>> res;  // To store the coordinates in spiral order

        res.push_back({rStart, cStart});  // Start from the initial position
        int steps = 0;  // Number of steps to move in the current direction
        int dir = 0;    // Current direction (0: east, 1: south, 2: west, 3: north)

        // Continue until we visit all the cells in the matrix
        while (res.size() < rows * cols) {
            // Increase the number of steps when moving east or west
            if (dir == 0 || dir == 2) {
                steps++;
            }

            // Move in the current direction for the given number of steps
            for (int cnt = 0; cnt < steps; cnt++) {
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                // Check if the current position is within the matrix bounds
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    res.push_back({rStart, cStart});
                }
            }

            // Update the direction for the next move
            dir = (dir + 1) % 4;
        } 

        return res;
    }
};
