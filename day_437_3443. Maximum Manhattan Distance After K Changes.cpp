/*
3443. Maximum Manhattan Distance After K Changes

Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:

'N' : Move north by 1 unit.
'S' : Move south by 1 unit.
'E' : Move east by 1 unit.
'W' : Move west by 1 unit.
Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.

Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.

The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
 

Example 1:

Input: s = "NWSE", k = 1

Output: 3

Explanation:

Change s[2] from 'S' to 'N'. The string s becomes "NWNE".

Movement	Position (x, y)	Manhattan Distance	Maximum
s[0] == 'N'	(0, 1)	0 + 1 = 1	1
s[1] == 'W'	(-1, 1)	1 + 1 = 2	2
s[2] == 'N'	(-1, 2)	1 + 2 = 3	3
s[3] == 'E'	(0, 2)	0 + 2 = 2	3
The maximum Manhattan distance from the origin that can be achieved is 3. Hence, 3 is the output.

Example 2:

Input: s = "NSWWEW", k = 3

Output: 6

Explanation:

Change s[1] from 'S' to 'N', and s[4] from 'E' to 'W'. The string s becomes "NNWWWW".

The maximum Manhattan distance from the origin that can be achieved is 6. Hence, 6 is the output.

 

Constraints:

1 <= s.length <= 105
0 <= k <= s.length
s consists of only 'N', 'S', 'E', and 'W'.
*/

/*
Approach:
We are given a string `s` of directions (N, S, E, W), and an integer `k` which allows us to make up to `k`
modifications (each modification can change one character to any other direction). Our goal is to find the 
**maximum possible Manhattan Distance** from the origin at any prefix of the string (after at most `k` changes).

Steps:
1. Traverse each prefix of the string up to index `i`.
2. Maintain counts of directions (E, W, N, S).
3. Compute current Manhattan Distance: abs(E-W) + abs(N-S).
4. Compute how many steps were "wasted": steps - distance.
5. You can use up to `2*k` to compensate wasted steps (each change can reduce the waste by 2).
6. Final distance = current distance + min(wasted, 2*k).
7. Track the maximum such distance across all prefixes.

Intuition:
Changes can be used to maximize the Manhattan distance. At most 2 units of distance can be gained per change
because one wrong direction (like canceling out a movement) can be turned into a helping one.

Time Complexity: O(n)
- Single pass through the string with constant-time operations

Space Complexity: O(1)
- Only counters used
*/

class Solution {
public:
    int maxDistance(string s, int k) {
        int east = 0, west = 0, north = 0, south = 0;
        int n = s.length();
        int maxMD = 0;

        for (int i = 0; i < n; i++) {
            // Update direction counts
            if (s[i] == 'E') east++;
            else if (s[i] == 'W') west++;
            else if (s[i] == 'N') north++;
            else if (s[i] == 'S') south++;

            int steps = i + 1;  // Number of steps so far
            int currMD = abs(east - west) + abs(north - south);  // Current Manhattan Distance
            int wasted = steps - currMD;  // Steps not contributing to distance

            // You can increase distance using at most 2*k "helpful" steps
            int extra = min(2 * k, wasted);
            int finalMD = currMD + extra;

            maxMD = max(maxMD, finalMD);  // Update max distance
        }

        return maxMD;
    }
};
