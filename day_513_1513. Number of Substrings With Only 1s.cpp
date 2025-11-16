/*
1513. Number of Substrings With Only 1s

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.
Example 2:

Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.
Example 3:

Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
*/

// Intuition:
// The problem asks us to find the number of substrings in the given binary string
// such that the substring contains at most one '0'. The output should be 
// returned modulo 10^9 + 7.
// This is a sliding window problem where we maintain a window of substrings that 
// contains at most one '0'. For each such valid substring, we count how many 
// substrings can be formed using the current window and keep adding them to the answer.
//
// Approach:
// 1. Use two pointers `i` and `j` to maintain a sliding window on the string. 
//    `i` is the left pointer, and `j` is the right pointer.
// 2. Traverse the string with the right pointer `j`. Whenever a '0' is encountered,
//    increase the count of zeros (`zeroCnt`).
// 3. If the count of zeros exceeds 1, move the left pointer `i` to shrink the window 
//    until there is at most one '0' in the window.
// 4. For every position of `j`, the number of valid substrings that end at `j` is 
//    `(j - i + 1)` because the substring starting from `i` to `j` is valid, 
//    and there are `(j - i + 1)` such substrings.
// 5. Sum up all valid substrings and return the result modulo 10^9 + 7.

// Time Complexity: O(n)
// - We use a sliding window approach where both `i` and `j` traverse the string once.
// - The overall time complexity is O(n), where n is the length of the string `s`.


// Space Complexity: O(1)
// - The space complexity is O(1) because we are only using a few variables 
//   (`i`, `j`, `zeroCnt`, `ans`), which do not depend on the size of the input string.

class Solution {
public:
    // Function to find the number of substrings containing at most one '0'
    int numSub(string s) {
        int n = s.length();   // Length of the string
        int i = 0, j = 0;     // Left and right pointers for the sliding window
        int ans = 0;          // Variable to store the total number of valid substrings
        int zeroCnt = 0;      // Counter to track the number of '0's in the window
        int mod = 1e9 + 7;    // Modulo value to avoid overflow

        // Start sliding the right pointer
        while (j < n) {
            // If the current character is '0', increment the zero count
            if (s[j] == '0') 
                zeroCnt++;

            // If the window contains more than 1 '0', move the left pointer `i`
            // to shrink the window and maintain at most one '0'
            while (i < n && zeroCnt > 1) {
                if (s[i] == '0')
                    zeroCnt--;   // Decrease the zero count if we are moving past a '0'
                i++;  // Shrink the window from the left
            }

            // Now the window [i, j] contains at most one '0'. The number of valid 
            // substrings ending at index `j` is (j - i + 1)
            ans = (ans % mod + (j - i + 1)) % mod;

            // Move the right pointer `j` to the next position
            j++;
        }

        // Return the total number of valid substrings modulo 10^9 + 7
        return ans;
    }
};