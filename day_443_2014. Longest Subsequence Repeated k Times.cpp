/*
2014. Longest Subsequence Repeated k Times

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.

For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

 

Example 1:

example 1
Input: s = "letsleetcode", k = 2
Output: "let"
Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
"let" is the lexicographically largest one.
Example 2:

Input: s = "bb", k = 2
Output: "b"
Explanation: The longest subsequence repeated 2 times is "b".
Example 3:

Input: s = "ab", k = 2
Output: ""
Explanation: There is no subsequence repeated 2 times. Empty string is returned.
 

Constraints:

n == s.length
2 <= n, k <= 2000
2 <= n < k * 8
s consists of lowercase English letters.
*/

/*
Approach:
We are given a string `s` and an integer `k`, and we need to find the **longest string `t`** such that 
`t` repeated `k` times is a subsequence of `s`. The string `t` must also be the **lexicographically largest** among all such possibilities.

Strategy:
1. Count the frequency of each character in `s`.
2. If a character's frequency is less than `k`, it cannot be used in `t`.
3. For all characters with frequency >= k, try to use them up to `freq[i]/k` times.
4. Use **backtracking** to try all possible combinations of characters in decreasing lexicographical order.
   - For each combination (candidate `t`), check if repeating it `k` times forms a subsequence of `s`.
5. We use pruning via `maxLen = n / k` to avoid checking lengths that can't possibly form a valid result.

Core Checks:
- `isSubsequence`: Check if `t` repeated `k` times is a subsequence of `s`.
- `backtracking`: Try all combinations of characters that can form such a `t` of a given length.

Time Complexity:
- Exponential in worst-case for backtracking: O(26^L), where L = length of candidate subsequence.
- Subsequence checking is O(n), called multiple times.
- Acceptable due to pruning and lexicographical ordering.

Space Complexity:
- O(L): space used for current string and frequency arrays.

*/

class Solution {
    string res = ""; // To store the final result
public:
    // Helper function to check if 'sub' repeated k times is a subsequence of s
    bool isSubsequence(string &s, string &sub, int k) {
        int i = 0, j = 0;
        int L = sub.length();
        int n = s.length();

        while (i < n && j < L * k) {
            if (s[i] == sub[j % L])
                j++;
            i++;
        }

        return j == L * k;
    }

    // Backtracking function to build candidate subsequences
    bool backtracking(string &s, string &curr, vector<bool> &canUse, vector<int> &reqFreq, int k, int maxLen) {
        if (curr.length() == maxLen) {
            if (isSubsequence(s, curr, k)) {
                res = curr; // Save the result if valid
                return true;
            }
            return false;
        }

        // Try characters from 'z' to 'a' for lexicographically largest first
        for (int i = 25; i >= 0; i--) {
            if (!canUse[i] || reqFreq[i] == 0) continue;

            char ch = i + 'a';
            curr.push_back(ch);
            reqFreq[i]--;

            if (backtracking(s, curr, canUse, reqFreq, k, maxLen)) {
                return true;
            }

            // Backtrack
            curr.pop_back();
            reqFreq[i]++;
        }

        return false;
    }

    // Main function
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char &x : s) {
            freq[x - 'a']++;
        }

        vector<bool> canUse(26, false);   // Characters that can be used at least k times
        vector<int> reqFreq(26, 0);       // How many times we can use each character in 't'
        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                reqFreq[i] = freq[i] / k;
            }
        }

        int maxLen = n / k;  // Maximum length of string 't'

        // Try all lengths from maxLen down to 0
        for (int len = maxLen; len >= 0; len--) {
            vector<int> tempReqFreq = reqFreq;
            string curr = "";
            if (backtracking(s, curr, canUse, tempReqFreq, k, len)) {
                return res;
            }
        }

        return res;
    }
};
