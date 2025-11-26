/*
2435. Paths in Matrix Whose Sum Is Divisible by K

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:


Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
Output: 2
Explanation: There are two paths where the sum of the elements on the path is divisible by k.
The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
Example 2:


Input: grid = [[0,0]], k = 5
Output: 1
Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.
Example 3:


Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
Output: 10
Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 5 * 104
1 <= m * n <= 5 * 104
0 <= grid[i][j] <= 100
1 <= k <= 50
*/

/*
Approach:
---------
We must count how many paths (only moving right or down) from top-left to bottom-right
give a total sum divisible by k.

A brute-force approach would explore all possible paths → exponential time.
To optimize, we use **Dynamic Programming + DFS + Memoization**.

State Representation:
---------------------
We define a DP state:
    dp[i][j][rem] = number of valid paths from cell (i, j) to bottom-right
                    when current remainder of path-sum modulo k is "rem".

Transition:
-----------
From cell (i, j), we can go:
- Down → (i+1, j)
- Right → (i, j+1)

Before moving, we add grid[i][j] to "rem":
    new_rem = (rem + grid[i][j]) % k

Base Case:
----------
At the destination (n-1, m-1):
    If (rem + value) % k == 0 → 1 valid path
    Else → 0 paths

Why DP works:
-------------
The only needed information for the future is:
- Where we are: (i, j)
- The current remainder modulo k

Total states = n * m * k, so memoization avoids recomputation.

Intuition:
-----------
We track the sum only mod k because:
If full sum % k == 0 ↔ only remainder matters.  
Storing full sum would be huge, but remainder keeps it small and sufficient.

Time Complexity:
----------------
O(n * m * k)
We compute each DP state once.

Space Complexity:
-----------------
O(n * m * k) for the dp table + recursion stack O(n + m).

*/

class Solution {
    int n, m;
    int mod;
    vector<vector<vector<int>>> dp;  // 3D DP memoization table

public:

    // Recursive function with memoization
    int solve(int i, int j, int rem, vector<vector<int>>& grid, int k) {

        // Out-of-bound check
        if (i < 0 || j < 0 || i >= n || j >= m)
            return 0;

        // If we reached bottom-right cell
        if (i == n - 1 && j == m - 1) {
            // Check if final sum % k == 0
            if ((rem + grid[i][j]) % k == 0)
                return 1;
            return 0;
        }

        // If value already computed, return it
        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        // Compute new remainder after including current cell
        int newRem = (rem + grid[i][j]) % k;

        // Move down
        int down = solve(i + 1, j, newRem, grid, k);

        // Move right
        int right = solve(i, j + 1, newRem, grid, k);

        // Store and return result modulo mod
        return dp[i][j][rem] = (down + right) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        mod = 1e9 + 7;

        // Initialize DP table with -1
        dp.resize(n, vector<vector<int>>(m, vector<int>(k, -1)));

        // Start from (0,0) with remainder = 0
        return solve(0, 0, 0, grid, k);
    }
};
