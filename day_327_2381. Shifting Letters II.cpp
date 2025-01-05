/*
2381. Shifting Letters II
Solved
Medium
Topics
Companies
Hint
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

 

Example 1:

Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
Example 2:

Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
 

Constraints:

1 <= s.length, shifts.length <= 5 * 104
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s consists of lowercase English letters.
*/

/*
Approach:
1. Use a difference array `diff` to handle the cumulative effect of shifts efficiently.
   - For each shift operation, update the start index with the direction (`+1` for right, `-1` for left).
   - Update the position right after the end index to negate the effect beyond the range.
2. Compute the prefix sum of the `diff` array to get the net shift for each character in the string.
3. For each character in the string:
   - Apply the net shift to determine the new character.
   - Use modulo 26 to handle circular shifts within the alphabet.
   - Ensure non-negative shifts by adjusting for negative values.

Intuition:
Using a difference array allows us to apply multiple range updates efficiently without iterating over the full range for each shift operation. The prefix sum gives the cumulative effect, and modulo arithmetic ensures shifts remain within bounds.

Time Complexity:
- Updating the difference array: \(O(M)\), where \(M\) is the number of shift operations.
- Calculating the prefix sum: \(O(N)\), where \(N\) is the length of the string.
- Applying shifts to the string: \(O(N)\).
Overall: \(O(M + N)\).

Space Complexity:
- Difference array `diff`: \(O(N)\).
Overall: \(O(N)\).

*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();            // Length of the input string
        vector<int> diff(n, 0);        // Difference array for cumulative shifts

        // Process each shift operation
        for (auto &query : shifts) {
            int L = query[0];          // Start index of the shift
            int R = query[1];          // End index of the shift
            int dir = query[2];        // Direction of the shift (1 for right, 0 for left)

            // Determine shift direction
            int x = (dir == 1 ? 1 : -1);

            // Update the difference array
            diff[L] += x;
            if (R + 1 < n)
                diff[R + 1] -= x;      // Negate the effect after the range
        }

        // Compute the prefix sum to get net shifts for each character
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        // Apply the net shifts to the string
        for (int i = 0; i < n; i++) {
            int shift = diff[i] % 26;  // Net shift, modulo 26 for alphabet bounds

            // Adjust for negative shifts
            if (shift < 0) {
                shift += 26;
            }

            // Update the character after applying the shift
            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }

        return s; // Return the updated string
    }
};
