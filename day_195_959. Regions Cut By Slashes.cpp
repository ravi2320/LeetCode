/*
959. Regions Cut By Slashes
Solved
Medium
Topics
Companies
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:


Input: grid = [" /","/ "]
Output: 2
Example 2:


Input: grid = [" /","  "]
Output: 1
Example 3:


Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.
*/

// Intuition:
// The problem involves counting the number of distinct regions formed by slashes ('/' and '\\') in a grid.
// To solve this, we can expand each cell of the grid into a 3x3 matrix. This way, we can accurately represent
// slashes as barriers within the grid. After transforming the grid, we count the number of connected components
// in the resulting matrix using Depth-First Search (DFS). Each connected component represents a distinct region.

// Time Complexity: O(N^2) where N is the total number of cells in the original grid. 
// This is because we convert the grid into a 3N x 3N matrix and perform DFS on it.
// Space Complexity: O(N^2) for the 3N x 3N matrix, where N is the length of the grid.

class Solution {
public:
    // Helper function to perform DFS and mark connected regions
    void numberOfIslandDFS(vector<vector<int>> &matrix, int i, int j) {
        // Check for out of bounds or if the cell is already marked (part of a slash or visited region)
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1) {
            return;
        }

        // Mark the cell as visited
        matrix[i][j] = 1;

        // Explore the neighboring cells
        numberOfIslandDFS(matrix, i, j+1); // Right
        numberOfIslandDFS(matrix, i, j-1); // Left
        numberOfIslandDFS(matrix, i-1, j); // Up
        numberOfIslandDFS(matrix, i+1, j); // Down
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int regions = 0;

        // Initialize a 3N x 3N matrix to represent the expanded grid
        vector<vector<int>> matrix(rows * 3, vector<int>(cols * 3, 0));

        // Fill the matrix using the mapping of '/' and '\\'
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '/') {
                    matrix[3*i][3*j+2] = 1;
                    matrix[3*i+1][3*j+1] = 1;
                    matrix[3*i+2][3*j] = 1;
                }
                else if(grid[i][j] == '\\') {
                    matrix[3*i][3*j] = 1;
                    matrix[3*i+1][3*j+1] = 1;
                    matrix[3*i+2][3*j+2] = 1;
                }
            }
        }

        // Traverse the matrix and count the number of distinct regions
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {  // Unvisited cell
                    numberOfIslandDFS(matrix, i, j);  // Perform DFS
                    regions++;  // Increment the region count
                }
            }
        }

        return regions;
    }
};
