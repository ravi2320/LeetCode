/*
1002. Find Common Characters
Solved
Easy
Topics
Companies
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
*/

// Intuition:
// - To find the common characters among a list of words.
// - We maintain a frequency array for the characters in the first word.
// - For each subsequent word, we update the frequency array to contain the minimum frequencies of characters.
// - Finally, we construct the result vector based on the minimum frequencies.

// Approach:
// - Create a function `fillFreq` to fill the frequency array for a given word.
// - Initialize a frequency array `freq` with zeros.
// - Fill the frequency array with the characters of the first word using `fillFreq`.
// - For each subsequent word, update the frequency array with the minimum frequencies using another temporary frequency array.
// - Construct the result vector `res` by iterating through the frequency array and adding characters based on their frequencies.

// Time Complexity: O(N * M), where N is the number of words and M is the average length of a word.
// - We iterate through each word and each character in the words.

// Space Complexity: O(1) since the size of the frequency array is fixed at 26, regardless of the input size.

class Solution {
public:
    // Function to fill the frequency array for a given word
    void fillFreq(string word, vector<int> &freq) {
        for (char ch : word) {
            freq[ch - 'a']++;
        }
    }
    
    // Function to find common characters among a list of words
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        
        // Initialize a frequency array to store the minimum frequency of each character
        vector<int> freq(26, 0);
        
        // Fill the frequency array with the characters of the first word
        fillFreq(words[0], freq);
        
        // Iterate through each subsequent word
        for (int i = 1; i < words.size(); i++) {
            // Temporary frequency array for the current word
            vector<int> temp(26, 0);
            
            // Fill the temporary frequency array
            fillFreq(words[i], temp);
            
            // Update the frequency array to contain the minimum frequencies
            for (int j = 0; j < 26; j++) {
                freq[j] = min(freq[j], temp[j]);
            }
        }

        // Construct the result vector based on the minimum frequencies
        for (int i = 0; i < 26; i++) {
            int c = freq[i];
            while (c--) {
                res.push_back(string(1, i + 'a'));
            }
        }

        return res;
    }
};
