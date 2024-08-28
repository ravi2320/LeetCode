/*
1905. Count Sub Islands
Solved
Medium
Topics
Companies
Hint
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

 

Example 1:


Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
Example 2:


Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
 

Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.
*/

/*
Intuition:
The problem requires counting the number of sub-islands in `grid2` that are also islands in `grid1`. A sub-island in `grid2` is considered valid if every land cell in the sub-island in `grid2` corresponds to a land cell in `grid1`. We can use Depth-First Search (DFS) to explore each island in `grid2` and verify whether it is fully contained within an island in `grid1`.

Approach:
1. **DFS Traversal**:
   - Traverse `grid2` to find unvisited land cells (cells with value `1`).
   - For each unvisited land cell, initiate a DFS that explores the entire connected component (island) in `grid2`.
   - During the DFS, check whether the corresponding cells in `grid1` are also land cells.
   - If any cell in the current island of `grid2` does not have a corresponding land cell in `grid1`, mark the island as invalid.

2. **Count Valid Sub-Islands**:
   - If the DFS confirms that the current island in `grid2` is a valid sub-island, increment the count.

Time Complexity:
- The time complexity is `O(n * m)` where `n` is the number of rows and `m` is the number of columns. Each cell is visited at most once.

Space Complexity:
- The space complexity is `O(n * m)` in the worst case due to the recursion stack for DFS.

*/

class Solution {
    int n, m;
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &res) {
        // Boundary checks and if the cell is water or already visited
        if(i < 0 || j < 0 || i >= n || j >= m || !grid2[i][j]) return;

        // Check if the current cell in grid2 is a valid land cell in grid1
        res = res & grid1[i][j];

        // Mark the current cell in grid2 as visited
        grid2[i][j] = 0;

        // Explore all four directions
        dfs(grid1, grid2, i, j-1, res); // Left
        dfs(grid1, grid2, i, j+1, res); // Right
        dfs(grid1, grid2, i-1, j, res); // Up
        dfs(grid1, grid2, i+1, j, res); // Down
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        n = grid1.size(), m = grid1[0].size();

        // Traverse through each cell in grid2
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // If the cell is land in grid2
                if(grid2[i][j]) {
                    bool res = true;
                    // Perform DFS to explore the island
                    dfs(grid1, grid2, i, j, res);
                    // If the island is valid, increment the count
                    if(res) cnt++;
                }
            }
        }

        return cnt;
    }
};
