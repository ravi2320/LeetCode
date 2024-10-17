/*
131. Palindrome Partitioning
Solved
Medium
Topics
Companies
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

/*
Approach:
- The problem is about partitioning a string such that every substring in the partition is a palindrome.
- We use backtracking to explore all possible partitions of the string and check if each partition is a valid palindrome.
- The function `isPalindrome` checks if a substring is a palindrome.
- The backtracking function `backtrack` recursively partitions the string and adds valid palindromic substrings to the current partition.
- The base case for backtracking is when the entire string has been processed, and we push the current partition into the result.

Time Complexity:
- O(n * 2^n), where `n` is the length of the string.
  - The backtracking function explores all possible partitions (which is 2^n in the worst case).
  - For each partition, checking if the substrings are palindromes takes O(n).

Space Complexity:
- O(n), where `n` is the depth of the recursive call stack (in the worst case, every character forms a partition).
*/

class Solution {
public:
    int n;

    // Function to check if the substring s[l:r] is a palindrome
    bool isPalindrome(string &s, int l, int r) {
        // Compare characters from both ends towards the center
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    // Backtracking function to find all palindrome partitions
    void backtrack(string &s, int idx, vector<string> &curr, vector<vector<string>> &result) {
        // If we've reached the end of the string, add the current partition to the result
        if (idx == n) {
            result.push_back(curr);
            return;
        }

        // Try all possible partitions starting from index `idx`
        for (int i = idx; i < n; i++) {
            // If the substring from `idx` to `i` is a palindrome
            if (isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));  // Add the substring to the current partition
                backtrack(s, i + 1, curr, result);  // Recurse to partition the remaining string
                curr.pop_back();  // Backtrack and remove the last substring from the current partition
            }
        }
    }

    // Function to return all palindrome partitions of the string `s`
    vector<vector<string>> partition(string s) {
        n = s.length();  // Length of the input string
        vector<vector<string>> result;  // To store the final result
        vector<string> curr;  // To store the current partition
        backtrack(s, 0, curr, result);  // Start backtracking from index 0
        return result;  // Return the result containing all partitions
    }
};
