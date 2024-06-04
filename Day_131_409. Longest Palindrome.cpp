/*
409. Longest Palindrome
Solved
Easy
Topics
Companies
Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/

// Intuition:
// - The problem involves finding the length of the longest palindrome that can be built using the characters of the given string `s`.
// - A palindrome reads the same forward and backward, so each character must appear an even number of times to be paired.
// - If there are any characters with odd counts, one of them can be placed in the middle of the palindrome.

// Approach:
// - Use an unordered set to track characters that appear an odd number of times.
// - Traverse the string, adding each character to the set if it is not already present, and removing it if it is (indicating it now appears an even number of times).
// - Each time a character is removed from the set, increment the length of the palindrome by 2.
// - After processing all characters, if there are any characters left in the set (indicating an odd count), we can add one more character to the middle of the palindrome.

// Time Complexity: O(n)
// - The algorithm iterates through the string once, performing constant-time operations on the set.

// Space Complexity: O(1)
// - The maximum size of the set is limited by the number of unique characters (constant, 26 for lowercase English letters).

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int len = 0;

        for (char ch : s) {
            if (st.find(ch) != st.end()) {
                len += 2;
                st.erase(ch);
            } else {
                st.insert(ch);
            }
        }

        return !st.empty() ? len + 1 : len;
    }
};
