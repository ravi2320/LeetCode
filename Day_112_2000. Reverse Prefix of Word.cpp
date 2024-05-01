/*
2000. Reverse Prefix of Word
Solved
Easy
Topics
Companies
Hint
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

 

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
 

Constraints:

1 <= word.length <= 250
word consists of lowercase English letters.
ch is a lowercase English letter.
*/

// Intuition:
// This function reverses the prefix of a string up to the first occurrence of a given character 'ch'.
// It iterates through the string to find the index of the first occurrence of 'ch'.
// Then, it uses two pointers approach to reverse the characters in the prefix up to that index.

// Time Complexity: O(N)
// - 'N' is the length of the input string 'word'.
// - The algorithm iterates through the string once.

// Space Complexity: O(1)
// - The algorithm uses constant extra space.

#include <string>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j, i = 0; // Initialize two pointers i and j
        for (j = 0; j < word.length(); j++) {
            if (word[j] == ch) {
                // Reverse the prefix of the string up to the first occurrence of 'ch'
                while (i < j) {
                    swap(word[i], word[j]); // Swap characters at indices i and j
                    i++; // Move pointer i to the right
                    j--; // Move pointer j to the left
                }
                break; // Exit the loop once the prefix is reversed
            }
        }
        return word; // Return the modified string
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string word = "abcdefg";
    char ch = 'd';
    string result = obj.reversePrefix(word, ch);
    cout << "Reversed prefix string: " << result << endl; // Output: Reversed prefix string: dcbaefg
    return 0;
}



// Intuition:
// This function finds the index of the first occurrence of the character 'ch' in the string 'word'.
// Then, it reverses the prefix of the string up to that index using the reverse function.

// Time Complexity: O(N)
// - 'N' is the length of the input string 'word'.
// - The find operation takes O(N) time, and the reverse operation also takes O(N) time.

// Space Complexity: O(1)
// - The algorithm uses constant extra space.

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Find the index of the first occurrence of 'ch' in 'word'
        int j = word.find(ch);

        // Reverse the prefix of the string up to the index of 'ch'
        reverse(word.begin(), word.begin() + j + 1);

        // Return the modified string
        return word;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string word = "abcdefg";
    char ch = 'd';
    string result = obj.reversePrefix(word, ch);
    cout << "Reversed prefix string: " << result << endl; // Output: Reversed prefix string: dcbaefg
    return 0;
}
