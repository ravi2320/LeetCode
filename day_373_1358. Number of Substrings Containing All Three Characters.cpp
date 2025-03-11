/*
1358. Number of Substrings Containing All Three Characters
Solved
Medium
Topics
Companies
Hint
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

/**
 * Approach:
 * - Use a **sliding window** with two pointers (`i` and `j`).
 * - Maintain a **frequency array `freq[3]`** for 'a', 'b', and 'c'.
 * - Expand `j` to include characters until all three ('a', 'b', 'c') are present.
 * - Shrink `i` while the condition holds, and **count valid substrings**.
 * 
 * 🔹 **Time Complexity**: O(N) → Two-pointer traversal.
 * 🔹 **Space Complexity**: O(1) → Fixed size frequency array (3 elements).
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> freq(3, 0); // Frequency array for 'a', 'b', 'c'
        int i = 0, j = 0, result = 0;

        // Sliding window approach
        while (j < n) {
            freq[s[j] - 'a']++; // Include character in the window

            // Shrink window if all 'a', 'b', and 'c' are present
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                result += n - j; // Count valid substrings from (i, j) to (i, n-1)
                freq[s[i] - 'a']--; // Remove `s[i]` from window
                i++; // Move left pointer
            }

            j++; // Move right pointer
        }

        return result;
    }
};
