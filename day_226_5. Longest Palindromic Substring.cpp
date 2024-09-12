/*
5. Longest Palindromic Substring
Solved
Medium
Topics
Companies
Hint
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

/*
Approach:
1. The task is to find the longest palindromic substring in a given string `s`.
2. A palindrome reads the same forwards and backwards.
3. We use dynamic programming to check if a substring is a palindrome by recursively comparing the characters at the ends and checking if the inner substring is also a palindrome.
4. The `solve` function is a helper that uses memoization to store results for substrings that have already been checked, reducing redundant computations.
5. For each pair of indices `(i, j)`, if the substring `s[i..j]` is a palindrome and its length is greater than the current longest palindrome, we update the starting point `sp` and the maximum length `maxLen`.

Time Complexity:
- O(n^3): We check all substrings, and for each substring, we recursively check for palindrome validity. The recursive calls can take linear time due to the nature of the problem.

Space Complexity:
- O(n^2): The `dp` table stores results for each substring, and it requires O(n^2) space.

*/

class Solution {
public:
    // Recursive function to check if the substring s[i..j] is a palindrome
    bool solve(string &s, int i, int j, vector<vector<int>> &dp) {
        // Base case: single character or empty string is always a palindrome
        if (i >= j) return true;

        // If we have already computed the result for this substring
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Check if the outer characters match and recursively check the inner substring
        if (s[i] == s[j]) {
            return dp[i][j] = solve(s, i + 1, j - 1, dp);
        }

        // If characters don't match, it's not a palindrome
        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int sp = 0;        // Starting point of the longest palindrome
        int maxLen = 1;    // Maximum length of the palindrome found so far
        int n = s.length();

        // DP table to store results of whether s[i..j] is a palindrome
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Check all substrings (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j, dp)) {  // If s[i..j] is a palindrome
                    if (j - i + 1 > maxLen) {  // Update if this is the longest so far
                        sp = i;                // Update starting point
                        maxLen = j - i + 1;    // Update maximum length
                    }
                }
            }
        }

        // Return the longest palindrome substring
        return s.substr(sp, maxLen);
    }
};


/*
Approach:
1. This dynamic programming solution finds the longest palindromic substring in the string `s`.
2. The DP table `dp[i][j]` is used to store whether the substring `s[i..j]` is a palindrome.
   - `dp[i][i] = 1`: Every single character is a palindrome.
   - If `s[i] == s[j]` and the substring `s[i+1..j-1]` is also a palindrome (`dp[i+1][j-1] == 1`), then `s[i..j]` is a palindrome.
   - For substrings of length 2, only the equality of `s[i] == s[j]` needs to be checked.
3. We check substrings of increasing lengths (`L`), and for each valid palindrome, we update the starting point `sp` and the maximum length `maxLen`.

Time Complexity:
- O(n^2): We iterate over all possible substrings of the string using two nested loops, and each substring check takes constant time due to DP.

Space Complexity:
- O(n^2): We use a 2D DP table to store the results for all substring checks.

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";  // Edge case: empty string

        // DP table to store whether s[i..j] is a palindrome
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        int maxLen = 1;  // Length of the longest palindrome found so far
        int sp = 0;      // Starting point of the longest palindrome

        // Check substrings of length L
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;  // Calculate the ending index based on the starting index and length
                
                // Check if the substring s[i..j] is a palindrome
                if (s[i] == s[j] && (L == 2 || dp[i+1][j-1])) {
                    dp[i][j] = 1;  // Mark this substring as a palindrome

                    // Update the longest palindrome if needed
                    if (L > maxLen) {
                        maxLen = L;
                        sp = i;
                    }
                }
            }
        }

        // Return the longest palindrome substring
        return s.substr(sp, maxLen);
    }
};
