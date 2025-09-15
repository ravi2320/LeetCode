/*
1935. Maximum Number of Words You Can Type

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

 

Example 1:

Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.
Example 2:

Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
Example 3:

Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.
 

Constraints:

1 <= text.length <= 104
0 <= brokenLetters.length <= 26
text consists of words separated by a single space without any leading or trailing spaces.
Each word only consists of lowercase English letters.
brokenLetters consists of distinct lowercase English letters.
*/

/*
Approach:
1. Build a frequency map (array of size 26) for the broken letters.
2. Traverse each word in the text:
   - For each character, check if it belongs to the broken letters set.
   - If yes, mark the word as not typable.
   - If no broken letter is encountered, count the word as typable.
3. Return the total count of typable words.

Intuition:
- A word is valid only if none of its letters are broken.
- By pre-storing broken letters in a frequency array, we can quickly check validity for each character.

Time Complexity:
- O(n + m), where n = length of text, m = length of brokenLetters.
- Each character is checked once.

Space Complexity:
- O(26) ≈ O(1), fixed space for the frequency array.

*/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Frequency array for broken letters
        vector<int> freq(26, 0);
        for (char &x : brokenLetters) {
            freq[x - 'a']++;
        }

        int n = text.size();
        int i = 0, cnt = 0;

        // Traverse through each word in the text
        while (i < n) {
            bool canType = true;

            // Check each character of the word
            while (i < n && text[i] != ' ') {
                if (freq[text[i] - 'a']) {
                    canType = false; // Broken letter found
                }
                i++;
            }

            i++; // Skip space

            // If no broken letters in this word, count it
            if (canType) {
                cnt++;
            }
        }

        return cnt;
    }
};
