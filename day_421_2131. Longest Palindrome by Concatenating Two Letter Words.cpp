/*
2131. Longest Palindrome by Concatenating Two Letter Words
Solved
Medium
Topics
Companies
Hint
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

Constraints:

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.
*/

/*
Approach:
- Use a hash map to count occurrences of each 2-letter word.
- For each word, check if its reverse exists in the map.
  - If yes, form a palindrome pair and add 4 to the total length.
  - Decrease the count of the reverse word.
- After pairing all reversible words, check if any word has both characters equal (e.g., "aa", "bb").
  - If such a word exists and has a remaining count, place one in the center, adding 2 to the length.

Intuition:
- Palindromes can be built symmetrically using word-reverse pairs like ("ab", "ba").
- A single symmetrical word like "aa" can serve as the center of the palindrome.

Time Complexity: O(N), where N is the number of words  
Space Complexity: O(N), for storing the word counts
*/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;  // Map to store frequency of each word
        int len = 0;                    // Resultant palindrome length

        // Step 1: Form palindrome pairs
        for (auto word : words) {
            string revWord = word;
            swap(revWord[0], revWord[1]); // Reverse the 2-letter word

            // If reverse exists, form a pair and update length
            if (mp[revWord] > 0) {
                len += 4;          // Each pair adds 4 to length
                mp[revWord]--;     // Use one occurrence of the reverse
            } else {
                mp[word]++;        // Store the current word for future pairing
            }
        }

        // Step 2: Check if a same-letter word like "aa" is left to place in center
        for (auto &itr : mp) {
            string word = itr.first;
            int cnt = itr.second;

            // If a same-letter word remains, it can go in the center
            if (word[0] == word[1] && cnt > 0) {
                len += 2;  // Add 2 to the length for central placement
                break;     // Only one such word can be in the center
            }
        }

        return len;  // Final palindrome length
    }
};
