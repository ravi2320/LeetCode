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

/*
Approach:
1. Use the sliding window concept to track the last seen positions of the characters 'a', 'b', and 'c' in the string.
2. Maintain a `lastSeen` array of size 3 where:
   - `lastSeen[0]` stores the last seen index of 'a',
   - `lastSeen[1]` stores the last seen index of 'b',
   - `lastSeen[2]` stores the last seen index of 'c'.
3. For every character in the string:
   - Update its corresponding position in the `lastSeen` array.
   - The number of valid substrings ending at the current position is determined by the minimum index of the three characters.
4. Sum up the counts for all positions.

Steps:
- Initialize `lastSeen` with `-1` (as no character has been seen initially).
- For each character in the string, update its last seen index.
- Calculate the contribution of substrings ending at the current position by taking `1 + min(lastSeen[0], lastSeen[1], lastSeen[2])`.
- Accumulate this value into a running total `cnt`.

Time Complexity:
- O(n): Each character is processed once.

Space Complexity:
- O(1): Constant space for the `lastSeen` array.

Edge Cases:
- The string does not contain all three characters ('a', 'b', 'c').
- The string has a minimum valid length of 3.

*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastSeen = {-1, -1, -1}; // Stores the last seen index of 'a', 'b', and 'c'
        int cnt = 0; // Total count of valid substrings

        // Traverse the string
        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i; // Update last seen position of the current character

            // Add the count of valid substrings ending at this position
            cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }

        return cnt; // Return the total count of valid substrings
    }
};
