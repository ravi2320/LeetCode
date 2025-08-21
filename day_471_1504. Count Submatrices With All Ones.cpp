/*
1504. Count Submatrices With All Ones

Given an m x n binary matrix mat, return the number of submatrices that have all ones.

 

Example 1:


Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation: 
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
Example 2:


Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
Output: 24
Explanation: 
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
 

Constraints:

1 <= m, n <= 150
mat[i][j] is either 0 or 1.
*/

/*
Approach:
---------
1. The problem is to count the number of submatrices with all 1s.
2. We iterate over all possible start rows (`startRow`) and extend downwards (`endRow`).
3. For each extension, we maintain a 1D vector `vec` representing the "ANDed values" of columns 
   between `startRow` and `endRow`. 
   - If a column remains 1 for all rows in this range, `vec[col]` stays 1, else it becomes 0.
4. For each valid `vec`, we compute how many subarrays consist only of 1s using the helper 
   function `onedArrayCount`.
   - This function uses a running count of consecutive 1s in the array and adds them up.
   - Example: For `[1,1,1]`, it counts subarrays → (1), (1,1), (1,1,1).
5. The total sum across all row pairs gives the answer.

Intuition:
----------
- By fixing start and end rows, we reduce the 2D submatrix problem into a simpler 1D 
  subarray problem.
- `onedArrayCount` efficiently counts subarrays of 1s without explicitly enumerating them.
- Combining these steps lets us count all submatrices with all 1s.

Time Complexity:
----------------
- There are O(m²) possible row pairs (`startRow`, `endRow`).
- For each pair, we scan all n columns → O(n).
- Counting subarrays of 1s is also O(n).
- Total = O(m² * n).

Space Complexity:
-----------------
- We use an auxiliary vector `vec` of size O(n).
- No extra recursive stack or data structure.
- Total = O(n).
*/

class Solution {
public:
    // Helper function to count number of subarrays consisting only of 1s in a 1D array
    int onedArrayCount(vector<int> &arr) {
        int cnt = 0;   // Tracks consecutive 1s
        int ans = 0;   // Stores total subarrays of 1s

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i]) {
                cnt++;        // Increase consecutive 1 count
            } else {
                cnt = 0;      // Reset on encountering 0
            }
            ans += cnt;       // Add count of subarrays ending at current index
        }

        return ans;
    }

    // Main function to count submatrices with all 1s
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();     // Number of rows
        int n = mat[0].size();  // Number of columns
        int ans = 0;            // Final answer

        // Fix starting row
        for (int startRow = 0; startRow < m; startRow++) {
            // Vector to hold column status between startRow and endRow
            vector<int> vec(n, 1);

            // Extend endRow downwards
            for (int endRow = startRow; endRow < m; endRow++) {
                // Update vec: AND column values for current row range
                for (int col = 0; col < n; col++) {
                    vec[col] = vec[col] & mat[endRow][col];
                }

                // Count subarrays of 1s in this "flattened row"
                ans += onedArrayCount(vec);
            }
        }

        return ans;
    }
};
