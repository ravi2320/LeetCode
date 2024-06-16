/*
54. Spiral Matrix
Solved
Medium
Topics
Companies
Hint
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

/*
Intuition:
- The task is to traverse a given matrix in a spiral order and return the elements in a 1D vector.
- We can achieve this by simulating the movement through the matrix while maintaining boundaries that shrink as we move inward.

Approach:
1. Define boundaries: `top`, `bottom`, `left`, `right`.
2. Traverse from left to right along the `top` boundary, then increment `top`.
3. Traverse from top to bottom along the `right` boundary, then decrement `right`.
4. Traverse from right to left along the `bottom` boundary (if `top` <= `bottom`), then decrement `bottom`.
5. Traverse from bottom to top along the `left` boundary (if `left` <= `right`), then increment `left`.
6. Repeat the process until the boundaries overlap.

Time Complexity:
- O(n * m), where n is the number of rows and m is the number of columns. We visit each element exactly once.

Space Complexity:
- O(1) for extra space (excluding the output vector), as we only use a fixed number of variables.

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        vector<int> ans;
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top boundary
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }
            ++top;

            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            --right;

            // Traverse from right to left along the bottom boundary, if applicable
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                --bottom;
            }

            // Traverse from bottom to top along the left boundary, if applicable
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                ++left;
            }
        }

        return ans;
    }
};
