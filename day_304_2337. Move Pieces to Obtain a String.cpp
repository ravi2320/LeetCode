/*
2337. Move Pieces to Obtain a String
Solved
Medium
Topics
Companies
Hint
You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.

 

Example 1:

Input: start = "_L__R__R_", target = "L______RR"
Output: true
Explanation: We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to "L___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___R".
- Move the second piece three steps to the right, start becomes equal to "L______RR".
Since it is possible to get the string target from start, we return true.
Example 2:

Input: start = "R_L_", target = "__LR"
Output: false
Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
Example 3:

Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
 

Constraints:

n == start.length == target.length
1 <= n <= 105
start and target consist of the characters 'L', 'R', and '_'.
*/

/*
Approach:
1. The problem involves determining if the string `start` can be transformed into `target` by moving 'L' and 'R' while following specific rules:
   - 'L' can only move left.
   - 'R' can only move right.
   - '_' represents empty spaces that can be freely filled.

2. Key Observations:
   - The relative order of 'L' and 'R' must remain the same in `start` and `target`.
   - For 'L', the position in `start` must be greater than or equal to its position in `target` (as it moves left).
   - For 'R', the position in `start` must be less than or equal to its position in `target` (as it moves right).

3. Two-pointer Technique:
   - Use two pointers `i` and `j` to iterate through `start` and `target`.
   - Skip '_' in both strings.
   - Ensure the characters match and the movement constraints are satisfied.

Steps:
1. Traverse `start` and `target` using `i` and `j`.
2. Skip all '_' characters in both strings.
3. Check if the characters at `i` and `j` are the same. If not, return false.
4. Check movement constraints:
   - For 'L', `i` must be greater than or equal to `j`.
   - For 'R', `i` must be less than or equal to `j`.
5. If the traversal ends without issues, return true.

Time Complexity:
- **O(n)**: Single pass through both strings of length `n`.

Space Complexity:
- **O(1)**: Constant space used.

*/

class Solution {
public:
    bool canChange(string start, string target) {
        int n = target.length();
        int i = 0, j = 0;

        // Traverse both strings with two pointers
        while (i < n || j < n) {
            // Skip underscores in `start`
            while (i < n && start[i] == '_') {
                i++;
            }

            // Skip underscores in `target`
            while (j < n && target[j] == '_') {
                j++;
            }

            // Check if both pointers have reached the end
            if (i == n || j == n) {
                return i == n && j == n; // Ensure both are at the end simultaneously
            }

            // Check if characters at current positions match
            if (start[i] != target[j]) {
                return false;
            }

            // Movement constraints for 'L' and 'R'
            if (start[i] == 'L' && i < j) { // 'L' cannot move right
                return false;
            }

            if (start[i] == 'R' && i > j) { // 'R' cannot move left
                return false;
            }

            // Move both pointers forward
            i++, j++;
        }

        return true; // If traversal completes without issues
    }
};
