/*
1568. Minimum Number of Days to Disconnect Island
Solved
Hard
Topics
Companies
Hint
You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

 

Example 1:


Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:


Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.
*/

// Intuition:
// The problem asks us to determine the minimum number of days required to disconnect an island 
// (i.e., make the number of islands either 0 or greater than 1) in a grid where '1' represents land 
// and '0' represents water. The approach involves the following steps:
// 1. Check the initial number of islands using a DFS. If the island count is already not 1, return 0.
// 2. For each land cell, temporarily change it to water and check the number of islands again.
//    If the island count changes to 0 or more than 1, return 1, as removing that cell disconnects the island.
// 3. If no single cell removal can disconnect the island, return 2, which is the worst case.

// Time Complexity: O(N * M * (N * M)) where N is the number of rows and M is the number of columns in the grid.
// This is because for each land cell (N * M cells), we check the number of islands, which itself takes O(N * M) time.
// Space Complexity: O(N * M) for the visited matrix used in DFS.

class Solution {
    int m, n;
public:
    // DFS to explore the entire connected component (island) and mark it as visited
    void DFS(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j) {
        // Boundary check and base case for recursion
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0) {
            return;
        }

        vis[i][j] = 1; // Mark the current cell as visited

        // Explore the neighboring cells
        DFS(grid, vis, i, j+1); // Right
        DFS(grid, vis, i, j-1); // Left
        DFS(grid, vis, i-1, j); // Up
        DFS(grid, vis, i+1, j); // Down
    }

    // Helper function to count the number of islands in the grid
    int numberOfIslandsUtil(vector<vector<int>> &grid) {
        int island = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0)); // Visited matrix

        // Iterate through each cell in the grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // If the cell is part of an island and hasn't been visited
                if(grid[i][j] == 1 && !vis[i][j]) {
                    DFS(grid, vis, i, j); // Perform DFS to mark the entire island
                    island++; // Increment the island count
                }
            }
        }

        return island;
    }

    // Main function to determine the minimum number of days required to disconnect the island
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size(); // Initialize dimensions

        // Step 1: Count the initial number of islands
        int island = numberOfIslandsUtil(grid);

        // If the grid is already disconnected or empty, return 0
        if(island == 0 || island > 1) {
            return 0;
        }

        // Step 2: Try removing each land cell to check if it disconnects the island
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0; // Temporarily remove the land cell

                    island = numberOfIslandsUtil(grid); // Recount the number of islands

                    // If the island count is 0 or greater than 1, return 1
                    if(island > 1 || island == 0) {
                        return 1;
                    }

                    grid[i][j] = 1; // Restore the land cell
                }
            }
        }

        // If no single cell removal works, return 2 as the worst-case scenario
        return 2;
    }
};
