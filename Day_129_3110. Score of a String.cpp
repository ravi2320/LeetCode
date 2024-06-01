/*
3110. Score of a String
Solved
Easy
Topics
Companies
Hint
You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

Return the score of s.

 

Example 1:

Input: s = "hello"

Output: 13

Explanation:

The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

Example 2:

Input: s = "zaz"

Output: 50

Explanation:

The ASCII values of the characters in s are: 'z' = 122, 'a' = 97. So, the score of s would be |122 - 97| + |97 - 122| = 25 + 25 = 50.

 

Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.
*/

// Intuition:
// - We need to calculate the score of a string based on the absolute differences between the positions of adjacent characters in the alphabet.
// - The position of a character 'a' to 'z' can be found by subtracting 'a' from the character.
// - We iterate through the string and for each pair of adjacent characters, compute the absolute difference in their positions and sum it up.

// Time Complexity: O(N)
// - We iterate through the string once to calculate the score, which takes O(N) time where N is the length of the string.

// Space Complexity: O(1)
// - We use a constant amount of extra space regardless of the input size.

class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        int n = s.length();

        for (int i = 1; i < n; i++) {
            ans += abs((s[i-1] - 'a') - (s[i] - 'a'));
        }

        return ans;
    }
};
