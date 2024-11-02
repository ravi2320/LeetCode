/*
2490. Circular Sentence
Solved
Easy
Topics
Companies
Hint
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

A sentence is circular if:

The last character of a word is equal to the first character of the next word.
The last character of the last word is equal to the first character of the first word.
For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

Given a string sentence, return true if it is circular. Otherwise, return false.

 

Example 1:

Input: sentence = "leetcode exercises sound delightful"
Output: true
Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode's last character is equal to exercises's first character.
- exercises's last character is equal to sound's first character.
- sound's last character is equal to delightful's first character.
- delightful's last character is equal to leetcode's first character.
The sentence is circular.
Example 2:

Input: sentence = "eetcode"
Output: true
Explanation: The words in sentence are ["eetcode"].
- eetcode's last character is equal to eetcode's first character.
The sentence is circular.
Example 3:

Input: sentence = "Leetcode is cool"
Output: false
Explanation: The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode's last character is not equal to is's first character.
The sentence is not circular.
 

Constraints:

1 <= sentence.length <= 500
sentence consist of only lowercase and uppercase English letters and spaces.
The words in sentence are separated by a single space.
There are no leading or trailing spaces.
*/

/*
Approach:
1. Check if the first and last characters of the string `s` are the same, as the sentence needs to be circular.
   - If they are not the same, return false.
2. Traverse through each character in `s`:
   - If a space character is found (indicating a word boundary), verify if the last character of the previous word matches the first character of the next word.
   - If they do not match, return false.
3. If all word boundaries are satisfied and the sentence starts and ends with the same character, return true.

Time Complexity: O(n), where `n` is the length of the string `s`.
Space Complexity: O(1), as only a constant amount of extra space is used.
*/

class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.length();
        
        // Check if first and last character are the same
        if (s[0] != s[n - 1]) return false;

        // Traverse the string to check all word boundaries
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == ' ' && s[i - 1] != s[i + 1]) {
                return false;  // Boundary check fails if characters do not match
            }
        }

        return true;
    }
};
