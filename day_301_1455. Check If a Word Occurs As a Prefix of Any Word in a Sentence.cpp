/*
1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
Solved
Easy
Topics
Companies
Hint
Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.
*/

/*
Approach:
1. Traverse the sentence while keeping track of:
   - **`wordCnt`**: The current word number (incremented on encountering spaces).
   - **`j`**: Pointer for comparing characters in `searchWord`.
   - **`wordStart`**: A flag indicating whether we are at the start of a word.

2. For each character in the sentence:
   - Compare it with the `j-th` character of `searchWord` if `wordStart` is `true`.
   - Reset `j` and `wordStart` if there is a mismatch or if a space is encountered.

3. If all characters of `searchWord` match a prefix of a word in the sentence (`j == searchWord.length()`), return `wordCnt`.

4. If no such word is found, return `-1`.

Time Complexity:
- **O(n)**: Iterate through each character of the sentence once.

Space Complexity:
- **O(1)**: No additional data structures used.

*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordCnt = 1;  // Word counter starts at the first word
        int n = sentence.length(), m = searchWord.length();
        int j = 0;        // Pointer for searchWord
        bool wordStart = true; // Tracks if currently at the start of a word

        // Iterate through each character in the sentence
        for (int i = 0; i < n; i++) {
            // Check if current character matches searchWord[j]
            if (searchWord[j] == sentence[i] && wordStart) {
                j++;  // Move to the next character of searchWord
            } else {
                // Reset comparison on mismatch
                j = 0;
                wordStart = false;
            }

            // Check for space (end of a word)
            if (sentence[i] == ' ') {
                wordStart = true; // Next character starts a new word
                wordCnt++;        // Increment word count
            }

            // If full searchWord is found as prefix, return current word count
            if (m == j) {
                return wordCnt;
            }
        }

        // If no prefix match is found
        return -1;
    }
};
