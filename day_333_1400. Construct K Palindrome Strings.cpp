/*
1400. Construct K Palindrome Strings
Solved
Medium
Topics
Companies
Hint
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= 105
*/

/*
Approach:
1. Count the frequency of each character in the string using a frequency array.
2. Determine the number of characters with odd frequencies (`cnt`).
3. To construct `k` palindrome substrings:
   - A single palindrome can contain at most one character with an odd frequency.
   - If `cnt > k`, it's impossible to divide the string into `k` palindromes.
4. Return true if the number of odd frequencies (`cnt`) is less than or equal to `k` and `k <= n` (length of the string).

Intuition:
- A valid palindrome can have at most one character with an odd frequency (in the center).
- The total number of odd-frequency characters must be less than or equal to the number of required palindromes.

Time Complexity:
- \(O(n + 26)\): \(O(n)\) for counting frequencies and \(O(26)\) for checking odd frequencies (constant).

Space Complexity:
- \(O(1)\): A fixed-size frequency array of size 26 is used.

Edge Cases:
1. \(k > n\): Impossible to form \(k\) palindromes, return false.
2. \(k = n\): Each character forms a palindrome, return true.
3. \(k = 1\): The whole string must be a palindrome.

*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26, 0);  // Frequency array to count character occurrences
        int n = s.length();      // Length of the string
        
        // If more palindromes are required than the string length, return false
        if (k > n) return false;

        // Count the frequency of each character in the string
        for (char &x : s) {
            freq[x - 'a']++;
        }

        int cnt = 0;  // Count of characters with odd frequencies

        // Count the number of characters with odd frequencies
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                cnt++;
            }
        }

        // A valid partition into `k` palindromes is possible if `cnt <= k`
        return cnt <= k;
    }
};