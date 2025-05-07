/*
3341. Find Minimum Time to Reach Last Room I
Solved
Medium
Topics
Companies
Hint
There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 

Example 1:

Input: moveTime = [[0,4],[4,4]]

Output: 6

Explanation:

The minimum time required is 6 seconds.

At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in one second.
Example 2:

Input: moveTime = [[0,0,0],[0,0,0]]

Output: 3

Explanation:

The minimum time required is 3 seconds.

At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in one second.
At time t == 2, move from room (1, 1) to room (1, 2) in one second.
Example 3:

Input: moveTime = [[0,1],[1,2]]

Output: 3

 

Constraints:

2 <= n == moveTime.length <= 50
2 <= m == moveTime[i].length <= 50
0 <= moveTime[i][j] <= 109
*/

/*
Approach:
- This is a Dijkstra-like shortest path algorithm on a 2D grid.
- Each cell has a move time constraint, i.e., you cannot enter a cell before its moveTime value.
- From the current cell, you can move in 4 directions: up, down, left, right.

Intuition:
- Use a min-heap priority queue to always expand the cell with the least current time.
- For every move to a neighbor (i_, j_), calculate:
    waitTime = max(moveTime[i_][j_] - currTime, 0)
    totalTime = currTime + waitTime + 1 (1 for the move itself)
- Only update the result if this new path gives a smaller time.

Time Complexity: O(m * n * log(m * n))
- Each cell is processed once and inserted into the priority queue at most once.
- The heap operations take log(m * n) time.

Space Complexity: O(m * n)
- For the result matrix and the priority queue.

*/

class Solution {
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();

        // Initialize result matrix with INT_MAX
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        res[0][0] = 0; // Starting point
        pq.push({0, {0, 0}}); // {time, {i, j}}

        while (!pq.empty()) {
            int currTime = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            // If destination is reached
            if (i == m - 1 && j == n - 1) {
                return res[i][j];
            }

            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                // Check bounds
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    int waitTime = max(moveTime[i_][j_] - currTime, 0);
                    int nextTime = currTime + waitTime + 1;

                    // If better path found
                    if (res[i_][j_] > nextTime) {
                        res[i_][j_] = nextTime;
                        pq.push({nextTime, {i_, j_}});
                    }
                }
            }
        }

        return -1; // If unreachable
    }
};
