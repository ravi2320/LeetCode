/*
1605. Find Valid Matrix Given Row and Column Sums
Solved
Medium
Topics
Companies
Hint
You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.

 

Example 1:

Input: rowSum = [3,8], colSum = [4,7]
Output: [[3,0],
         [1,7]]
Explanation: 
0th row: 3 + 0 = 3 == rowSum[0]
1st row: 1 + 7 = 8 == rowSum[1]
0th column: 3 + 1 = 4 == colSum[0]
1st column: 0 + 7 = 7 == colSum[1]
The row and column sums match, and all matrix elements are non-negative.
Another possible matrix is: [[1,2],
                             [3,5]]
Example 2:

Input: rowSum = [5,7,10], colSum = [8,6,8]
Output: [[0,5,0],
         [6,1,0],
         [2,0,8]]
 

Constraints:

1 <= rowSum.length, colSum.length <= 500
0 <= rowSum[i], colSum[i] <= 108
sum(rowSum) == sum(colSum)
*/

/**
 * Intuition:
 * - To restore the matrix from row sums and column sums, we start by filling the matrix greedily.
 * - At each step, we take the minimum of the current row sum and column sum, and assign this value to the current cell.
 * - We then update the row sum and column sum by subtracting the value assigned to the cell.
 * - We move to the next row or column depending on which sum reaches zero first.
 * 
 * Time Complexity:
 * - O(n * m), where n is the number of rows and m is the number of columns. This is because we visit each cell exactly once.
 * 
 * Space Complexity:
 * - O(n * m) for storing the resulting matrix.
 */

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(); // Number of rows
        int m = colSum.size(); // Number of columns
        
        // Initialize the result matrix with zeros
        vector<vector<int>> matrix(n, vector<int>(m, 0));

        int i = 0; // Pointer for row
        int j = 0; // Pointer for column

        // Iterate until either row or column pointer exceeds their limits
        while (i < n && j < m) {
            // Fill the current cell with the minimum of the current row sum or column sum
            matrix[i][j] = min(rowSum[i], colSum[j]);

            // Subtract the assigned value from both row and column sums
            rowSum[i] -= matrix[i][j];
            colSum[j] -= matrix[i][j];

            // Move to the next row if the current row sum is zero
            if (rowSum[i] == 0) i++;
            // Move to the next column if the current column sum is zero
            if (colSum[j] == 0) j++;
        }

        return matrix; // Return the constructed matrix
    }
};
