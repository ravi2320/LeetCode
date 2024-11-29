/*
2577. Minimum Time to Visit a Cell In a Grid
Solved
Hard
Topics
Companies
Hint
You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].

You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.

Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.

 

Example 1:



Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
Output: 7
Explanation: One of the paths that we can take is the following:
- at t = 0, we are on the cell (0,0).
- at t = 1, we move to the cell (0,1). It is possible because grid[0][1] <= 1.
- at t = 2, we move to the cell (1,1). It is possible because grid[1][1] <= 2.
- at t = 3, we move to the cell (1,2). It is possible because grid[1][2] <= 3.
- at t = 4, we move to the cell (1,1). It is possible because grid[1][1] <= 4.
- at t = 5, we move to the cell (1,2). It is possible because grid[1][2] <= 5.
- at t = 6, we move to the cell (1,3). It is possible because grid[1][3] <= 6.
- at t = 7, we move to the cell (2,3). It is possible because grid[2][3] <= 7.
The final time is 7. It can be shown that it is the minimum time possible.
Example 2:



Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
Output: -1
Explanation: There is no path from the top left to the bottom-right cell.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
0 <= grid[i][j] <= 105
grid[0][0] == 0
 
*/

/*
Approach:
1. **Priority Queue (Dijkstra's Algorithm):**
   - Use a priority queue to always process the current cell with the smallest time.
   - Start from the top-left cell `(0,0)`.

2. **Cell Updates:**
   - For each neighbor cell `(i, j)`:
     - If the current time (`time`) allows immediate movement (`grid[i][j] <= time`), move with a time increment of `+1`.
     - If `grid[i][j] > time`, determine when movement is possible:
       - If the difference `(grid[i][j] - time)` is odd, we can move directly.
       - If it's even, wait for one extra time unit (`time = grid[i][j] + 1`).

3. **Visited Check:**
   - Use a `visited` array to avoid re-processing cells.

4. **Edge Cases:**
   - If both adjacent cells `(0,1)` and `(1,0)` of `(0,0)` are initially blocked (`grid[0][1] > 1` and `grid[1][0] > 1`), return `-1`.

5. **Termination:**
   - The algorithm ends when the bottom-right cell `(m-1, n-1)` is reached, returning its minimum time.

Time Complexity:
- **O(m × n × log(m × n))**, where `m` is the number of rows and `n` is the number of columns.

Space Complexity:
- **O(m × n)** for priority queue and auxiliary data structures.

*/

#define P pair<int, pair<int, int>>

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Early exit if the first move is impossible
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        // Initialization
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Start from top-left corner
        pq.push({grid[0][0], {0, 0}});
        res[0][0] = 0;

        while (!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // Skip if already visited
            if (visited[row][col]) continue;

            // Mark as visited
            visited[row][col] = true;

            // Check if bottom-right corner is reached
            if (row == m - 1 && col == n - 1) {
                return res[row][col];
            }

            // Explore neighbors
            for (auto& dir : directions) {
                int i = dir[0] + row;
                int j = dir[1] + col;

                // Skip out-of-bound cells
                if (i < 0 || i >= m || j < 0 || j >= n)
                    continue;

                // Determine the time to move to the neighboring cell
                if (grid[i][j] <= time) {
                    pq.push({time + 1, {i, j}});
                    res[i][j] = time + 1;
                } else if ((grid[i][j] - time) % 2 == 0) {
                    pq.push({grid[i][j] + 1, {i, j}});
                    res[i][j] = grid[i][j] + 1;
                } else {
                    pq.push({grid[i][j], {i, j}});
                    res[i][j] = grid[i][j];
                }
            }
        }

        // Return the result for bottom-right corner
        return res[m - 1][n - 1];
    }
};
