/*
1072. Flip Columns For Maximum Number of Equal Rows
Solved
Medium
Topics
Companies
Hint
You are given an m x n binary matrix matrix.

You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

Return the maximum number of rows that have all values equal after some number of flips.

 

Example 1:

Input: matrix = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.
Example 2:

Input: matrix = [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.
Example 3:

Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is either 0 or 1.
*/

/*
Approach:
1. Given a matrix of binary values, we want to determine the maximum number of rows that can be made identical after flipping some columns.
2. Two rows are considered identical if, by flipping columns, they can become equal. This means that for any given row:
   - We can either flip columns to match the original row.
   - Or flip columns to match the inverted (complemented) version of the row.
3. To solve this, iterate through each row:
   - Compute its inverted form (flip 0 to 1 and vice versa).
   - Count how many rows match either the original or its inverted form.
   - Keep track of the maximum count of such matching rows.

Time Complexity:
- O(m * n) — where `m` is the number of rows and `n` is the number of columns. For each row, we compare it with all other rows.

Space Complexity:
- O(n) — for storing the inverted row for comparison.

*/

class Solution {
public:
    // Function to find the maximum number of identical rows after flipping columns
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();         // Number of rows
        int n = matrix[0].size();      // Number of columns
        int res = 0;                   // To keep track of the maximum identical rows

        // Iterate over each row in the matrix
        for (vector<int> &currRow : matrix) {
            // Inverted version of the current row
            vector<int> Inverted(n);
            int cnt = 0;  // Counter to track identical rows

            // Compute the inverted form of the current row
            for (int i = 0; i < n; i++) {
                Inverted[i] = currRow[i] == 0 ? 1 : 0;
            }

            // Count rows that are identical to either the current row or its inverted form
            for (vector<int> &row : matrix) {
                if (row == currRow || row == Inverted)
                    cnt++;
            }

            // Update the result with the maximum count found
            res = max(res, cnt);
        }

        return res;  // Return the maximum identical rows found
    }
};


/*
Approach:
1. The goal is to maximize the number of rows that can become identical after flipping columns.
2. The key observation is that a row and its complement (where 0s are flipped to 1s and vice versa) should be treated as identical.
3. To implement this:
   - Iterate through each row and create a unique "pattern" for it based on its first element.
     - If an element matches the first element, mark it with an "S" (Same).
     - If an element is the opposite of the first element, mark it with a "B" (Bit-flip).
   - Use a hashmap to count the occurrences of each pattern.
   - The maximum count of any pattern represents the maximum number of rows that can be made identical.
4. Return the maximum count from the hashmap.

Time Complexity:
- O(m * n) — where `m` is the number of rows and `n` is the number of columns.
  We iterate through each element in the matrix to build the patterns.

Space Complexity:
- O(m * n) — for storing the patterns in the hashmap.

*/

class Solution {
public:
    // Function to find the maximum number of identical rows after flipping columns
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();  // Dimensions of the matrix
        int res = 0;  // Variable to store the result (maximum identical rows)
        
        unordered_map<string, int> mp;  // Hashmap to count pattern frequencies

        // Iterate through each row in the matrix
        for (vector<int> &currRow : matrix) {
            string currRowNature = "";  // String pattern to represent the current row's nature
            int firstChar = currRow[0]; // Store the first element of the current row

            // Build the pattern based on the first element of the row
            for (int col = 0; col < n; col++) {
                // Mark 'S' if the element is the same as the first element, otherwise 'B'
                currRowNature += (firstChar == currRow[col]) ? "S" : "B";
            }

            mp[currRowNature]++;  // Increment the count of the current pattern

            // Update the maximum result with the highest pattern count
            res = max(res, mp[currRowNature]);
        }

        return res;  // Return the maximum count of identical rows
    }
};
