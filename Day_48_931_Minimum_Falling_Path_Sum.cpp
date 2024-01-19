/*
931. Minimum Falling Path Sum
Solved
Medium
Topics
Companies
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> prev(matrix[0].begin(), matrix[0].end());

        for (int i = 1; i < rows; i++) {
            vector<int> curr(cols, -1);
            for (int j = 0; j < cols; j++) {
                int left = j - 1 < 0 ? 1e9 : prev[j - 1] + matrix[i][j];
                int right = j + 1 >= cols ? 1e9 : prev[j + 1] + matrix[i][j];
                int up = prev[j] + matrix[i][j];
                curr[j] = min(left, min(right, up));
            }
            prev = curr;
        }

        int minSum = 1e9;
        for (int j = 0; j < cols; j++)
            minSum = min(minSum, prev[j]);

        return minSum;
    }
};