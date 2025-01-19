/*
407. Trapping Rain Water II
Solved
Hard
Topics
Companies
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

Example 1:


Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
Example 2:


Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
 

Constraints:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104
*/

/*
Approach:
1. Use a priority queue to process the lowest boundary cell first.
2. Start from all boundary cells and expand inward using BFS.
3. Track visited cells to avoid revisiting.
4. Accumulate trapped water for each cell based on the height difference.

Time Complexity: O(m * n * log(m * n))
- Each cell is processed once and inserted into the priority queue, which takes O(log(m * n)) time.

Space Complexity: O(m * n)
- For the priority queue and visited array.

*/

class Solution {
public:
    typedef pair<int, pair<int, int>> P; // {height, {row, col}}
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 4 possible directions (up, down, left, right)

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0; // No water can be trapped in a height map smaller than 3x3

        // Min-Heap to store cells with their heights
        priority_queue<P, vector<P>, greater<P>> pq;

        // Visited array to keep track of processed cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the priority queue
        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) { // First and last columns
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        for (int col = 0; col < n; col++) {
            for (int row : {0, m - 1}) { // First and last rows
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;

        // BFS using the priority queue
        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();

            int i = cell.first;
            int j = cell.second;

            // Explore all 4 neighbors
            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                // Check bounds and if the neighbor is unvisited
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                    // Calculate trapped water for the current neighbor
                    water += max(0, height - heightMap[i_][j_]);

                    // Push the neighbor into the queue with updated height
                    pq.push({max(height, heightMap[i_][j_]), {i_, j_}});

                    // Mark the neighbor as visited
                    visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
};