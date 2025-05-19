/*
1931. Painting a Grid With Three Different Colors
Solved
Hard
Topics
Companies
Hint
You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.
Example 2:


Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.
Example 3:

Input: m = 5, n = 5
Output: 580986
 

Constraints:

1 <= m <= 5
1 <= n <= 1000
*/

/*
Approach:
- We are asked to color an m x n grid such that:
  1. No two adjacent cells in a row have the same color.
  2. No two cells in the same column (between adjacent columns) have the same color.

- Strategy:
  - Generate all valid column colorings of height `m` such that adjacent cells (vertically) differ.
  - Use DP to count the number of ways to build up the grid column-by-column:
    - dp[col][prevColState] = number of ways to color remaining columns given previous column's coloring.

- We treat each column as a "state", and we generate all valid states for a column.
- Then we use memoized recursion (top-down DP) to count the number of ways to fill the grid column by column,
  ensuring adjacent columns have different colors in each corresponding row.

Intuition:
- The grid is colored column-by-column.
- A valid coloring for the grid is a sequence of valid column states such that no two adjacent columns have same color in the same row.

Time Complexity:
- O(n * S^2 * m), where:
    - S = number of valid column states (which is exponential in m, ~3*2^(m-1)),
    - n = number of columns,
    - m = number of rows (impacts state generation and comparison).
    
Space Complexity:
- O(n * S) for memoization table + O(S) for storing all states.
*/

class Solution {
    vector<string> columnsStates; // All valid single-column colorings
    int M = 1e9+7;

public:
    // Generate all valid column states of height `m`
    void generateColumnsStates(string curr, char prevChar, int len, int m) {
        if(len == m){
            columnsStates.push_back(curr);
            return;
        }

        for(char ch : {'R', 'G', 'B'}) {
            if(ch != prevChar) {
                generateColumnsStates(curr + ch, ch, len + 1, m);
            }
        }
    }

    // Recursive DP to solve number of valid configurations
    int solve(int remLen, int prevIdx, int m, int S, vector<vector<int>> &dp) {
        if(remLen == 0)
            return 1;

        if(dp[remLen][prevIdx] != -1)
            return dp[remLen][prevIdx];

        string prevState = columnsStates[prevIdx];
        int ways = 0;

        // Try every possible next column
        for(int i = 0; i < S; i++) {
            if(i == prevIdx) continue; // Same state can't be adjacent

            string currState = columnsStates[i];

            bool valid = true;
            for(int j = 0; j < m; j++) {
                if(currState[j] == prevState[j]) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                ways = (ways + solve(remLen - 1, i, m, S, dp)) % M;
            }
        }

        return dp[remLen][prevIdx] = ways;
    }

    // Main function
    int colorTheGrid(int m, int n) {
        generateColumnsStates("", '#', 0, m); // '#' acts as a dummy previous char

        int res = 0;
        int S = columnsStates.size();

        vector<vector<int>> dp(n, vector<int>(S, -1)); // dp[col][prevStateIndex]

        // Try all valid first column states
        for(int i = 0; i < S; i++) {
            res = (res + solve(n - 1, i, m, S, dp)) % M;
        }

        return res;
    }
};
