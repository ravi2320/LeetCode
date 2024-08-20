/*
1140. Stone Game II
Solved
Medium
Topics
Companies
Hint
Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104
 

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104
*/

class Solution {
    int n;
    int t[2][101][101]; // DP table to store intermediate results

public:
    /**
     * Intuition:
     * The problem is solved using a dynamic programming approach with memoization. 
     * Alice and Bob take turns to pick stones from the piles, and the goal is to maximize the number of stones Alice can collect.
     * The game is recursive in nature, where the outcome depends on the previous decisions. 
     * The state is defined by the current player, index, and the value of M (the maximum number of piles that can be taken).
     *
     * Time Complexity:
     * - O(n^3) where n is the number of piles. This is because, for each state (indexed by `idx` and `M`), 
     *   we may explore up to O(n) possible moves.
     * 
     * Space Complexity:
     * - O(n^2) due to the memoization table that stores results for `2 * n * n` states.
     */

    int solveForAlice(vector<int>& piles, int person, int idx, int M) {
        if (idx >= n) return 0; // Base case: No more piles to take

        // Return the stored result if this state has been computed before
        if (t[person][idx][M] != -1) {
            return t[person][idx][M];
        }

        int stones = 0;
        int result = (person == 1) ? -1 : INT_MAX; // Alice wants to maximize, Bob wants to minimize

        // Iterate over the possible number of piles Alice/Bob can take
        for (int x = 1; x <= min(2 * M, n - idx); x++) {
            stones += piles[idx + x - 1];

            if (person == 1) { // Alice's turn
                result = max(result, stones + solveForAlice(piles, 0, idx + x, max(x, M)));
            } else { // Bob's turn
                result = min(result, solveForAlice(piles, 1, idx + x, max(x, M)));
            }
        }

        // Store the computed result in the DP table
        return t[person][idx][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size(); // Number of piles
        memset(t, -1, sizeof(t)); // Initialize the DP table with -1 (indicating uncomputed states)
        return solveForAlice(piles, 1, 0, 1); // Start the game with Alice's turn, index 0, and M = 1
    }
};
