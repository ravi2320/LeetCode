/*
648. Replace Words
Solved
Medium
Topics
Companies
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/

/*
Intuition:
- The task is to replace words in a sentence with the shortest possible root form found in a dictionary. 
- We can use a set for efficient lookup of dictionary words (roots).
- For each word in the sentence, we check from the beginning to find the shortest prefix that exists in the dictionary and replace the word with this root.
- Using `stringstream`, we can easily split the sentence into words and process each word.

Approach:
1. Insert all dictionary words into an unordered_set for O(1) average-time complexity lookups.
2. For each word in the sentence, attempt to find the shortest root by progressively checking substrings starting from the first character.
3. If a root is found in the set, replace the word with this root; otherwise, keep the word as is.
4. Construct the final sentence by combining the processed words.

Time Complexity: O(L), where L is the total length of the sentence.
- Building the set takes O(D) time, where D is the sum of lengths of all dictionary words.
- Processing each word in the sentence involves checking each prefix, making it O(L) for the entire sentence.

Space Complexity: O(D)
- We use an unordered_set to store dictionary words, where D is the total length of all dictionary words.
*/

class Solution {
public:
    // Function to find the shortest root in the dictionary for a given word
    string getRoot(unordered_set<string>& st, string& word) {
        for (int i = 1; i <= word.length(); i++) {
            string root = word.substr(0, i);
            if (st.find(root) != st.end()) {
                return root;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        // Build an unordered_set for quick lookups
        unordered_set<string> st(begin(dictionary), end(dictionary));
        stringstream ss(sentence); // For splitting the sentence into words
        string word;
        string res;

        // Process each word in the sentence
        while (getline(ss, word, ' ')) {
            // Append the shortest root or the original word if no root is found
            res += getRoot(st, word) + ' ';
        }

        res.pop_back(); // Remove the trailing space
        return res;
    }
};
