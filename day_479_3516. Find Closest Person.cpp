/*
3516. Find Closest Person
Solved

avatar
Discuss Approach
arrow-up
Easy
Topics
premium lock icon
Companies
Hint
You are given three integers x, y, and z, representing the positions of three people on a number line:

x is the position of Person 1.
y is the position of Person 2.
z is the position of Person 3, who does not move.
Both Person 1 and Person 2 move toward Person 3 at the same speed.

Determine which person reaches Person 3 first:

Return 1 if Person 1 arrives first.
Return 2 if Person 2 arrives first.
Return 0 if both arrive at the same time.
Return the result accordingly.

 

Example 1:

Input: x = 2, y = 7, z = 4

Output: 1

Explanation:

Person 1 is at position 2 and can reach Person 3 (at position 4) in 2 steps.
Person 2 is at position 7 and can reach Person 3 in 3 steps.
Since Person 1 reaches Person 3 first, the output is 1.

Example 2:

Input: x = 2, y = 5, z = 6

Output: 2

Explanation:

Person 1 is at position 2 and can reach Person 3 (at position 6) in 4 steps.
Person 2 is at position 5 and can reach Person 3 in 1 step.
Since Person 2 reaches Person 3 first, the output is 2.

Example 3:

Input: x = 1, y = 5, z = 3

Output: 0

Explanation:

Person 1 is at position 1 and can reach Person 3 (at position 3) in 2 steps.
Person 2 is at position 5 and can reach Person 3 in 2 steps.
Since both Person 1 and Person 2 reach Person 3 at the same time, the output is 0.

 

Constraints:

1 <= x, y, z <= 100
*/

/*
Approach:
1. Compute the absolute difference between `x` and `z` → diff1.
2. Compute the absolute difference between `y` and `z` → diff2.
3. Compare the two differences:
   - If diff1 < diff2 → `x` is closer, return 1.
   - If diff2 < diff1 → `y` is closer, return 2.
   - If both are equal, return 0 (indicating a tie).

Intuition:
We need to determine which of the two values `x` or `y` is closer to a target value `z`.  
By directly computing the absolute differences and comparing them, we can efficiently find the closest number.

Time Complexity: O(1) → Only a constant number of arithmetic and comparison operations.  
Space Complexity: O(1) → Only a few integer variables are used.
*/

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff1 = abs(x - z); // distance between x and z
        int diff2 = abs(y - z); // distance between y and z

        if(diff1 < diff2) {
            return 1; // x is closer
        }
        else if(diff2 < diff1) {
            return 2; // y is closer
        }

        return 0; // both are equally close
    }
};
