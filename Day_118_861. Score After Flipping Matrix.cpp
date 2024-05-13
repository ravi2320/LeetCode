/*
861. Score After Flipping Matrix
Solved
Medium
Topics
Companies
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

 

Example 1:


Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
Example 2:

Input: grid = [[0]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
grid[i][j] is either 0 or 1.
*/

// Intuition:
// - We can determine the maximum score by analyzing each column of the grid.
// - The leftmost column (column 0) has the highest weight, contributing 2^(n-1) to the score, where n is the number of columns.
// - For each subsequent column (from column 1 to n-1), we count the number of rows with the same value as the first row.
// - We choose the maximum count of 1s or 0s for each column to maximize the score.
// - We update the score by adding the contribution of each column based on the maximum count of 1s or 0s.
// - Finally, we return the maximum score.

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
// - We iterate through each cell of the grid to calculate the score.
// Space Complexity: O(1), constant extra space is used.
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns

        // Initialize the score with the contribution of the leftmost column
        int score = pow(2, n-1) * m;

        // Iterate through each column (from column 1 to n-1)
        for(int j = 1; j < n; j++) {

            int countSameBits = 0; // Count of rows with the same value as the first row in the current column
            for(int i = 0; i < m; i++) {
                if(grid[i][j] == grid[i][0]) {
                    countSameBits++;
                }
            }

            // Count the number of 1s and 0s in the current column
            int countOnes  = countSameBits;
            int countZeros = m - countOnes;

            // Choose the maximum count of 1s or 0s for the current column
            int ones = max(countOnes, countZeros);

            // Update the score by adding the contribution of the current column
            score += (pow(2, n-j-1) * ones);            
        }

        return score; // Return the maximum score
    }
};
