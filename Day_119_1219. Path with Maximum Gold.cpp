/*
1219. Path with Maximum Gold
Solved
Medium
Topics
Companies
Hint
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.
*/

// Intuition:
// - We can use Depth First Search (DFS) to explore each possible path starting from each cell in the grid.
// - At each cell, we explore all possible directions (up, down, left, right) as long as the cell has gold.
// - During the DFS traversal, we keep track of the maximum amount of gold collected from the current path.
// - After exploring all possible paths, we return the maximum amount of gold collected.
// - We restore the original value of the cell after DFS traversal to avoid affecting subsequent DFS calls.

// Time Complexity: O(m * n * 4^k), where m is the number of rows, n is the number of columns, and k is the maximum possible length of a path.
// - In the worst case, each cell in the grid is visited, and at each cell, we explore up to 4 possible directions.
// - The maximum possible length of a path is limited by the number of cells in the grid (m * n).
// Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
// - The space complexity is determined by the recursive call stack during DFS traversal.
#include <vector>
using namespace std;

class Solution {
public:
    int m, n;

    // Depth First Search function to explore paths and collect gold
    int DFS(vector<vector<int>>& grid, int i, int j) {
        // Base case: if the cell is out of bounds or contains no gold, return 0
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;

        int originalGoldValue = grid[i][j]; // Store the original gold value of the current cell
        int maxGold = 0; // Initialize the maximum gold collected from the current path

        // Mark the current cell as visited by setting its value to 0
        grid[i][j] = 0;

        // Explore all possible directions (up, down, left, right)
        maxGold = max(maxGold, DFS(grid, i - 1, j)); // Up
        maxGold = max(maxGold, DFS(grid, i + 1, j)); // Down
        maxGold = max(maxGold, DFS(grid, i, j - 1)); // Left
        maxGold = max(maxGold, DFS(grid, i, j + 1)); // Right
        
        // Restore the original value of the current cell after DFS traversal
        grid[i][j] = originalGoldValue;

        // Return the original gold value of the current cell plus the maximum gold collected from the current path
        return originalGoldValue + maxGold;
    }

    // Function to get the maximum amount of gold collected from the grid
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        m = grid.size(); // Number of rows
        n = grid[0].size(); // Number of columns

        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Explore paths starting from each cell and update the maximum gold collected
                maxGold = max(maxGold, DFS(grid, i, j));
            }
        }

        // Return the maximum amount of gold collected from the grid
        return maxGold;
    }
};
