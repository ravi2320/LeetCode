/*
1039. Minimum Score Triangulation of Polygon

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.

 

Example 1:


Input: values = [1,2,3]

Output: 6

Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:


Input: values = [3,7,4,5]

Output: 144

Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

Example 3:


Input: values = [1,3,1,4,1,5]

Output: 13

Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

 

Constraints:

n == values.length
3 <= n <= 50
1 <= values[i] <= 100
*/

/*
Approach:
1. This is a classic dynamic programming (interval DP) problem.
2. We want to triangulate a convex polygon such that the sum of triangle scores is minimized.
   - Each triangle formed by vertices (i, k, j) contributes: values[i] * values[k] * values[j].
3. Define dp[i][j] = minimum triangulation score for the sub-polygon between vertices i and j.
4. Base case: If there are less than 3 vertices between i and j, no triangle can be formed, so return 0.
5. Transition:
   - For each possible k in (i, j), split the polygon into (i..k) and (k..j).
   - Recurrence: dp[i][j] = min(dp[i][j], values[i] * values[k] * values[j] + solve(i,k) + solve(k,j)).
6. Use memoization (top-down DP) to avoid recomputation.

Intuition:
- A polygon triangulation problem is naturally recursive since choosing one triangle divides the polygon into two smaller sub-polygons.
- By trying all possible divisions and caching results, we ensure minimal triangulation cost.
- This is very similar to Matrix Chain Multiplication DP.

Time Complexity:
- O(n^3), since there are O(n^2) states (i,j) and for each we try O(n) possible k.
Space Complexity:
- O(n^2) for the DP table and recursion stack.

*/

class Solution {
    vector<vector<int>> dp; // memoization table
public:
    // Recursive function to compute minimum score for polygon between i and j
    int solve(vector<int>& values, int i, int j) {
        if(j - i + 1 < 3) { // less than 3 vertices = no triangle possible
            return 0;
        }

        if(dp[i][j] != -1) { // return cached result
            return dp[i][j];
        }

        int res = INT_MAX;
        // Try placing triangle with vertex k between i and j
        for(int k = i + 1; k < j; k++) {
            int wt = values[i] * values[k] * values[j]
                   + solve(values, i, k)   // triangulate left polygon
                   + solve(values, k, j);  // triangulate right polygon

            res = min(res, wt);
        }

        return dp[i][j] = res;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(values, 0, n-1);
    }
};
