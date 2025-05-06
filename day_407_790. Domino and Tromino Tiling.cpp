/*
790. Domino and Tromino Tiling
Solved
Medium
Topics
Companies
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000
*/


/*
Approach:
- This is a variation of the tiling problem using dynamic programming.
- You are given a 2 x n board. You can tile it using:
  - 2 x 1 dominoes (vertical or horizontal),
  - L-shaped trominoes (3 blocks forming an "L" shape).

Intuition:
- Let `dp[n]` represent the number of ways to tile a 2 x n board.
- The recurrence is based on how the last few tiles are placed:
  dp[n] = (2 * dp[n - 1]) + dp[n - 3]

Why?
1. From dp[n-1]: Place a vertical domino at the end.
2. From dp[n-3]: Place an L-shaped tromino — multiple configurations contribute to this.

Base Cases:
- dp[1] = 1 → Only vertical domino
- dp[2] = 2 → Two vertical or two horizontal dominoes
- dp[3] = 5 → Verified by manual enumeration

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
    int M = 1e9 + 7;         // Modulo to prevent overflow
    int dp[1001];            // Memoization array
public:
    // Recursive function with memoization
    int solve(int n) {
        // Base cases
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 5;

        // Return memoized result
        if (dp[n] != -1)
            return dp[n];

        // Recurrence relation
        return dp[n] = (2LL * solve(n - 1) % M + solve(n - 3) % M) % M;
    }

    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));  // Initialize dp array
        return solve(n);             // Start solving from n
    }
};


/*
Approach:
- This is a bottom-up dynamic programming solution for the tiling problem using:
  - 2x1 dominoes and L-shaped trominoes to tile a 2 x n board.

Intuition:
- Let dp[i] represent the number of ways to tile a 2 x i board.
- Recurrence:
    dp[i] = (2 * dp[i - 1] + dp[i - 3]) % M
  Explanation:
    - 2 * dp[i - 1]: Placing a vertical domino or two horizontal dominoes.
    - dp[i - 3]: Covers all unique placements of an L-shaped tromino.

Base Cases:
- dp[0] = 1  (1 way to tile an empty board)
- dp[1] = 1  (1 vertical domino)
- dp[2] = 2  (two vertical or two horizontal dominoes)

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        const int M = 1e9 + 7;
        vector<long long> dp(n + 1);
        
        dp[0] = 1; // base: empty board
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = (2LL * dp[i - 1] % M + dp[i - 3] % M) % M;
        }

        return dp[n];
    }
};