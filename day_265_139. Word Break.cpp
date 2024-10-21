/*
139. Word Break
Solved
Medium
Topics
Companies
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

/*
Approach:
- The problem is to determine whether a string `s` can be segmented into one or more dictionary words.
- The algorithm uses recursion with memoization (dynamic programming) to efficiently solve the problem.
- It tries to break the string `s` into substrings and checks whether each substring exists in the given dictionary (`wordDict`).
- If a valid segmentation is found at any point, it returns true; otherwise, it returns false.

Key Steps:
1. Convert `wordDict` into a hash set (`unordered_set<string>`) for fast lookups.
2. Use a recursive function `solve()` with memoization (`dp[]`) to try all possible segmentations of `s`.
3. If the substring from the current index `i` to `j` exists in the set, recursively solve the rest of the string starting from index `j+1`.
4. Use memoization to store results for subproblems and avoid redundant computations.

Time Complexity:
- O(n^2): The outer loop runs `n` times and for each iteration, a substring comparison of length up to `n` is performed.
- Checking if a substring exists in the set takes O(1), but generating the substring takes O(n) for each call.

Space Complexity:
- O(n): The space is mainly used by the recursion stack and the memoization array (`dp[]`), where `n` is the length of the string.

*/

class Solution {
public:
    // Helper function to solve the problem using recursion and memoization
    bool solve(int i, string &s, unordered_set<string> &st, int n, vector<int> &dp) {
        
        // If we have reached the end of the string, return true (successful segmentation)
        if (i == n) {
            return true;
        }

        // If the result for the current index `i` is already computed, return it
        if (dp[i] != -1) {
            return dp[i];
        }

        // Try all substrings starting from the current index `i`
        string curr = "";
        for (int j = i; j < n; j++) {
            curr += s[j]; // Build the substring
            // Check if the substring exists in the set and recursively solve the rest
            if (st.count(curr) && solve(j + 1, s, st, n, dp)) {
                return dp[i] = true;
            }
        }

        // If no valid segmentation is found, mark it as false
        return dp[i] = false;
    }

    // Main function to check if the string can be segmented into dictionary words
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end()); // Store words in a set for O(1) lookup
        int n = s.length(); // Length of the string
        vector<int> dp(n, -1); // Memoization array initialized to -1

        // Start solving from index 0
        return solve(0, s, st, n, dp);
    }
};
