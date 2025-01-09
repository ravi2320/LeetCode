/*
2185. Counting Words With a Given Prefix
Solved
Easy
Topics
Companies
Hint
You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.
*/

/*
Approach:
1. Iterate through the list of words.
2. For each word, extract a substring of length equal to the prefix size `n` starting from index 0.
3. Compare the extracted substring with the given prefix.
4. If they match, increment the count.

Intuition:
The problem requires checking if each word starts with the specified prefix. Using the `substr` function, we can directly extract the prefix portion of each word and compare it to the given prefix. This ensures simplicity and clarity in the implementation.

Time Complexity:
- Let \(m\) be the average length of the words and \(k\) be the number of words.
- Extracting the prefix for a word is \(O(n)\), where \(n\) is the prefix length.
- Total complexity: \(O(k \cdot n)\).

Space Complexity:
- \(O(1)\), as no extra data structures are used, apart from the count variable.

Edge Cases:
1. If `words` is empty, return `0`.
2. If no word matches the prefix, return `0`.
3. If the prefix length exceeds the length of any word, handle it gracefully.

*/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(); // Length of the prefix
        int cnt = 0;         // Counter for words matching the prefix

        // Iterate over each word in the list
        for (string &word : words) {
            // Check if the prefix of the word matches `pref`
            if (word.substr(0, n) == pref) {
                cnt++; // Increment the counter
            }
        }

        return cnt; // Return the total count
    }
};