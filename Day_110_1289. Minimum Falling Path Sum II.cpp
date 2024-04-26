/*
1289. Minimum Falling Path Sum II
Solved
Hard
Topics
Companies
Hint
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

 

Example 1:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
Example 2:

Input: grid = [[7]]
Output: 7
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
-99 <= grid[i][j] <= 99
*/

// Intuition:
// This class provides a solution to find the minimum falling path sum in the given grid.
// The algorithm uses dynamic programming to efficiently compute the minimum falling path sum
// starting from each cell in the first row and recursively exploring the minimum path sum
// in subsequent rows.

// Time Complexity: O(n^2)
// - 'n' is the size of the input grid.
// - The algorithm iterates through each cell of the grid once and performs constant-time operations
//   to compute the minimum falling path sum.

// Space Complexity: O(n^2)
// - The algorithm uses an additional 2D dynamic programming array of size 201x201 to store intermediate results.

#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    int n;

    // Recursive function to compute the minimum falling path sum
    int solve(int col, int row, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Base case: reached the last row
        if (row == n - 1)
            return grid[row][col];

        // If the result is already computed, return it
        if (dp[row][col] != -1)
            return dp[row][col];

        int res = INT_MAX;
        // Iterate through all columns in the next row
        for (int i = 0; i < n; i++) {
            // Avoid choosing the same column as the current one
            if (i != col) {
                // Compute the minimum falling path sum recursively
                res = min(res, solve(i, row + 1, grid, dp));
            }
        }

        // Store the result in the DP table and return
        return dp[row][col] = res + grid[row][col];
    }

    // Function to find the minimum falling path sum
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        // Initialize the DP table with -1
        vector<vector<int>> dp(201, vector<int>(201, -1));

        int ans = INT_MAX;
        // Iterate through each column in the first row
        for (int col = 0; col < n; col++) {
            // Find the minimum falling path sum starting from each cell in the first row
            ans = min(ans, solve(col, 0, grid, dp));
        }

        // Return the minimum falling path sum
        return ans;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    vector<vector<int>> grid = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    cout << "Minimum falling path sum: " << obj.minFallingPathSum(grid) << endl; // Output: 13
    return 0;
}


// Intuition:
// This class provides a solution to find the minimum falling path sum in the given grid.
// The algorithm uses dynamic programming to efficiently compute the minimum falling path sum
// starting from each cell in the last row and iteratively updating the minimum path sum
// for each cell in the grid.

// Time Complexity: O(n^2)
// - 'n' is the size of the input grid.
// - The algorithm iterates through each cell of the grid once and performs constant-time operations
//   to compute the minimum falling path sum.

// Space Complexity: O(n^2)
// - The algorithm uses an additional 2D dynamic programming array of size 'n x n' to store intermediate results.

#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    int n;

    // Recursive function to compute the minimum falling path sum
    int solve(int col, int row, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Base case: reached the last row
        if (row == n - 1)
            return grid[row][col];

        // If the result is already computed, return it
        if (dp[row][col] != INT_MAX)
            return dp[row][col];

        int res = INT_MAX;
        // Iterate through all columns in the next row
        for (int i = 0; i < n; i++) {
            // Avoid choosing the same column as the current one
            if (i != col) {
                // Compute the minimum falling path sum recursively
                res = min(res, solve(i, row + 1, grid, dp));
            }
        }

        // Store the result in the DP table and return
        return dp[row][col] = res + grid[row][col];
    }

    // Function to find the minimum falling path sum
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        // Initialize the DP table with INT_MAX
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // Base case: initialize the last row of the DP table
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = grid[n - 1][i];
        }

        // Iterate through each row from bottom to top
        for (int row = n - 2; row >= 0; row--) {
            // Iterate through each column
            for (int col = 0; col < n; col++) {
                // Initialize the minimum falling path sum for the current cell
                int ans = INT_MAX;
                // Iterate through all columns in the next row
                for (int newCol = 0; newCol < n; newCol++) {
                    // Avoid choosing the same column as the current one
                    if (newCol != col) {
                        ans = min(ans, dp[row + 1][newCol]);
                    }
                }
                // Update the DP table with the minimum falling path sum for the current cell
                dp[row][col] = grid[row][col] + ans;
            }
        }

        // Find the minimum falling path sum in the first row of the DP table
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, dp[0][i]);
        }

        // Return the minimum falling path sum
        return res;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    vector<vector<int>> grid = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    cout << "Minimum falling path sum: " << obj.minFallingPathSum(grid) << endl; // Output: 13
    return 0;
}
