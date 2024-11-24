/*
1975. Maximum Matrix Sum
Solved
Medium
Topics
Companies
Hint
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 

Example 1:


Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
Example 2:


Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.
 

Constraints:

n == matrix.length == matrix[i].length
2 <= n <= 250
-105 <= matrix[i][j] <= 105
*/

/*
Approach:
1. The task is to maximize the sum of the absolute values of elements in a matrix, with the possibility of changing the sign of any element.
2. Key observations:
   - If the count of negative numbers in the matrix is even, we can make all elements positive to maximize the sum.
   - If the count of negative numbers is odd, one element will have to remain negative to achieve the maximum sum.
   - In this case, the minimum absolute value element should be negative to minimize the reduction in the total sum.
   
Steps:
1. Traverse the matrix and:
   - Keep a cumulative sum of the absolute values of all elements.
   - Count the number of negative elements.
   - Track the minimum absolute value element.
2. If the count of negative elements is even, return the cumulative sum.
3. If odd, subtract twice the smallest absolute value element from the cumulative sum to ensure the maximum possible sum.
   
Time Complexity:
- O(m * n) — since we iterate over each element in the matrix once.

Space Complexity:
- O(1) — only a few additional variables are used, independent of the matrix size.

*/

class Solution {
public:
    // Function to find the maximum sum of the matrix with sign adjustments
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int cnt = 0, mini = INT_MAX;
        int m = matrix.size(), n = matrix[0].size(); 

        // Traverse the matrix to calculate sum of absolute values,
        // count negative numbers, and find the minimum absolute value
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Count negatives
                if(matrix[i][j] < 0) {
                    cnt++;
                }

                // Update the minimum absolute value element
                mini = min(mini, abs(matrix[i][j]));

                // Add the absolute value of the current element to the sum
                sum += abs(matrix[i][j]);
            }
        }

        // If the count of negative numbers is odd, adjust by removing twice the minimum absolute value
        return cnt % 2 ? sum - (2 * mini) : sum;
    }
};
