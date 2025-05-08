/*
3342. Find Minimum Time to Reach Last Room II
Solved
Medium
Topics
Companies
Hint
There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 

Example 1:

Input: moveTime = [[0,4],[4,4]]

Output: 7

Explanation:

The minimum time required is 7 seconds.

At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
Example 2:

Input: moveTime = [[0,0,0,0],[0,0,0,0]]

Output: 6

Explanation:

The minimum time required is 6 seconds.

At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
At time t == 3, move from room (1, 1) to room (1, 2) in one second.
At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
Example 3:

Input: moveTime = [[0,1],[1,2]]

Output: 4

 

Constraints:

2 <= n == moveTime.length <= 750
2 <= m == moveTime[i].length <= 750
0 <= moveTime[i][j] <= 109
*/

/*
Approach:
- This is a variation of Dijkstra's shortest path algorithm on a 2D grid.
- Each cell has a dynamic time constraint `moveTime[i][j]`, and we may have to wait if we arrive too early.
- Movement cost depends on the parity of the sum of cell indices: odd = 1 unit, even = 2 units.

Intuition:
- We maintain a min-heap (priority queue) to always expand the cell that can be reached the earliest.
- For each move, we calculate the earliest possible time to reach the next cell, considering any required waiting.
- If this time improves the previous best time to that cell, we update and push it to the heap.

Time Complexity:
- O(m * n * log(m * n)), where m and n are the dimensions of the grid.
  Each cell may be visited multiple times, but the priority queue ensures minimal work.

Space Complexity:
- O(m * n) for the result grid and the priority queue.

*/

class Solution {
    typedef pair<int, pair<int, int>> P; // (time, (i, j))
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // Directions for moving in the grid (up, down, left, right)
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = moveTime.size(), n = moveTime[0].size();

        // res[i][j] holds the minimum time to reach cell (i, j)
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));

        // Min-heap: stores tuples (time, (i, j))
        priority_queue<P, vector<P>, greater<P>> pq;

        // Starting point
        res[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int currTime = pq.top().first;
            auto [i, j] = pq.top().second;
            pq.pop();

            // If we reached the destination
            if (i == m - 1 && j == n - 1) {
                return res[i][j];
            }

            // Explore all 4 directions
            for (auto &dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                // Check bounds
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    // Movement time depends on parity of i_ + j_
                    int moveT = (i_ + j_) % 2 ? 1 : 2;

                    // If we reach before moveTime[i_][j_], we must wait
                    int waitTime = max(moveTime[i_][j_] - currTime, 0);

                    // Total time to reach the next cell
                    int nextTime = currTime + waitTime + moveT;

                    // If this path is better, update
                    if (res[i_][j_] > nextTime) {
                        res[i_][j_] = nextTime;
                        pq.push({nextTime, {i_, j_}});
                    }
                }
            }
        }

        // Destination not reachable
        return -1;
    }
};