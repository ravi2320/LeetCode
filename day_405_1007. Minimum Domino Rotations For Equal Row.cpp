/*
1007. Minimum Domino Rotations For Equal Row
Solved
Medium
Topics
Companies
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= tops.length <= 2 * 104
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6
*/

/*
Intuition:
- We want all values in either the `tops` or `bottoms` array to be the same using the **minimum number of rotations**.
- A domino rotation swaps the top and bottom of the same domino.
- We try all possible values from 1 to 6 (since domino values are between 1 and 6), and for each, check:
  - Can all elements in tops/bottoms be made equal to this value?
  - If yes, compute the number of required rotations.

Approach:
1. For each candidate value `val` from 1 to 6:
   - Check whether we can make all dominoes have `val` in either the top or bottom row.
   - Track how many rotations are needed for each scenario (top-to-val or bottom-to-val).
2. Return the minimum number of such rotations if possible.

Time Complexity: O(6 * N) = O(N), where N is the number of dominoes.
Space Complexity: O(1), no extra space apart from a few variables.
*/

class Solution {
public:
    // Helper function to calculate steps needed to make all dominoes have value `val`
    int findSteps(int val, vector<int>& tops, vector<int>& bottoms){
        int n = bottoms.size();
        int bottomSteps = 0, topsSteps = 0;

        for(int i = 0; i < n; i++){
            // If neither top nor bottom has val, it's impossible
            if(tops[i] != val && bottoms[i] != val){
                return -1;
            }
            // Count how many rotations are needed to bring `val` to the top
            else if(tops[i] != val){
                topsSteps++;
            }
            // Count how many rotations are needed to bring `val` to the bottom
            else if(bottoms[i] != val){
                bottomSteps++;
            }
        }

        // Return the minimum rotations needed for either configuration
        return min(bottomSteps, topsSteps);
    }

    // Main function to find the minimum rotations needed
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX;

        // Try all possible domino values from 1 to 6
        for(int val = 1; val <= 6; val++){
            int steps = findSteps(val, tops, bottoms);
            if(steps != -1){
                res = min(res, steps);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};