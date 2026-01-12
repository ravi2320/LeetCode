/*
1266. Minimum Time Visiting All Points

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order, but these do not count as visits.
 

Example 1:


Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5
 

Constraints:

points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000
*/

/*
Approach:
---------
To move from one point to the next, we are allowed to:
- Move vertically
- Move horizontally
- Move diagonally (which moves both x and y by 1 in one second)

For two consecutive points:
1. Compute the absolute difference in x-coordinates → dx
2. Compute the absolute difference in y-coordinates → dy
3. The optimal strategy is:
   - Use diagonal moves as much as possible: min(dx, dy)
   - Remaining distance is covered by straight moves: abs(dx - dy)
4. Total time for that segment = min(dx, dy) + abs(dx - dy)

Sum this time for all consecutive point pairs.

Intuition:
----------
A diagonal move reduces both x and y simultaneously, making it the
most efficient move when both dx and dy are positive.
Once one coordinate matches, only straight moves are required.
This greedy approach guarantees minimum time.

Time Complexity:
----------------
O(n)
- We traverse the points array once

Space Complexity:
-----------------
O(1)
- Only constant extra variables are used

*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        // Traverse through consecutive points
        for (int i = 0; i < n - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];

            // Absolute differences
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);

            // Add minimum time required between two points
            ans += min(dx, dy) + abs(dx - dy);
        }

        return ans;
    }
};
