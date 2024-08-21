/*
664. Strange Printer
Solved
Hard
Topics
Companies
There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

 

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.
*/

/*
Intuition:
- The problem is about minimizing the number of turns a strange printer needs to print a given string.
- The strange printer can print a contiguous substring of the same character in one turn. The goal is to minimize the total number of turns needed to print the entire string.
- To solve this, we can use dynamic programming. The idea is to break the problem into subproblems where we consider the minimum number of turns needed to print the substring `s[l...r]`.
- If the first character `s[l]` repeats further in the substring, we have an opportunity to merge printing operations, reducing the number of turns required.

Time Complexity:
- The time complexity is `O(n^3)`, where `n` is the length of the string. This is because we have `O(n^2)` subproblems and for each subproblem, we might iterate through the substring, leading to an additional `O(n)` factor.

Space Complexity:
- The space complexity is `O(n^2)` for the `dp` table `t`, where `t[l][r]` stores the minimum number of turns needed to print the substring `s[l...r]`.

*/

class Solution {
    int n;
    int t[101][101]; // DP table to store results of subproblems

public:
    // Helper function to find the minimum number of turns to print s[l...r]
    int solve(int l, int r, string &s) {
        
        if (l == r) return 1; // Base case: A single character needs exactly one turn to print

        if (l > r) return 0; // Invalid case

        if (t[l][r] != -1) { // If the subproblem is already solved, return the stored result
            return t[l][r];
        }

        int i = l + 1; 
        while (i <= r && s[i] == s[l]) // Skip over contiguous characters that are the same as s[l]
            i++;

        if (i == r + 1) // If the entire substring from l to r is the same character
            return 1;

        // Basic case: Assume we need one turn to print s[l...i-1] and then solve the rest
        int basic = 1 + solve(i, r, s);

        // `lalach` means 'greed' in Hindi. Here it represents the optimal (minimum) solution found.
        int lalach = INT_MAX;

        // Try to merge printing operations if s[j] matches s[l] at any position j in s[i...r]
        for (int j = i; j <= r; j++) {
            if (s[j] == s[l]) {
                int ans = solve(i, j - 1, s) + solve(j, r, s);
                lalach = min(ans, lalach);
            }
        }

        // The optimal solution for the subproblem s[l...r] is the minimum of the basic and greedy solutions
        return t[l][r] = min(basic, lalach);
    }

    int strangePrinter(string s) {
        n = s.length();
        memset(t, -1, sizeof(t)); // Initialize the DP table with -1
        return solve(0, n - 1, s); // Solve the problem for the entire string s[0...n-1]
    }
};
