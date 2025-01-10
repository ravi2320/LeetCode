/*
916. Word Subsets
Solved
Medium
Topics
Companies
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
 

Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.
*/

/*
Approach:
1. Calculate the maximum frequency of each character across all words in `words2`.
   - Use a `freq` array of size 26 to store the maximum frequency of each character required.
2. For each word in `words1`, check if it satisfies the character frequency requirements stored in `freq`.
   - Use a helper function `isSubset` to verify if the word meets these requirements.
3. Collect all words from `words1` that satisfy the condition and return them as the result.

Intuition:
The problem requires checking if each word in `words1` is a universal word for `words2`. To efficiently check this:
- Compute the combined frequency requirements of all words in `words2`.
- Verify each word in `words1` against this frequency requirement.

Time Complexity:
1. Computing the `freq` array: \(O(m \cdot l)\), where \(m\) is the size of `words2` and \(l\) is the average length of words in `words2`.
2. Checking each word in `words1`: \(O(n \cdot k)\), where \(n\) is the size of `words1` and \(k\) is the average length of words in `words1`.
3. Overall: \(O(m \cdot l + n \cdot k)\).

Space Complexity:
1. `freq` and `temp` arrays: \(O(26)\), or \(O(1)\) in terms of input size.
2. Result vector `ans`: \(O(p)\), where \(p\) is the number of universal words in `words1`.

Edge Cases:
1. If either `words1` or `words2` is empty, return an empty result.
2. If all words in `words2` are empty, consider all words in `words1` as universal.

*/

class Solution {
public:
    // Helper function to check if all character frequencies in `freq` are satisfied by `temp`.
    bool isSubset(vector<int>& freq, vector<int>& temp) {
        for (int i = 0; i < 26; i++) {
            if (temp[i] < freq[i]) {
                return false; // If any required frequency is not met, return false
            }
        }
        return true; // Otherwise, return true
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0); // Maximum frequency requirements for all characters
        vector<string> ans;     // Result vector to store universal words

        // Step 1: Calculate the maximum frequency of each character across all words in `words2`
        for (string& word : words2) {
            vector<int> temp(26, 0); // Temporary frequency array for the current word
            for (char& x : word) {
                temp[x - 'a']++; // Increment the frequency for the current character
                freq[x - 'a'] = max(freq[x - 'a'], temp[x - 'a']); // Update the maximum frequency
            }
        }

        // Step 2: Check each word in `words1` against the frequency requirements in `freq`
        for (string& word : words1) {
            vector<int> temp(26, 0); // Frequency array for the current word in `words1`
            for (char& x : word) {
                temp[x - 'a']++; // Increment the frequency for the current character
            }

            // If the word satisfies the subset condition, add it to the result
            if (isSubset(freq, temp)) {
                ans.push_back(word);
            }
        }

        return ans; // Return the result
    }
};
