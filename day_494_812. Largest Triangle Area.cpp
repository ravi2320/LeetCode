/*
812. Largest Triangle Area

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:


Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2.00000
Explanation: The five points are shown in the above figure. The red triangle is the largest.
Example 2:

Input: points = [[1,0],[0,0],[0,1]]
Output: 0.50000
 

Constraints:

3 <= points.length <= 50
-50 <= xi, yi <= 50
All the given points are unique.
*/

/*
Approach:
1. The area of a triangle given 3 points (x1, y1), (x2, y2), (x3, y3) can be found using the
   Shoelace formula:
      Area = |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2
2. Iterate over all triplets of points (brute force).
3. Compute the area for each triplet using the formula and update the maximum area.
4. Return the maximum area found.

Intuition:
- Any 3 points in 2D space form a triangle (unless collinear).
- To maximize the area, we must check all combinations.
- Shoelace formula gives a direct O(1) way to compute the triangle’s area.

Time Complexity:
- O(n^3), since we check all possible triplets of points.
Space Complexity:
- O(1), only a few variables are used.

*/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        int n = points.size();

        // Iterate over all triplets of points
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Extract coordinates of the points
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];

                    // Compute area using Shoelace formula
                    double area = abs(x1 * (y2 - y3) +
                                      x2 * (y3 - y1) +
                                      x3 * (y1 - y2)) * 0.5;

                    // Update maximum area
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
