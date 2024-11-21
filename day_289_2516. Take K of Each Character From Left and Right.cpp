/*
2516. Take K of Each Character From Left and Right
Solved
Medium
Topics
Companies
Hint
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

 

Example 1:

Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation: 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.
Example 2:

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.
 

Constraints:

1 <= s.length <= 105
s consists of only the letters 'a', 'b', and 'c'.
0 <= k <= s.length
*/

/*
Approach:
1. We need to determine the minimum number of characters to remove from the string `s` such that each of the characters 'a', 'b', and 'c' appears at least `k` times.
2. First, we calculate the frequency of 'a', 'b', and 'c' in the string. If any of these frequencies are less than `k`, it's impossible to meet the condition, so we return -1.
3. The goal is to find the longest valid substring that maintains at least `k` occurrences for each character when the substring is removed. To do this:
   - Use a sliding window approach with two pointers (`i` and `j`).
   - Adjust the window such that the characters outside the window meet the requirement.
   - Track the maximum length of the valid substring.

Time Complexity:
- O(n) — Each character is processed a constant number of times.

Space Complexity:
- O(1) — We only use a fixed-size frequency vector.

*/

class Solution {
public:
    // Function to find the minimum number of characters to remove to meet the condition
    int takeCharacters(string s, int k) {
        // Frequency vector to count occurrences of 'a', 'b', 'c'
        vector<int> freq(3, 0);

        // Count the frequency of each character in the string
        for (char &x : s) {
            freq[x - 'a']++;
        }

        // If any character frequency is less than `k`, return -1 as it's not possible
        if (freq[0] < k || freq[1] < k || freq[2] < k) {
            return -1;
        }

        // Sliding window variables
        int i = 0, j = 0, maxLen = 0;
        int n = s.length();

        // Start sliding window approach
        while (j < n) {
            // Reduce the frequency of the current character as it's included in the window
            freq[s[j] - 'a']--;

            // Adjust the window from the left if any character's count goes below `k`
            while (i < j && (freq[0] < k || freq[1] < k || freq[2] < k)) {
                freq[s[i++] - 'a']++;
            }

            // If the current window is valid, update the maximum length
            if (freq[0] >= k && freq[1] >= k && freq[2] >= k) {
                maxLen = max(maxLen, j - i + 1);
            }

            // Expand the window
            j++;
        }

        // The result is the length of the entire string minus the maximum valid substring length
        return n - maxLen;
    }
};
