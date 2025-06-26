/*
2311. Longest Binary Subsequence Less Than or Equal to K

Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

Note:

The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 

Example 1:

Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.
Example 2:

Input: s = "00101001", k = 1
Output: 6
Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.
 

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
1 <= k <= 109
*/

/*
Approach:
We are given a binary string `s` and an integer `k`. The goal is to find the **length of the longest subsequence** of `s` 
that, when interpreted as a binary number, has a value less than or equal to `k`.

Strategy:
1. We traverse from the right end of the string (least significant bit).
2. We can **always include '0'**, as it doesn’t increase the binary value.
3. We can include '1' **only if** adding `2^power` does not exceed `k`.
   - We maintain the cumulative value and power.
4. Stop if the value exceeds `k` or power exceeds 31 (to avoid overflow).

Intuition:
Including more '0's helps build longer subsequences without increasing the numeric value. '1's are selectively included 
based on whether they push the binary value over `k`.

Time Complexity: O(n)
- We iterate the string once from right to left.

Space Complexity: O(1)
- Only constant variables used.

Note: The input string contains only '0' and '1'.
*/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int count = 0;       // Count of characters included in the subsequence
        int value = 0;       // Current binary value of the chosen subsequence
        int power = 0;       // Power of 2 corresponding to current position

        // Traverse from the end (least significant bit)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                count++; // Always include '0' since it doesn't increase the value
            } else {
                // Try to include '1' if its contribution doesn't exceed k
                if (power < 31 && value + (1 << power) <= k) {
                    value += (1 << power);
                    count++;
                }
            }
            power++;
        }

        return count;
    }
};
