/*
1930. Unique Length-3 Palindromic Subsequences
Solved
Medium
Topics
Companies
Hint
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
 

Constraints:

3 <= s.length <= 105
s consists of only lowercase English letters.
*/

/*
Approach:
1. Identify all unique characters in the string using an unordered_set.
2. For each unique character:
   - Find the leftmost and rightmost occurrences of the character.
   - Extract all characters that lie between these two occurrences.
   - The distinct characters between the leftmost and rightmost occurrences represent palindromic subsequences of length 3 with the current character as the first and last character.
3. Add the count of distinct middle characters to the result.
4. Return the total count.

Intuition:
A palindromic subsequence of length 3 must have the same character at the first and last position. By iterating through each unique character and counting distinct middle characters between its first and last occurrences, we ensure all such subsequences are counted efficiently.

Time Complexity:
- Identifying unique characters: \(O(N)\), where \(N\) is the length of the string.
- Iterating through each unique character and finding leftmost and rightmost indices: \(O(26 \times N) = O(N)\), as there are at most 26 unique lowercase letters.
- Calculating distinct middle characters: \(O(N)\) for each unique character.
Overall: \(O(N)\).

Space Complexity:
- Using unordered_sets for unique letters and distinct middle characters: \(O(26) + O(26) = O(1)\) as the space depends only on the alphabet size.

*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();                   // Length of the input string
        unordered_set<char> letters;          // Set to store unique characters

        // Collect all unique characters in the string
        for (int i = 0; i < n; i++) {
            letters.insert(s[i]);
        }

        int ans = 0; // Initialize the count of palindromic subsequences

        // Iterate through each unique character
        for (char letter : letters) {
            int left_idx = -1;  // Leftmost occurrence of the current character
            int right_idx = -1; // Rightmost occurrence of the current character

            // Find the leftmost and rightmost occurrences of the character
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (left_idx == -1) {
                        left_idx = i; // Update the leftmost index
                    }
                    right_idx = i;    // Update the rightmost index
                }
            }

            // Use a set to track distinct middle characters
            unordered_set<char> st;
            for (int middle_idx = left_idx + 1; middle_idx < right_idx; middle_idx++) {
                st.insert(s[middle_idx]); // Add middle characters to the set
            }

            // Add the count of distinct middle characters to the result
            ans += st.size();
        }

        return ans; // Return the total count of palindromic subsequences
    }
};


/*
Approach:
1. Use a vector of pairs to store the first and last occurrences of each character in the string.
   - For each character in the string, update its first and last occurrence indices.
2. For each character in the alphabet:
   - If the character does not appear in the string, skip it.
   - Otherwise, iterate over the substring between its first and last occurrences.
   - Use an unordered_set to count distinct characters in this substring (valid middle characters).
3. Sum up the sizes of these sets for all characters to compute the total count of palindromic subsequences.

Intuition:
To form a palindromic subsequence of length 3, the first and last characters must be the same. By identifying the first and last occurrences of each character, we efficiently focus on potential middle characters for each valid palindromic subsequence.

Time Complexity:
- Determining first and last occurrences: \(O(N)\), where \(N\) is the length of the string.
- Iterating over each character's valid range: At most \(O(N)\) across all characters.
Overall: \(O(N)\).

Space Complexity:
- Vector for indices: \(O(26)\), as we only store first and last occurrences for each character.
- Unordered_set for middle characters: At most \(O(26)\), as the alphabet size is fixed.
Overall: \(O(1)\) (constant space, independent of \(N\)).

*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Vector to store the first and last occurrences of each character
        vector<pair<int, int>> indices(26, {-1, -1});
        int n = s.length();  // Length of the string
        int ans = 0;         // Initialize count of palindromic subsequences

        // Populate the first and last occurrence indices for each character
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a'; // Map character to index (0 for 'a', 1 for 'b', etc.)
            if (indices[idx].first == -1) {
                indices[idx].first = i; // Set the first occurrence if not already set
            }
            indices[idx].second = i;    // Update the last occurrence
        }

        // Iterate through all characters in the alphabet
        for (int i = 0; i < 26; i++) {
            int left_idx = indices[i].first;  // First occurrence
            int right_idx = indices[i].second; // Last occurrence

            // If the character does not appear in the string, skip it
            if (left_idx == -1) {
                continue;
            }

            // Use a set to track distinct middle characters
            unordered_set<char> st;
            for (int middle_idx = left_idx + 1; middle_idx < right_idx; middle_idx++) {
                st.insert(s[middle_idx]); // Add each middle character to the set
            }

            // Add the count of distinct middle characters to the result
            ans += st.size();
        }

        return ans; // Return the total count of palindromic subsequences
    }
};
