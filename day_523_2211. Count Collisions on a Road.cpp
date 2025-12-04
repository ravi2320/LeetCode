/*
2211. Count Collisions on a Road

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.

You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting whether the ith car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:

When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
When a moving car collides with a stationary car, the number of collisions increases by 1.
After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.

Return the total number of collisions that will happen on the road.

 

Example 1:

Input: directions = "RLRSLL"
Output: 5
Explanation:
The collisions that will happen on the road are:
- Cars 0 and 1 will collide with each other. Since they are moving in opposite directions, the number of collisions becomes 0 + 2 = 2.
- Cars 2 and 3 will collide with each other. Since car 3 is stationary, the number of collisions becomes 2 + 1 = 3.
- Cars 3 and 4 will collide with each other. Since car 3 is stationary, the number of collisions becomes 3 + 1 = 4.
- Cars 4 and 5 will collide with each other. After car 4 collides with car 3, it will stay at the point of collision and get hit by car 5. The number of collisions becomes 4 + 1 = 5.
Thus, the total number of collisions that will happen on the road is 5. 
Example 2:

Input: directions = "LLRR"
Output: 0
Explanation:
No cars will collide with each other. Thus, the total number of collisions that will happen on the road is 0.
 

Constraints:

1 <= directions.length <= 105
directions[i] is either 'L', 'R', or 'S'.
*/

/*
--------------------------------------------
💡 Approach
--------------------------------------------
We simulate collisions without actually modifying the string.

Key Observations:
1. Cars moving **'L'** at the beginning never collide → remove leading 'L's.
2. Cars moving **'R'** at the end never collide → remove trailing 'R's.
3. All remaining cars between the trimmed boundaries will **eventually collide**, 
   except 'S' (already stationary).

Thus, after trimming:
    - Every 'L' or 'R' inside contributes exactly 1 collision.
    - 'S' contributes 0.

So simply count all non-'S' cars in the valid middle segment.

--------------------------------------------
💡 Intuition
--------------------------------------------
Cars that move outward (leftmost 'L' or rightmost 'R') never meet another car.
Everything else must eventually hit something (either a stopped car or
opposite-direction car). Therefore collisions = count of non-'S' vehicles
between the first non-'L' and last non-'R'.

--------------------------------------------
⏳ Time Complexity
--------------------------------------------
O(n) — only single pass scanning.

--------------------------------------------
💾 Space Complexity
--------------------------------------------
O(1) — no extra storage.

--------------------------------------------
*/

class Solution {
public:
    int countCollisions(string directions) {
        int i = 0, j = directions.length() - 1;
        int ans = 0;

        // Skip all leading 'L' since they never collide
        while (i <= j && directions[i] == 'L') {
            i++;
        }

        // Skip all trailing 'R' since they never collide
        while (j >= i && directions[j] == 'R') {
            j--;
        }

        // Count all non-'S' characters in between
        // Each 'L' or 'R' here causes exactly 1 collision
        while (i <= j) {
            if (directions[i] != 'S') {
                ans++;
            }
            i++;
        }

        return ans;
    }
};
