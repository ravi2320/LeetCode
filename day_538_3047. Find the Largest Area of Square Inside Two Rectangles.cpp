/*
3047. Find the Largest Area of Square Inside Two Rectangles

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
There exist n rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays bottomLeft and topRight where bottomLeft[i] = [a_i, b_i] and topRight[i] = [c_i, d_i] represent the bottom-left and top-right coordinates of the ith rectangle, respectively.

You need to find the maximum area of a square that can fit inside the intersecting region of at least two rectangles. Return 0 if such a square does not exist.

 

Example 1:


Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]

Output: 1

Explanation:

A square with side length 1 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 1. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

Example 2:


Input: bottomLeft = [[1,1],[1,3],[1,5]], topRight = [[5,5],[5,7],[5,9]]

Output: 4

Explanation:

A square with side length 2 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 2 * 2 = 4. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

Example 3:

  
Input: bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]

Output: 1

Explanation:

A square with side length 1 can fit inside the intersecting region of any two rectangles. Also, no larger square can, so the maximum area is 1. Note that the region can be formed by the intersection of more than 2 rectangles.

Example 4:

  
Input: bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]

Output: 0

Explanation:

No pair of rectangles intersect, hence, the answer is 0.

 

Constraints:

n == bottomLeft.length == topRight.length
2 <= n <= 103
bottomLeft[i].length == topRight[i].length == 2
1 <= bottomLeft[i][0], bottomLeft[i][1] <= 107
1 <= topRight[i][0], topRight[i][1] <= 107
bottomLeft[i][0] < topRight[i][0]
bottomLeft[i][1] < topRight[i][1]
*/

/*
Approach:
---------
1. Each rectangle is represented by its bottom-left and top-right coordinates.
2. For every pair of rectangles (i, j), compute their overlapping region:
   - Overlapping width  = min(topRightX) - max(bottomLeftX)
   - Overlapping height = min(topRightY) - max(bottomLeftY)
3. If both width and height are positive, an overlap exists.
4. The largest square that can fit inside this overlap
   has side length = min(width, height).
5. Track the maximum such side across all rectangle pairs.
6. Return the square of the maximum side length.

Intuition:
----------
A square can only be formed in the overlapping region of two rectangles.
To maximize the square area, we want the largest possible overlap
where both width and height are available.
Since a square needs equal sides, the limiting factor is the smaller
of overlap width and height.

Time Complexity:
----------------
O(N²)
- Checking all pairs of rectangles

Space Complexity:
-----------------
O(1)
- Only constant extra variables used
*/

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {

        int n = bottomLeft.size();
        int maxSide = 0;

        // Compare every pair of rectangles
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // Overlapping width
                int topRightX = min(topRight[i][0], topRight[j][0]);
                int bottomLeftX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int width = topRightX - bottomLeftX;

                // Overlapping height
                int topRightY = min(topRight[i][1], topRight[j][1]);
                int bottomLeftY = max(bottomLeft[i][1], bottomLeft[j][1]);
                int height = topRightY - bottomLeftY;

                // Side of largest square in overlap
                int side = min(width, height);

                maxSide = max(maxSide, side);
            }
        }

        // Return area of the largest square
        return 1LL * maxSide * maxSide;
    }
};
