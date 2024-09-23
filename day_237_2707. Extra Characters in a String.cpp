/*
2707. Extra Characters in a String
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

 

Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
 

Constraints:

1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words
*/

/*
 * Approach:
 * 1. The problem is to minimize the number of extra characters left after decomposing the string `s` using words from the dictionary.
 * 2. We use dynamic programming (DP) to solve this problem by maintaining a DP table `t[]` where `t[i]` represents the minimum number of extra characters needed from index `i` to the end of the string.
 * 3. For each starting index `i`, we have two options:
 *    - Ignore the current character (count it as extra and move to the next).
 *    - Try to match a substring starting from `i` with words from the dictionary and solve recursively for the remaining part.
 * 4. We take the minimum of these two options to minimize the number of extra characters.
 * 5. The solution is based on exploring all substrings starting from `i` and checking if they exist in the dictionary.
 *
 * Time Complexity: O(n^2), where `n` is the length of the string `s`, as we are checking all substrings.
 * Space Complexity: O(n), for the DP table and recursion stack.
 */

class Solution {
    int t[51];  // DP table to store the result for each index
public:
    // Recursive function to solve for the minimum extra characters
    int solve(int i, string s, unordered_set<string> &st, int n) {
        if (i >= n) return 0;  // Base case: If index reaches the end, no extra characters needed

        if (t[i] != -1) return t[i];  // Return cached result if already computed

        // Option 1: Ignore the current character and solve for the next one (1 extra character)
        int res = 1 + solve(i + 1, s, st, n);

        // Option 2: Try to match substrings starting from index `i` with dictionary words
        for (int j = i; j < n; j++) {
            string curr = s.substr(i, j - i + 1);  // Current substring
            if (st.count(curr)) {  // If the substring is in the dictionary
                res = min(res, solve(j + 1, s, st, n));  // Solve recursively for the next index
            }
        }

        return t[i] = res;  // Cache the result and return
    }

    // Main function to compute the minimum number of extra characters
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> st(dict.begin(), dict.end());  // Store the dictionary in a set for fast lookup
        int n = s.length();
        memset(t, -1, sizeof(t));  // Initialize the DP table with -1

        // Start the recursive solution from index 0
        return solve(0, s, st, n);   
    }
};


/*
 * Approach:
 * 1. This solution involves finding the minimum number of extra characters when trying to break a string `s` into words from a dictionary.
 * 2. There are two approaches used here:
 *    - **Top-Down Approach** (Recursive + Memoization): Recursively break down the problem by checking all substrings and memoize the results.
 *    - **Bottom-Up Approach** (Tabulation): Build the solution from the end of the string to the start using a dynamic programming table.
 * 3. The goal is to minimize the number of extra characters that cannot be matched with any dictionary word.
 * 4. The solution iterates over all possible substrings from each index and checks if it's present in the dictionary.
 *
 * Time Complexity: O(n^2), where `n` is the length of the string `s`. We are iterating over all substrings.
 * Space Complexity: O(n), for the DP table and recursion stack.
 */

class Solution {
    int t[51];  // DP table for memoization in top-down approach

public:
    // Top-Down Approach: Recursive + Memoization
    int solve(int i, string s, unordered_set<string> &st, int n) {
        if (i >= n) return 0;  // Base case: If index reaches the end, no extra characters

        if (t[i] != -1) return t[i];  // Return cached result if already computed

        // Option 1: Ignore current character and move to the next (1 extra character)
        int res = 1 + solve(i + 1, s, st, n);

        // Option 2: Try to match substrings starting from index `i` with dictionary words
        for (int j = i; j < n; j++) {
            string curr = s.substr(i, j - i + 1);  // Current substring
            if (st.count(curr)) {  // If the substring exists in the dictionary
                res = min(res, solve(j + 1, s, st, n));  // Recurse for the next index
            }
        }

        return t[i] = res;  // Cache and return result
    }

    // Bottom-Up Approach: Tabulation
    int solveTab(string s, vector<string>& dict) {
        unordered_set<string> st(dict.begin(), dict.end());  // Set for quick dictionary lookup
        memset(t, 0, sizeof(t));  // Initialize DP table to zero
        int n = s.length();

        // Fill the DP table from the end of the string
        for (int i = n - 1; i >= 0; i--) {
            // Option 1: Count the current character as extra
            t[i] = 1 + t[i + 1];

            // Option 2: Try matching substrings starting from index `i`
            for (int j = i; j < n; j++) {
                string curr = s.substr(i, j - i + 1);  // Current substring
                if (st.count(curr)) {  // If substring exists in dictionary
                    t[i] = min(t[i], t[j + 1]);  // Take minimum of current and found substring match
                }
            }
        }

        return t[0];  // Return the result starting from index 0
    }

    // Main function to calculate minimum extra characters
    int minExtraChar(string s, vector<string>& dict) {
        // Use the tabulation approach to solve
        return solveTab(s, dict);
    }
};
