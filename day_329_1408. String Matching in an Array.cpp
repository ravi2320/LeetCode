/*
1408. String Matching in an Array
Solved
Easy
Topics
Companies
Hint
Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.
*/

/*
Approach:
1. Use two nested loops to compare every pair of strings in the input vector `words`.
2. For each pair `(i, j)` where `i != j`, check if `words[j]` is a substring of `words[i]` using `find()` function.
3. If `words[j]` is a substring of `words[i]`, store it in a `set` to avoid duplicates.
4. Convert the `set` to a vector and return it.

Intuition:
The task is to find all strings in the array that are substrings of another string in the same array. By comparing every string with every other string, we ensure all valid substrings are found. Using a `set` ensures no duplicates in the result.

Time Complexity:
- Outer loop: \(O(N)\), where \(N\) is the number of strings.
- Inner loop: \(O(N)\).
- Substring search (`find`): \(O(L1 * L2)\), where \(L1\) and \(L2\) are the lengths of the strings being compared.
Overall: \(O(N^2 \cdot L)\), where \(L\) is the average string length.

Space Complexity:
- The `set` for storing substrings: \(O(K)\), where \(K\) is the number of unique substrings.
- Result vector: \(O(K)\).
Overall: \(O(K)\).

*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> st;                    // Set to store unique substrings
        int n = words.size();              // Total number of strings

        // Compare each string with every other string
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;      // Skip comparing the string with itself

                // Check if `words[j]` is a substring of `words[i]`
                if (words[i].find(words[j]) != string::npos) {
                    st.insert(words[j]);   // Add to the set to ensure uniqueness
                }
            }
        }

        // Convert the set to a vector
        vector<string> res(st.begin(), st.end());
        return res;                        // Return the result
    }
};
