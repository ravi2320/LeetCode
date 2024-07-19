/*
1380. Lucky Numbers in a Matrix
Solved
Easy
Topics
Companies
Hint
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.
*/

/**
 * Intuition:
 * - A "lucky number" in the matrix is defined as the minimum element in its row and the maximum in its column.
 * - To find such numbers, iterate through each row to find the minimum element and then check if this element is the
 *   maximum in its corresponding column.
 * 
 * Time Complexity:
 * - The time complexity is O(n * m), where n is the number of rows and m is the number of columns. This is because
 *   for each row, we find the minimum element and then check all elements in the corresponding column.
 *
 * Space Complexity:
 * - The space complexity is O(1) for extra space, excluding the space used to store the output.
 * - The output space complexity is O(k), where k is the number of lucky numbers found.
 */

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;  // Vector to store the lucky numbers
        int n = matrix.size();  // Number of rows in the matrix
        int m = matrix[0].size();  // Number of columns in the matrix
        int col = -1;  // Column index of the minimum element in a row

        for(int i = 0; i < n; i++) {
            int mn = INT_MAX;

            // Find the minimum element in the current row
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] < mn) {
                    mn = matrix[i][j];
                    col = j;
                }
            }

            int mx = INT_MIN;

            // Check if the found minimum element is the maximum in its column
            for(int j = 0; j < n; j++) {
                mx = max(mx, matrix[j][col]);
            }

            // If it is both the minimum in the row and maximum in the column, add it to the result
            if(mx == mn) {
                ans.push_back(mn);
            }
        }

        return ans;  // Return the list of lucky numbers
    }
};
