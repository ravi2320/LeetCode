/*
884. Uncommon Words from Two Sentences
Solved
Easy
Topics
Companies
A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
253.6K
Submissions
342.5K
Acceptance Rate
74.1%
*/

/*
Approach:
1. The problem involves finding words that appear exactly once in either of the two sentences.
2. We will split both strings (`s1` and `s2`) into words and keep track of their occurrences in a hashmap.
3. The function `findWordCnt` is used to process each sentence and populate the word count in the unordered map.
4. After processing both sentences, we iterate through the map and collect words that have appeared exactly once.

Time Complexity:
- O(n + m): Where `n` is the length of string `s1` and `m` is the length of string `s2`. Each character is processed once while building the word count, and we iterate through the map afterward.

Space Complexity:
- O(n + m): Space is required for the hashmap storing word frequencies, and space for the result vector containing uncommon words.

*/

class Solution {
public:
    // Helper function to count words from a sentence and store in the map
    void findWordCnt(string &s, unordered_map<string, int> &mp){
        int n = s.size();
        string word = "";
        
        // Loop through the string and extract words
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){         // When a space is encountered, add the word to the map
                if(!word.empty()) mp[word]++;
                word = "";           // Reset the word after counting it
            } else {
                word += s[i];        // Build the word character by character
            }
        }
        
        if(!word.empty()) mp[word]++;  // Add the last word (since no space follows the last word)
    }

    // Function to find uncommon words from two sentences
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

        // Count words from both sentences
        findWordCnt(s1, mp);
        findWordCnt(s2, mp);

        vector<string> ans;
        
        // Add words with count 1 to the result
        for(auto &itr : mp){
            if(itr.second == 1){     // If a word appears exactly once
                ans.push_back(itr.first);
            }
        }

        return ans;
    }
};
