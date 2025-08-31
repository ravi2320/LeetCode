/*
3459. Length of Longest V-Shaped Diagonal Segment
Solved

avatar
Discuss Approach
arrow-up
Hard
Topics
premium lock icon
Companies
Hint
You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.

A V-shaped diagonal segment is defined as:

The segment starts with 1.
The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
The segment:
Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
Continues the sequence in the same diagonal direction.
Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.
Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.

 

Example 1:

Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

Output: 5

Explanation:



The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4), and continues as (3,3) → (4,2).

Example 2:

Input: grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

Output: 4

Explanation:



The longest V-shaped diagonal segment has a length of 4 and follows these coordinates: (2,3) → (3,2), takes a 90-degree clockwise turn at (3,2), and continues as (2,1) → (1,0).

Example 3:

Input: grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]

Output: 5

Explanation:



The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,0) → (1,1) → (2,2) → (3,3) → (4,4).

Example 4:

Input: grid = [[1]]

Output: 1

Explanation:

The longest V-shaped diagonal segment has a length of 1 and follows these coordinates: (0,0).

 

Constraints:

n == grid.length
m == grid[i].length
1 <= n, m <= 500
grid[i][j] is either 0, 1 or 2.
*/

/*
Approach:
- We are asked to find the maximum length of a diagonal path in the grid that follows 
  alternating values (1 -> 2 -> 0 -> 2 -> 0 ... pattern).
- From each cell containing '1', we attempt to explore all 4 diagonal directions.
- We recursively move in the same diagonal direction if the next value matches the required alternating pattern.
- We also allow at most one turn (change of diagonal direction) during traversal.
- Memoization (DP) is used to cache results for (i, j, direction, canTurn) to avoid recomputation.

Intuition:
- Think of this problem as walking along diagonals in a grid while ensuring that values alternate properly.
- From each starting cell with value `1`, we explore diagonals.
- At each step, we either:
  1. Continue moving in the same diagonal direction.
  2. If turning is allowed, change to another diagonal direction and continue.
- Memoization ensures efficiency by preventing repeated DFS calls from overlapping subproblems.

Time Complexity:
- Each state is defined by (i, j, direction, canTurn), giving O(m * n * 4 * 2) states.
- Each state takes O(1) work (just recursive transitions).
- Total Time Complexity = O(m * n).
- Here, m = rows and n = columns of the grid.

Space Complexity:
- Memoization table size = O(m * n * 4 * 2).
- Recursion depth in worst case = O(m + n).
- Hence Space Complexity = O(m * n).
*/

class Solution {
public:
    // Directions representing 4 diagonals: ↘, ↙, ↖, ↗
    vector<vector<int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int m, n;
    int t[501][501][4][2]; // DP cache: position + direction + turn-flag

    // Recursive DFS + memoization
    int solve(int i, int j, int d, bool canTurn, int val, vector<vector<int>>& grid) {
        int i_ = i + directions[d][0];
        int j_ = j + directions[d][1];

        // Out of bounds or value mismatch -> stop
        if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != val) {
            return 0;
        }

        // Return cached result if available
        if(t[i_][j_][d][canTurn] != -1) {
            return t[i_][j_][d][canTurn];
        }

        int result = 0;

        // Case 1: Keep moving in the same direction
        int keepMoving = 1 + solve(i_, j_, d, canTurn, (val == 2 ? 0 : 2), grid);
        result = max(result, keepMoving);

        // Case 2: Turn to another diagonal if turning is allowed
        if(canTurn == true) {
            int turnAndMove = max(keepMoving, 1 + solve(i_, j_, (d+1)%4, false, (val == 2 ? 0 : 2), grid));
            result = max(result, turnAndMove);
        }

        // Store result in DP cache
        return t[i_][j_][d][canTurn] = result;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t)); // Initialize DP table with -1

        int result = 0;

        // Start from each cell that contains '1'
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    // Try all 4 diagonal directions
                    for(int d = 0; d <= 3; d++) {
                        result = max(result, 1 + solve(i, j, d, true, 2, grid));
                    }
                }
            }
        }

        return result;
    }
};