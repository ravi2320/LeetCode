/*
3136. Valid Word

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
 

Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.

 

Constraints:

1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.
*/

/*
Approach:
- Iterate through each character in the given word.
- Check if the character is either:
  1. A digit (0-9)
  2. A valid alphabet character (a-z or A-Z)
     - If it's a vowel, mark `isVowel = true`
     - Else (a consonant), mark `isConsonant = true`
  3. If the character is neither a digit nor alphabet, return false.

- Finally, a word is valid if:
  - It has at least one vowel and one consonant
  - Its length is at least 3

Intuition:
- The string should be a mix of letters and/or digits, with no special symbols.
- To be valid, it must contain **both** vowels and consonants and be of sufficient length.

Time Complexity: O(n) – iterate over all characters
Space Complexity: O(1) – constant extra space
*/

class Solution {
public:
    bool isValid(string word) {
        bool isVowel = false;
        bool isConsonant = false;

        for (char &ch : word) {
            // Check if the character is a letter
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                // Check if the character is a vowel
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                    isVowel = true;
                } else {
                    isConsonant = true;
                }
            }
            // Check if character is a digit
            else if (ch >= '0' && ch <= '9') {
                continue;
            }
            // If special character or symbol, return false
            else {
                return false;
            }
        }

        // Must contain at least one vowel, one consonant, and be at least length 3
        return isVowel && isConsonant && word.size() >= 3;
    }
};
