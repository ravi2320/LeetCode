/*
2812. Find the Safest Path in a Grid
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

 

Example 1:


Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
Example 2:


Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
Example 3:


Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
 

Constraints:

1 <= grid.length == n <= 400
grid[i].length == n
grid[i][j] is either 0 or 1.
There is at least one thief in the grid.
*/

// Intuition:
// - We perform a two-step approach to solve the problem.
// - In the first step, we precalculate the distance of each cell to the nearest thief using BFS from each thief's position.
// - In the second step, we perform binary search on the safeness factor (SF) to find the maximum possible SF such that the police can reach the destination (bottom-right cell) without encountering any thieves.
// - We use BFS to traverse the grid from the top-left cell to the bottom-right cell while checking if the current SF allows the police to reach the destination without encountering any thieves.

// Time Complexity: O(N^2 * log(400)), where N is the size of the grid.
// - Precomputation of distNearestThief: O(N^2) for BFS traversal from each thief's position.
// - Binary search on SF: O(log(400)) for the range [0, 400].
// - BFS traversal for each SF: O(N^2) for traversing the grid.
// - Overall time complexity: O(N^2 * log(400)).
// Space Complexity: O(N^2) for storing distNearestThief, visited, and the queue.

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    // Function to check if police can reach the destination without encountering any thieves
    bool check(vector<vector<int>>& distNearestThief, int sf) {
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        que.push({0, 0});
        visited[0][0] = true;

        if (distNearestThief[0][0] < sf)
            return false;

        while (!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();

            if (curr_i == n - 1 && curr_j == n - 1) {
                return true;
            }

            for (vector<int>& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !visited[new_i][new_j]) {
                    if (distNearestThief[new_i][new_j] < sf) {
                        continue; // Reject this cell
                    }
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }

        return false;
    }

    // Function to calculate the maximum safeness factor
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        // Step 1: Precalculate distNearestThief using BFS
        vector<vector<int>> distNearestThief(n, vector<int>(n, -1));
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while (!que.empty()) {
            int size = que.size();

            while (size--) {
                int curr_i = que.front().first;
                int curr_j = que.front().second;
                que.pop();
                distNearestThief[curr_i][curr_j] = level;
                for (vector<int>& dir : directions) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !visited[new_i][new_j]) {
                        que.push({new_i, new_j});
                        visited[new_i][new_j] = true;
                    }
                }
            }
            level++;
        }

        // Step 2: Binary search on safeness factor (SF)
        int l = 0;
        int r = 400; // Max SF value
        int result = 0;

        while (l <= r) {
            int mid_sf = l + (r - l) / 2;

            if (check(distNearestThief, mid_sf)) {
                result = mid_sf;
                l = mid_sf + 1;
            } else {
                r = mid_sf - 1;
            }
        }

        return result;
    }
};
