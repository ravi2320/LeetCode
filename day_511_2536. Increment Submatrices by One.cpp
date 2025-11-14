/*
2536. Increment Submatrices by One

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.

You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:

Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all row1i <= x <= row2i and col1i <= y <= col2i.
Return the matrix mat after performing every query.

 

Example 1:


Input: n = 3, queries = [[1,1,2,2],[0,0,1,1]]
Output: [[1,1,0],[1,2,1],[0,1,1]]
Explanation: The diagram above shows the initial matrix, the matrix after the first query, and the matrix after the second query.
- In the first query, we add 1 to every element in the submatrix with the top left corner (1, 1) and bottom right corner (2, 2).
- In the second query, we add 1 to every element in the submatrix with the top left corner (0, 0) and bottom right corner (1, 1).
Example 2:


Input: n = 2, queries = [[0,0,1,1]]
Output: [[1,1],[1,1]]
Explanation: The diagram above shows the initial matrix and the matrix after the first query.
- In the first query we add 1 to every element in the matrix.
 

Constraints:

1 <= n <= 500
1 <= queries.length <= 104
0 <= row1i <= row2i < n
0 <= col1i <= col2i < n
*/

// Intuition:
// The problem is asking to perform range updates on a matrix multiple times. Instead of directly updating 
// the matrix for each query, we can use a more efficient approach called the "difference array" technique 
// for 2D ranges. The key idea is to mark the start and end points of the updates, and later process the 
// matrix to compute the final values using a prefix sum approach.
// This method reduces the complexity of repeated updates on subarrays.

//
// Approach:
// 1. We initialize a matrix `mat` of size n x n with all values set to 0.
// 2. For each query, instead of updating every cell in the range [r1, c1] to [r2, c2], we increment 
//    the cell `mat[i][c1]` by 1 for each row in the range [r1, r2] (marking the start of the update).
//    Then, we decrement `mat[i][c2 + 1]` by 1 (if within bounds) to mark the end of the update for the 
//    row at column `c2 + 1`.
// 3. After all queries are processed, we compute the prefix sum row by row to get the final matrix where 
//    each cell reflects the total sum from all previous updates.

//
// Time Complexity:
// - For each query, we are iterating through rows from `r1` to `r2`, and updating at most 2 values in each row. 
//   Hence, the time complexity for each query is O(r2 - r1 + 1). In the worst case, this could take O(n) for each query.
// - After processing all queries, we perform a row-wise prefix sum which takes O(n^2) time.
// Therefore, the overall time complexity is O(n^2 + q * n), where `q` is the number of queries.
//
// Space Complexity:
// - We use an n x n matrix, so the space complexity is O(n^2).

class Solution {
public:
    // Function to process range add queries
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // Initialize a n x n matrix with all values set to 0
        vector<vector<int>> mat(n, vector<int>(n, 0));

        // Iterate through each query
        for(auto &query : queries){
            // Extract the corners of the sub-matrix to update
            int r1 = query[0], c1 = query[1];
            int r2 = query[2], c2 = query[3];

            // Apply the difference array technique row by row
            for(int i = r1; i <= r2; i++) {
                // Increment the starting column of the row to mark the beginning of the update
                mat[i][c1] += 1;

                // If within bounds, decrement the column after the ending column to mark the end of the update
                if (c2 + 1 < n) {
                    mat[i][c2 + 1] -= 1;
                }
            }
        }

        // Now, we need to compute the prefix sum row by row to get the final values in the matrix
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                // Add the previous column's value to the current column to compute the cumulative sum
                mat[i][j] += mat[i][j - 1];
            }
        }

        // Return the updated matrix
        return mat;
    }
};
