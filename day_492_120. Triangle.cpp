/*
120. Triangle

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 
*/

/*
Approach:
1. Use Bottom-Up Dynamic Programming.
2. Start from the second-last row and move upward.
3. For each cell triangle[i][j], the minimum path sum is:
      triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1])
4. Update in-place (or in a copy) until we reach the top.
5. Final result = updated triangle[0][0].

Intuition:
- Each number can only move to two adjacent numbers in the next row.
- By starting from the bottom, we always know the minimum cost for the row below.
- This avoids recomputation and leads to efficient DP.

Time Complexity:
- O(n^2), since we update each element of the triangle once (n rows, total ~ n^2/2 elements).
Space Complexity:
- O(n^2) if using a DP copy (like `t` here).
- Can be optimized to O(n) by only keeping the last row.

*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Copy triangle into DP table t
        vector<vector<int>> t = triangle;
        
        // Process from second last row to top
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                // Update current cell with min path sum from below
                t[i][j] += min(t[i+1][j], t[i+1][j+1]);
            }
        }

        // Final result is stored at top
        return t[0][0];
    }
};
