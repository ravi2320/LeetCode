/*
3163. String Compression III
Solved
Medium
Topics
Companies
Hint
Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.

 

Example 1:

Input: word = "abcde"

Output: "1a1b1c1d1e"

Explanation:

Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.

For each prefix, append "1" followed by the character to comp.

Example 2:

Input: word = "aaaaaaaaaaaaaabb"

Output: "9a5a2b"

Explanation:

Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.

For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
For prefix "aaaaa", append "5" followed by "a" to comp.
For prefix "bb", append "2" followed by "b" to comp.
 

Constraints:

1 <= word.length <= 2 * 105
word consists only of lowercase English letters.
*/

/*
Approach:
1. This function compresses a given string `word` by counting consecutive characters and storing the count alongside the character.
2. If the count of consecutive characters exceeds 9, it splits them into groups of '9' to maintain a compressed format.
3. We iterate over each character in the string:
   - If the character matches the previous character and `cnt` is less than 9, we increment the count.
   - If `cnt` reaches 9, we append '9' and the character to `ans`, then reset `cnt` to continue counting.
4. If a new character is encountered, append the previous character's count and character, reset `cnt`, and update `ch` to the new character.
5. After the loop, append the final character count and character.

Time Complexity: O(n), where `n` is the length of the string `word`, as each character is processed once.
Space Complexity: O(n), for storing the result string `ans`.
*/

class Solution {
public:
    string compressedString(string word) {
        char ch = word[0];
        int cnt = 1;
        int n = word.length();
        string ans = "";

        for (int i = 1; i < n; i++) {
            if (ch == word[i]) {
                if (cnt == 9) {
                    ans += "9" + string(1, ch); // Add '9' and the character when count reaches 9
                    cnt = 0;
                }
                cnt++;
            } else {
                // Append count and character for the previous group
                ans += to_string(cnt) + ch;
                cnt = 1;
                ch = word[i];
            }
        }
        
        // Append the last character and its count
        ans += to_string(cnt) + ch;

        return ans;
    }
};
