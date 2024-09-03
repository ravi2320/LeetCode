/*
1901. Find a Peak Element II
Solved
Medium
Topics
Companies
Hint
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:



Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.
*/

/*
**Problem Statement:**
- Given a 2D matrix `mat`, the task is to find a peak element in the matrix and return its position (row, column). A peak element in a 2D grid is defined as an element that is strictly greater than its neighbors.

**Approach:**
1. **Binary Search on Columns:** 
   - We perform a binary search on the columns of the matrix to efficiently find a peak element.
   - For the mid column, find the maximum element in that column.
   - Compare this element with its left and right neighbors (if they exist) to determine if it is a peak.
   - If the element is a peak, return its position.
   - If the left neighbor is greater, search the left half by adjusting the `high` pointer.
   - If the right neighbor is greater, search the right half by adjusting the `low` pointer.

2. **Helper Function:**
   - `findMax` function is used to find the maximum element in a given column and return its row index.

**Time Complexity:**
- The time complexity is `O(n * log(m))`, where `n` is the number of rows and `m` is the number of columns. This is because we are performing a binary search on columns (`log(m)`) and for each column, we are finding the maximum element (`O(n)`).

**Space Complexity:**
- The space complexity is `O(1)` since no extra space is used apart from the input matrix.

**Example Usage:**
- Given the matrix `mat = {{1, 4}, {3, 2}}`, the function will return `[0, 1]` as the position of the peak element.

*/

class Solution {
public:
    // Helper function to find the maximum element in a specific column
    int findMax(vector<vector<int>>& mat, int col) {
        int n = mat.size();
        int maxEle = mat[0][col]; // Initialize max element as the first element in the column
        int row = 0; // Row index of the max element

        // Traverse the column to find the max element
        for(int i = 1; i < n; i++) {
            if(maxEle < mat[i][col]) { // Update if a larger element is found
                row = i;
                maxEle = mat[i][col];
            }
        }

        return row; // Return the row index of the max element
    }

    // Function to find the peak element in the 2D matrix
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat[0].size(); // Number of columns
        int low = 0, high = m - 1;

        // Perform binary search on columns
        while(low <= high) {
            int mid = (low + high) >> 1; // Mid column index
            int row = findMax(mat, mid); // Find the row index of the max element in the mid column

            // Compare the mid element with its left and right neighbors
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1;

            // If the mid element is greater than both its neighbors, return its position
            if(left < mat[row][mid] && mat[row][mid] > right) {
                return {row, mid};
            }
            // If the left neighbor is greater, move to the left half
            else if(mat[row][mid] < left) {
                high = mid - 1;
            }
            // If the right neighbor is greater, move to the right half
            else {
                low = mid + 1;
            }
        }

        return {-1, -1}; // Return {-1, -1} if no peak is found (edge case)
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<vector<int>> mat = {{1, 4}, {3, 2}};
    vector<int> result = sol.findPeakGrid(mat);
    cout << "Peak element found at: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
