/*
1277. Count Square Submatrices with All Ones
Solved
Medium
Topics
Companies
Hint
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

/*
Approach:
1. Use dynamic programming to count square submatrices with all 1s in a binary matrix.
2. Traverse each cell `(i, j)` in `matrix`. If `matrix[i][j] == 1`, update it with the size of the largest square submatrix ending at `(i, j)`:
   - `matrix[i][j] = 1 + min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1])`.
   - This formula ensures that each cell holds the size of the square matrix it can extend to, considering diagonal, left, and top cells.
3. Accumulate the updated values in `sum` to get the total count of square submatrices with all 1s.

Time Complexity: O(m * n), where `m` is the number of rows and `n` is the number of columns.
Space Complexity: O(1), as we modify the input matrix in place.

*/

class Solution {
public:
    // Function to count square submatrices with all 1s.
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = 0;

        // Traverse each cell in the matrix.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If matrix[i][j] is 1 and not on the first row or column,
                // calculate the size of the largest square submatrix ending at (i, j).
                if (matrix[i][j] && i >= 1 && j >= 1) {
                    matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
                }
                // Add the value at matrix[i][j] to the sum.
                sum += matrix[i][j];
            }
        }

        return sum;  // Return the total count of square submatrices.
    }
};
