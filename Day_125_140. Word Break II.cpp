/*
140. Word Break II
Solved
Hard
Topics
Companies
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 

Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.
*/

// Intuition:
// - We are given a string `s` and a dictionary `wordDict`. Our task is to break the string into valid words present in the dictionary.
// - We use backtracking to explore all possible ways to split the string and store the results in a vector.

// Time Complexity: O(N * 2^N), where N is the length of the input string `s`.
// - In the worst case, each character can start a new word, and we explore all possible combinations, leading to 2^N combinations.
// - Checking if a substring is in the set takes O(1), but the number of possible sentences can be exponential.

// Space Complexity: O(N * 2^N)
// - We store all valid sentences, and each sentence can have a length up to N.

class Solution {
public:
    vector<string> res; // To store the final results
    set<string> st;     // To store the dictionary words for quick lookup

    // Helper function to perform backtracking
    void solve(int i, string currSentence, string s) {
        if (i >= s.length()) {
            res.push_back(currSentence);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            string tempWord = s.substr(i, j - i + 1); // Extract the substring from i to j
            if (st.count(tempWord)) { // Check if the extracted substring is in the dictionary
                string tempSentence = currSentence; // Save the current sentence state
                if (!currSentence.empty()) {
                    currSentence += " "; // Add a space if the sentence is not empty
                }
                currSentence += tempWord; // Append the valid word to the current sentence

                solve(j + 1, currSentence, s); // Recur for the remaining substring

                currSentence = tempSentence; // Backtrack to the previous state
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string &word : wordDict) {
            st.insert(word); // Insert all dictionary words into the set
        }    
        string currSentence = "";
        solve(0, currSentence, s); // Start backtracking from the beginning of the string

        return res; // Return the list of all possible sentences
    }
};
