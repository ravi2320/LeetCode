/*
2326. Spiral Matrix IV
Solved
Medium
Topics
Companies
Hint
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

 

Example 1:


Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
Example 2:


Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 

Constraints:

1 <= m, n <= 105
1 <= m * n <= 105
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000
*/

/*
Approach:
1. Initialize an `m x n` matrix filled with -1.
2. Use four boundary pointers (`top`, `bottom`, `left`, `right`) to maintain the current boundary of the matrix and a direction indicator `id`.
3. Traverse the matrix in a spiral order using four directions (left to right, top to bottom, right to left, bottom to top) while filling the matrix with values from the linked list.
4. Stop the traversal when the linked list is exhausted or when all boundaries meet.
5. If the linked list is shorter than the matrix cells, remaining cells stay filled with -1.

Time Complexity:
- O(m * n): We iterate through each cell of the matrix once.

Space Complexity:
- O(m * n): We use an extra matrix of size `m x n` to store the results.

*/

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize a matrix of size m x n with default value -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Define boundaries
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        // Initialize direction id
        int id = 0;

        // Traverse the matrix in spiral order
        while (top <= bottom && left <= right) {

            // Traverse from left to right
            if (id == 0) {
                for (int i = left; head && i <= right; i++) {
                    matrix[top][i] = head->val;  // Fill the matrix with the current node's value
                    head = head->next;           // Move to the next node in the list
                }
                top++;  // Move the top boundary down
                id = (id + 1) % 4;  // Change direction
            }

            // Traverse from top to bottom
            if (id == 1) {
                for (int i = top; head && i <= bottom; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;  // Move the right boundary left
                id = (id + 1) % 4;
            }

            // Traverse from right to left
            if (id == 2) {
                for (int i = right; head && i >= left; i--) {
                    matrix[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;  // Move the bottom boundary up
                id = (id + 1) % 4;
            }

            // Traverse from bottom to top
            if (id == 3) {
                for (int i = bottom; head && i >= top; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;  // Move the left boundary right
                id = (id + 1) % 4;
            }
        }

        // Return the filled spiral matrix
        return matrix;
    }
};
