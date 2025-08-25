/*
498. Diagonal Traverse

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105
*/

/*
Approach:
1. Use a hash map (or ordered map) where the key is (i + j), representing the diagonal index.
2. Traverse the matrix, and for each element mat[i][j], store it in mp[i+j].
3. After grouping, for each diagonal:
   - If the diagonal index is even, reverse the stored elements (to achieve zig-zag pattern).
   - Append the values to the result.
4. Return the final result array.

Intuition:
- All elements having the same (row + col) value belong to the same diagonal.
- By iterating over the matrix and storing elements grouped by (i + j), we naturally form diagonals.
- To match the problem’s required traversal order, we reverse even diagonals.
- This ensures the proper zig-zag diagonal traversal of the matrix.

Time Complexity:
- O(n*m) for traversing the entire matrix.
- Reversing some diagonals costs O(total elements) = O(n*m).
- Hence overall time complexity = O(n*m).

Space Complexity:
- Extra space for the map storing elements by diagonals.
- In worst case, every diagonal stores elements separately, so O(n*m).
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        map<int, vector<int>> mp;  // Stores diagonals based on i+j

        // Step 1: Group elements by diagonal index (i+j)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;

        // Step 2: Process diagonals in order
        for(auto &itr : mp){
            // Reverse the diagonal if its index is even
            if(itr.first % 2 == 0){
                reverse(itr.second.begin(), itr.second.end());
            }

            // Append the diagonal elements to the result
            for(int &x : itr.second){
                ans.push_back(x);
            }
        }

        return ans; // Final diagonal traversal order
    }
};
