/*
2486. Append Characters to String to Make Subsequence
Solved
Medium
Topics
Companies
Hint
You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

 

Example 1:

Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
Example 2:

Input: s = "abcde", t = "a"
Output: 0
Explanation: t is already a subsequence of s ("abcde").
Example 3:

Input: s = "z", t = "abcde"
Output: 5
Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
Now, t is a subsequence of s ("zabcde").
It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
 

Constraints:

1 <= s.length, t.length <= 105
s and t consist only of lowercase English letters.
*/

// Intuition:
// - The problem involves finding how many characters need to be appended to the end of string `s` to make string `t` a subsequence of `s`.
// - To achieve this, we use two pointers to traverse both strings.
// - If characters at the current pointers in both strings match, we move both pointers forward.
// - If they don't match, we only move the pointer for string `s` forward.
// - After the traversal, the difference between the length of `t` and the number of matched characters gives us the number of characters needed to be appended.

// Time Complexity: O(n + m)
// - We traverse both strings once where `n` is the length of `s` and `m` is the length of `t`.

// Space Complexity: O(1)
// - We use a constant amount of extra space.

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0, j = 0;

        // Traverse both strings
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                j++; // Move pointer for `t` when characters match
            }
            i++; // Always move pointer for `s`
        }

        // Number of characters to append is the remaining length of `t`
        return m - j;
    }
};
