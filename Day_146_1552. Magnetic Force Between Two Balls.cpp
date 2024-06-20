/*
1552. Magnetic Force Between Two Balls
Solved
Medium
Topics
Companies
Hint
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 

Example 1:


Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
 

Constraints:

n == position.length
2 <= n <= 105
1 <= position[i] <= 109
All integers in position are distinct.
2 <= m <= position.length
*/

/*
Intuition:
- The problem is to place `m` balls in positions such that the minimum distance between any two balls is maximized.
- This can be solved using a binary search approach on the possible minimum distances.

Approach:
1. Sort the positions.
2. Use binary search to find the largest minimum distance that can be achieved.
3. The binary search checks if it is possible to place `m` balls with at least a given minimum distance (`force`).

Time Complexity:
- O(n log d): The sorting step takes O(n log n) time, and the binary search takes O(log d) time, where d is the difference between the maximum and minimum positions. Each check within the binary search takes O(n) time.

Space Complexity:
- O(1): Only a few extra variables are used, which consume constant space.

*/

class Solution {
public:
    // Helper function to determine if it is possible to place m balls with at least 'force' distance apart
    bool possibleToPlace(int force, vector<int>& position, int m) {
        int prev = position[0];  // Place the first ball at the first position
        int cntBalls = 1;  // Counter for balls placed

        for (int i = 1; i < position.size(); i++) {
            int curr = position[i];

            if (curr - prev >= force) {
                cntBalls++;  // Place a ball at the current position
                prev = curr;  // Update the position of the last placed ball
            }

            if (cntBalls == m)  // If all balls are placed, return true
                break;
        }

        return cntBalls == m;
    } 

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());  // Sort the positions

        int minForce = 1;  // Minimum possible force (distance)
        int maxForce = position[n-1] - position[0];  // Maximum possible force (distance)
        int res = 0;

        while (minForce <= maxForce) {
            int midForce = minForce + (maxForce - minForce) / 2;

            if (possibleToPlace(midForce, position, m)) {
                res = midForce;  // Update the result
                minForce = midForce + 1;  // Try for a larger minimum distance
            } else {
                maxForce = midForce - 1;  // Try for a smaller minimum distance
            }
        }

        return res;  // Return the largest minimum distance found
    }
};
