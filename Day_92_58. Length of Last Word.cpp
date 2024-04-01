/*
58. Length of Last Word
Solved
Easy
Topics
Companies
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

/*
Intuition:
- We start by finding the index of the last non-space character in the string.
- Then, we iterate backward from this index to count the length of the last word, stopping when we encounter a space or reach the beginning of the string.
- Finally, we return the length of the last word.

Time Complexity: O(N)
- We iterate through the string once to find the index of the last non-space character and then iterate backward to count the length of the last word. Therefore, the time complexity is linear with respect to the length of the input string.

Space Complexity: O(1)
- We use only a constant amount of extra space for storing variables, so the space complexity is constant.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int end = len - 1;
        
        // Trim trailing spaces
        while(end >= 0 && s[end] == ' ') {
            end--;
        }

        int lastWordLength = 0;

        // Count the length of the last word
        for(int i = end; i >= 0 && s[i] != ' '; i--) {
            lastWordLength++;
        }

        return lastWordLength;
    }
};


/*
Intuition:
- We start iterating from the end of the string.
- We encounter non-space characters, indicating the beginning of the last word. We start counting the length of this word.
- Once we encounter a space character after encountering non-space characters, we stop counting.
- We return the length of the last word.

Time Complexity: O(N)
- We iterate through the string once, so the time complexity is linear with respect to the length of the input string.

Space Complexity: O(1)
- We use only a constant amount of extra space for storing variables, so the space complexity is constant.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool count = false; // Flag to indicate if we are currently counting the length of the last word

        int lastWordLength = 0;

        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] != ' ') {
                count = true; // Start counting the length of the last word
                lastWordLength++;
            } else if(count) {
                break; // Stop counting if we encounter a space after encountering non-space characters
            }
        }

        return lastWordLength;
    }
};