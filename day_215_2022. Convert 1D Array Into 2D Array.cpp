/*
2022. Convert 1D Array Into 2D Array
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using all the elements from original.

The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

 

Example 1:


Input: original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]
Explanation: The constructed 2D array should contain 2 rows and 2 columns.
The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.
Example 2:

Input: original = [1,2,3], m = 1, n = 3
Output: [[1,2,3]]
Explanation: The constructed 2D array should contain 1 row and 3 columns.
Put all three elements in original into the first row of the constructed 2D array.
Example 3:

Input: original = [1,2], m = 1, n = 1
Output: []
Explanation: There are 2 elements in original.
It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D array.
 

Constraints:

1 <= original.length <= 5 * 104
1 <= original[i] <= 105
1 <= m, n <= 4 * 104
*/


/*
**Problem Statement:**
- You are given a 1D array `original` and two integers `m` and `n`, representing the number of rows and columns of a 2D array, respectively.
- Your task is to convert the `original` 1D array into a 2D array with `m` rows and `n` columns.

**Approach:**
1. **Size Check:**
   - First, check if the size of the `original` array is equal to `m * n`. If it is not, return an empty 2D array, as it is impossible to reshape the array.

2. **Reshape Logic:**
   - Create a 2D array `ans` of size `m x n` and initialize all elements to 0.
   - Traverse the `original` array and place each element in the corresponding position in the `ans` 2D array. 
   - The element at position `original[i]` in the 1D array should be placed at position `[i/n][i%n]` in the 2D array.

**Time Complexity:**
- The time complexity is `O(m * n)`, where `m` is the number of rows and `n` is the number of columns, as we are iterating over each element of the `original` array.

**Space Complexity:**
- The space complexity is `O(m * n)`, required for storing the resultant 2D array.

**Example Usage:**
- Given `original = {1, 2, 3, 4}` with `m = 2` and `n = 2`, the function will return the 2D array `{{1, 2}, {3, 4}}`.
*/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        
        // If the size of the original array is not equal to m * n, return an empty array
        if(size != m * n) return {};
        
        // Initialize the 2D array with m rows and n columns filled with 0
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        // Fill the 2D array with the elements from the original 1D array
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = original[n * i + j];
            }
        }

        return ans; // Return the reshaped 2D array
    }
};

// Example usage:
int main() {
    vector<int> original = {1, 2, 3, 4};
    int m = 2, n = 2;
    Solution sol;
    vector<vector<int>> result = sol.construct2DArray(original, m, n);
    
    // Output the resulting 2D array
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
