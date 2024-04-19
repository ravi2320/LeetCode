/*
463. Island Perimeter
Solved
Easy
Topics
Companies
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
*/

// Intuition:
// This class provides a solution to calculate the perimeter of an island in a grid.
// It employs Depth-First Search (DFS) to traverse the grid, exploring connected land cells.
// By counting the perimeter of land cells encountered during traversal, it determines the perimeter of the island.

// Time Complexity: O(m * n)
// - 'm' is the number of rows and 'n' is the number of columns in the grid.
// - The DFS algorithm traverses each cell of the grid at most once, resulting in O(m * n) time complexity.

// Space Complexity: O(1) (excluding the input grid)
// - The algorithm utilizes only a constant amount of extra space for variables.
// - However, considering the function call stack space used by recursive DFS, it could be O(m * n) in the worst case.

#include <vector>
using namespace std;

class Solution {
public:
    int m, n;

    // DFS function to explore connected land cells and calculate perimeter
    int dfs(vector<vector<int>>& grid, int i, int j, int &perimeter) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            perimeter++; // Increment perimeter when encountering water or boundary
            return perimeter;
        }

        if (grid[i][j] == -1)
            return perimeter; // Return perimeter if already visited

        grid[i][j] = -1; // Mark current cell as visited

        // Explore adjacent cells
        dfs(grid, i + 1, j, perimeter);
        dfs(grid, i, j + 1, perimeter);
        dfs(grid, i - 1, j, perimeter);
        dfs(grid, i, j - 1, perimeter);

        return perimeter;
    }

    // Main function to calculate island perimeter
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(); // Number of rows
        n = grid[0].size(); // Number of columns
        int perimeter = 0; // Initialize perimeter

        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // If current cell is land
                    dfs(grid, i, j, perimeter); // Explore island and update perimeter
                    break; // Break the loop once an island is found
                }
            }
        }

        return perimeter; // Return total perimeter of the island
    }
};


#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    // Function for performing Breadth-First Search (BFS) to calculate island perimeter
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int peri = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (auto dir : directions) {
                int i_ = p.first + dir[0];
                int j_ = p.second + dir[1];

                if (i_ < 0 || j_ < 0 || i_ >= m || j_ >= n || grid[i_][j_] == 0) {
                    peri++; // Increment perimeter when encountering water or boundary
                } else if (grid[i_][j_] == 1) {
                    if (grid[i_][j_] == -1) continue; // Skip visited cells
                    q.push({i_, j_}); // Add neighboring land cell to the queue
                    grid[i_][j_] = -1; // Mark neighboring land cell as visited
                }
            }
        }
        return peri; // Return perimeter of the island
    }

    // Main function to calculate island perimeter
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(); // Number of rows
        n = grid[0].size(); // Number of columns
        int peri = 0; // Initialize perimeter

        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // If current cell is land
                    peri = bfs(grid, i, j); // Perform BFS to calculate island perimeter
                    break; // Break the loop once an island is found
                }
            }
        }

        return peri; // Return total perimeter of the island
    }
};
