/*
3330. Find the Original Typed String I

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.

You are given a string word, which represents the final output displayed on Alice's screen.

Return the total number of possible original strings that Alice might have intended to type.

 

Example 1:

Input: word = "abbcccc"

Output: 5

Explanation:

The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

Example 2:

Input: word = "abcd"

Output: 1

Explanation:

The only possible string is "abcd".

Example 3:

Input: word = "aaaa"

Output: 4

 

Constraints:

1 <= word.length <= 100
word consists only of lowercase English letters.
*/

/*
Approach:
We are given a string `word`, and we want to count the number of positions `i` (from 1 to n-1)
where the current character `word[i]` is the same as the previous character `word[i-1]`.
For each such repetition, we increment a counter `ans` starting from 1.

Intuition:
The counter starts at 1 (as the first character always contributes at least one "possible" string).
Each time we see a repeated character (same as the previous one), we consider that a new valid string could start here,
so we increment the count.

Time Complexity: O(n) — We iterate through the string once.
Space Complexity: O(1) — Only a few integer variables are used.
*/

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int ans = 1; // At least one possible string exists

        // Check each adjacent character
        for(int i = 1; i < n; i++) {
            if(word[i - 1] == word[i])
                ans++; // Count consecutive repeated characters
        }

        return ans;
    }
};