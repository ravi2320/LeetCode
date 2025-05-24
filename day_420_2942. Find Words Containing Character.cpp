/*
2942. Find Words Containing Character
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.

 

Example 1:

Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.
Example 2:

Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
Output: [0,2]
Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.
Example 3:

Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
Output: []
Explanation: "z" does not occur in any of the words. Hence, we return an empty array.
 

Constraints:

1 <= words.length <= 50
1 <= words[i].length <= 50
x is a lowercase English letter.
words[i] consists only of lowercase English letters.
*/

/*
Approach:
- Iterate through each word in the input list `words`.
- For each word, check if it contains the character `x`.
- If it does, store the index of that word in the result vector.

Intuition:
- We want to collect the indices of all words that contain the target character `x`.
- We check each word character-by-character and stop at the first match to avoid unnecessary comparisons.

Time Complexity: O(N * L)
    where N = number of words, L = average length of each word  
Space Complexity: O(K)
    where K = number of matching indices stored in the result vector
*/

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();          // Total number of words
        vector<int> res;               // Result vector to store matching indices

        // Iterate through each word
        for (int i = 0; i < n; i++) {
            // Check if the current word contains the character x
            for (char &ch : words[i]) {
                if (ch == x) {
                    res.push_back(i);  // Store index if match is found
                    break;             // No need to check further characters
                }
            }
        }

        return res; // Return all matching indices
    }
};
