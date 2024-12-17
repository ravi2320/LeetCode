/*
2182. Construct String With Repeat Limit
Solved
Medium
Topics
Companies
Hint
You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

 

Example 1:

Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
Example 2:

Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
 

Constraints:

1 <= repeatLimit <= s.length <= 105
s consists of lowercase English letters.
*/

/*
Approach:
1. Use a frequency array to count the occurrence of each character in the string `s`.
2. Start from the highest frequency character (lexicographically largest).
3. Add characters to the result string while ensuring the `repeatLimit` constraint:
   - Append the current character up to `repeatLimit` times.
   - If more instances of the character remain, insert the next largest available character to avoid violating the limit.
4. Continue the process until no characters are left or further additions are impossible.

Steps:
1. Count the frequency of all characters using a vector of size 26.
2. Traverse the characters in descending order (from 'z' to 'a') and append up to `repeatLimit` occurrences.
3. If the current character's frequency exceeds the limit, find the next valid character and append it to the result.
4. Repeat the process until all valid characters are processed.

Time Complexity:
- O(n): Counting the frequency of characters.
- O(26 * n) ≈ O(n): Processing the characters up to `repeatLimit` times.
- Total: O(n).

Space Complexity:
- O(26): For the frequency array.

Edge Cases:
- The string `s` has a single character.
- `repeatLimit` is 1.
- Characters in `s` are already sorted or all identical.

*/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0); // Frequency array for 26 letters

        // Count the frequency of each character
        for (char &x : s) {
            freq[x - 'a']++;
        }

        int i = 25;      // Start with the largest character ('z')
        string res = ""; // Resultant string

        while (i >= 0) {
            // Skip characters with zero frequency
            if (freq[i] == 0) {
                i--;
                continue;
            }

            char ch = 'a' + i;                 // Current character
            int cnt = min(freq[i], repeatLimit); // Add up to `repeatLimit` occurrences
            res += string(cnt, ch);
            freq[i] -= cnt;

            // If there are still remaining characters to process
            if (freq[i] > 0) {
                int j = i - 1;

                // Find the next valid character with a non-zero frequency
                while (j >= 0 && freq[j] == 0) {
                    j--;
                }

                // If no smaller character is available, break
                if (j < 0) break;

                res += ('a' + j); // Append the next smaller character
                freq[j]--;
            }
        }

        return res;
    }
};
