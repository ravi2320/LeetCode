/*
650. 2 Keys Keyboard
Solved
Medium
Topics
Companies
Hint
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Example 2:

Input: n = 1
Output: 0
 

Constraints:

1 <= n <= 1000
*/

/*
Intuition:
- The problem is to find the minimum number of steps required to get exactly `n` 'A's on the notepad starting with only one 'A'. The allowed operations are:
  1. Copy All: Copy all the 'A's present on the notepad.
  2. Paste: Paste the copied 'A's.

- This can be solved using dynamic programming by maintaining a 2D DP array where `dp[currA][clipA]` represents the minimum steps needed to reach `n` 'A's when `currA` represents the current number of 'A's on the notepad, and `clipA` represents the number of 'A's in the clipboard.

- The recursive relation considers two operations:
  1. `copyAndPaste`: Copy all and paste (results in doubling the number of 'A's).
  2. `paste`: Paste only (adds the clipboard's 'A's to the current 'A's).

- The solution builds upon smaller subproblems and uses memoization to avoid redundant calculations.

Time Complexity:
- The time complexity is O(n^2), since each state in the DP array is computed once.

Space Complexity:
- The space complexity is O(n^2), due to the DP table storing results for up to `n` 'A's with up to `n` 'A's in the clipboard.

*/

class Solution {
public:
    int solve(int currA, int clipA, int n, vector<vector<int>> &dp) {
        // Base case: If the current number of 'A's is exactly n, no more steps are needed.
        if (currA == n) return 0;

        // If the current number of 'A's exceeds n, return a large number to indicate an invalid path.
        if (currA > n) return 1e6;

        // Return the memoized result if already computed.
        if (dp[currA][clipA] != -1) {
            return dp[currA][clipA];
        }

        // Calculate the number of steps for the two possible operations:
        // 1. Copy All and Paste (costs 2 steps: one for copying and one for pasting).
        int copyAndPaste = 2 + solve(currA + currA, currA, n, dp);

        // 2. Paste only (costs 1 step).
        int paste = 1 + solve(currA + clipA, clipA, n, dp);

        // Take the minimum of the two options and store it in the DP table.
        return dp[currA][clipA] = min(copyAndPaste, paste);
    }

    int minSteps(int n) {
        // Special case: If n is 1, no steps are needed.
        if (n == 1) return 0;

        // Initialize a DP table to store results. The table size is set to a reasonable upper limit.
        vector<vector<int>> dp(1001, vector<int>(1001, -1));

        // Start with 1 'A' on the notepad and 1 'A' in the clipboard.
        return 1 + solve(1, 1, n, dp);
    }
};


/*
Intuition:
- The problem asks for the minimum number of steps required to get exactly `n` 'A's on the notepad starting with only one 'A'. The allowed operations are:
  1. Copy All: Copy all the 'A's present on the notepad.
  2. Paste: Paste the copied 'A's.

- The approach is to break down the number `n` into its factors and use dynamic programming to store the minimum steps required for each number of 'A's up to `n`.

- For each `i`, we find the largest factor `factor` that divides `i`. If `i` can be expressed as `factor * k`, then to get `i` 'A's, we can copy when we have `factor` 'A's and paste `k-1` times. The number of steps to achieve `i` is then the sum of steps to reach `factor`, one copy operation, and `k-1` paste operations.

Time Complexity:
- The time complexity is O(n√n), where the outer loop runs `n` times and the inner loop (finding factors) runs up to √n times.

Space Complexity:
- The space complexity is O(n), as we use a DP array to store the minimum steps for each number of 'A's up to `n`.

*/

class Solution {
public:
    int minSteps(int n) {
        
        if (n == 1) return 0; // Base case: If n is 1, no steps are needed.

        if (n == 2) return 2; // Special case: If n is 2, we need exactly 2 steps.

        vector<int> dp(n+1, 0); // DP array to store the minimum steps for each number of 'A's.
        dp[2] = 2; // Initial value for dp[2] as we need exactly 2 steps to reach 2 'A's.

        for (int i = 3; i <= n; i++) {

            int factor = i / 2;

            // Finding the largest factor of `i`.
            while (factor >= 1) {
                if (i % factor == 0) {
                    int steps_to_print_A = dp[factor]; // Steps needed to reach `factor` 'A's.
                    int copy = 1; // One copy operation.
                    int paste = (i / factor) - 1; // Number of paste operations.

                    dp[i] = steps_to_print_A + copy + paste; // Total steps to reach `i` 'A's.
                    break;
                }
                factor--;
            }
        }
        
        return dp[n]; // Return the minimum steps required to reach `n` 'A's.
    }
};
