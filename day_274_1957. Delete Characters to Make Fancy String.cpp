/*
1957. Delete Characters to Make Fancy String
Easy
Topics
Companies
Hint
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
*/

/*
Approach:
1. Traverse the input string `s` and build a new string `ans` to avoid three consecutive identical characters.
2. Start by adding the first character of `s` to `ans` and initialize a counter `cnt` to track consecutive occurrences.
3. For each subsequent character in `s`:
   - If it is the same as the previous character, check if `cnt` is less than 2:
     - If true, append the character to `ans` and increment `cnt`.
     - If `cnt` is 2 or more, skip adding this character to `ans`.
   - If it is different from the previous character, reset `cnt` to 1 and add the character to `ans`.
4. Return the resulting string `ans` after processing all characters in `s`.

Time Complexity: O(n), where `n` is the length of the string `s`.
Space Complexity: O(n), for storing the result in `ans`.
*/

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";       // Result string
        ans += s[0];           // Initialize `ans` with the first character
        int cnt = 1;           // Counter for consecutive characters
        int n = s.length();

        // Traverse the string starting from the second character
        for (int i = 1; i < n; i++) {
            // If the current character is the same as the previous one
            if (s[i] == s[i - 1]) {
                if (cnt < 2) {
                    ans += s[i];  // Add it to `ans` if we haven't reached three consecutive yet
                }
                cnt++;  // Increment consecutive count
            } else {
                // Different character found, reset counter and add to `ans`
                ans += s[i];
                cnt = 1;
            }
        }

        return ans;
    }
};
