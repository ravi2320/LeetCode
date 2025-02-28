/*
1092. Shortest Common Supersequence 
Solved
Hard
Topics
Companies
Hint
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

/**
 * Approach:
 * 1️⃣ **Recursive DP (Memoization)**:
 *    - `dp[i][j]` stores the length of SCS for `s1[i..n]` and `s2[j..m]`.
 *    - If characters match, take the diagonal move.
 *    - Otherwise, choose the minimum of adding `s1[i]` or `s2[j]`.
 *
 * 2️⃣ **Reconstruct the SCS String**:
 *    - Traverse `dp` from `(0,0)` to `(n,m)`, picking characters accordingly.
 *    - Append remaining characters if one string is exhausted.
 *
 * 🔹 **Time Complexity**: O(N * M) → Memoization avoids redundant computations.
 * 🔹 **Space Complexity**: O(N * M) → Memoization table.
 */

class Solution {
    int n, m;
public:
    // Recursive function to compute length of SCS
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (dp[i][j] != -1) return dp[i][j];

        if (i == n) return dp[i][j] = m - j;  // If s1 is exhausted, add remaining s2
        if (j == m) return dp[i][j] = n - i;  // If s2 is exhausted, add remaining s1

        if (s1[i] == s2[j])  // If characters match, move diagonally
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);

        int takeS1 = 1 + solve(i + 1, j, s1, s2, dp);  // Choose s1[i]
        int takeS2 = 1 + solve(i, j + 1, s1, s2, dp);  // Choose s2[j]

        return dp[i][j] = min(takeS1, takeS2);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        // Compute dp table
        solve(0, 0, str1, str2, dp);

        // Build the actual SCS string
        string ans = "";
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (str1[i] == str2[j]) {  
                ans.push_back(str1[i]);  // Take the common character
                i++, j++;
            } else {  
                if (dp[i + 1][j] < dp[i][j + 1]) {  
                    ans.push_back(str1[i]);  // Choose from str1
                    i++;
                } else {  
                    ans.push_back(str2[j]);  // Choose from str2
                    j++;
                }
            }
        }

        // Append remaining characters if one string is exhausted
        if (i < n) ans += str1.substr(i);
        if (j < m) ans += str2.substr(j);

        return ans;
    }
};


/**
 * Approach:
 * 1️⃣ **Dynamic Programming (Bottom-Up)**:
 *    - Use a **2D DP table** where `dp[i][j]` stores the length of the SCS
 *      for the first `i` characters of `str1` and `j` characters of `str2`.
 *    - If `str1[i-1] == str2[j-1]`, take diagonal move (`dp[i-1][j-1] + 1`).
 *    - Otherwise, take the minimum of left (`dp[i-1][j] + 1`) or top (`dp[i][j-1] + 1`).
 *
 * 2️⃣ **Reconstructing the SCS**:
 *    - Start from `dp[n][m]` and move **backward**.
 *    - If characters match, move diagonally.
 *    - Otherwise, choose the smaller value (left or top) and append the corresponding character.
 *    - Append any **remaining** characters from `str1` or `str2`.
 *    - **Reverse** the string to get the correct order.
 *
 * 🔹 **Time Complexity**: O(N * M) → Filling and reconstructing `dp` table.
 * 🔹 **Space Complexity**: O(N * M) → Storing the `dp` table.
 */

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Filling the DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;  // Base case: If one string is empty
                } else if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];  // Characters match → take diagonal
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);  // Choose min from left or top
                }
            }
        }

        // Reconstructing the shortest common supersequence
        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {  
                ans.push_back(str1[i - 1]);  // Common character → move diagonally
                i--, j--;
            } else {
                if (dp[i - 1][j] < dp[i][j - 1]) {  
                    ans.push_back(str1[i - 1]);  // Choose from str1
                    i--;
                } else {  
                    ans.push_back(str2[j - 1]);  // Choose from str2
                    j--;
                }
            }
        }

        // Append remaining characters
        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());  // Reverse to get the correct order

        return ans;
    }
};