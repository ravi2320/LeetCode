/*
2503. Maximum Number of Points From Grid Queries
Solved
Hard
Topics
Companies
Hint
You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.

 

Example 1:


Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.
Example 2:


Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
k == queries.length
1 <= k <= 104
1 <= grid[i][j], queries[i] <= 106
*/

/*
Approach:
1. **Use BFS with a Min-Heap (Priority Queue)**:
   - Instead of using DFS for each query, we process the grid in **ascending order of values**.
   - The **priority queue** ensures we always expand the **smallest value first**.
   
2. **Sort Queries for Efficient Processing**:
   - Sorting ensures we process smaller queries first and **reuse previous results**.
   - For each query, we count how many cells have values **less than the query**.

3. **Process Each Cell Only Once**:
   - We use a `visited` matrix to prevent revisits.
   - Every cell is pushed into the min-heap **exactly once**, reducing redundant work.

Intuition:
- Instead of starting a new DFS for each query, we **incrementally** expand the reachable cells.
- The **priority queue** ensures that cells with the **smallest value** are processed first.
- Sorting the queries allows us to **answer them efficiently in increasing order**.

Time Complexity:
- **O(MN log MN + Q log Q)**  
  - BFS processes each grid cell **once** → **O(MN)**  
  - Each insertion in priority queue is **O(log MN)**  
  - Sorting queries is **O(Q log Q)**  

Space Complexity:
- **O(MN)** (for `visited` matrix and priority queue storage)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(queries.size(), 0);

        // Directions for moving in the grid (right, left, down, up)
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Min-heap to store {grid value, row, col}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        int count = 0;
        int maxVal = grid[0][0];

        // Process each query in sorted order
        for (auto [query, index] : sortedQueries) {
            while (!pq.empty() && pq.top().first < query) {
                auto [val, pos] = pq.top();
                pq.pop();
                int r = pos.first, c = pos.second;
                count++;

                for (auto [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        pq.push({grid[nr][nc], {nr, nc}});
                        visited[nr][nc] = true;
                    }
                }
            }
            res[index] = count;
        }

        return res;
    }
};

// Driver Code
int main() {
    vector<vector<int>> grid = {{1, 2, 4}, {3, 4, 3}, {2, 1, 2}};
    vector<int> queries = {2, 3, 4};
    Solution obj;
    vector<int> result = obj.maxPoints(grid, queries);

    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}