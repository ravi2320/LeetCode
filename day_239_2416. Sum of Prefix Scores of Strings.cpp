/*
2416. Sum of Prefix Scores of Strings
Solved
Hard
Topics
Companies
Hint
You are given an array words of size n consisting of non-empty strings.

We define the score of a string term as the number of strings words[i] such that term is a prefix of words[i].

For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

Note that a string is considered as a prefix of itself.

 

Example 1:

Input: words = ["abc","ab","bc","b"]
Output: [5,4,3,2]
Explanation: The answer for each string is the following:
- "abc" has 3 prefixes: "a", "ab", and "abc".
- There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
The total is answer[0] = 2 + 2 + 1 = 5.
- "ab" has 2 prefixes: "a" and "ab".
- There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
The total is answer[1] = 2 + 2 = 4.
- "bc" has 2 prefixes: "b" and "bc".
- There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
The total is answer[2] = 2 + 1 = 3.
- "b" has 1 prefix: "b".
- There are 2 strings with the prefix "b".
The total is answer[3] = 2.
Example 2:

Input: words = ["abcd"]
Output: [4]
Explanation:
"abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists of lowercase English letters.
*/

/*
 * Approach:
 * 1. Use a Trie (prefix tree) to store the count of words passing through each node (character).
 * 2. For each word, insert its characters into the Trie while incrementing the count for each node (character).
 * 3. To get the prefix score of a word, traverse the Trie and sum up the counts of each character node encountered.
 * 
 * Time Complexity:
 * - Insertion: O(L * n), where L is the average length of the words and n is the number of words.
 * - Query: O(L * n), as each word’s prefix score is calculated by traversing its length.
 * - Overall: O(L * n).
 * 
 * Space Complexity:
 * - O(L * n) for storing words in the Trie.
 */

struct TrieNode {
    int countP;               // Count of words passing through this node
    TrieNode* children[26];   // Array to store references to child nodes for each character
};

class Solution {
public:
    // Function to create a new Trie node
    TrieNode* getTrieNode() {
        TrieNode* node = new TrieNode();
        for(int i = 0; i < 26; i++) {
            node->children[i] = NULL;  // Initialize all children pointers to NULL
        }
        node->countP = 0;  // Initialize count of words passing through this node
        return node;
    }

    // Function to insert a word into the Trie
    void insert(string word, TrieNode* root) {
        TrieNode* crawl = root;  // Start from the root of the Trie

        // Traverse each character of the word
        for(char &ch : word) {
            int idx = ch - 'a';  // Calculate index (0 to 25) based on character

            // If the character node does not exist, create a new node
            if(!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();
            }

            crawl->children[idx]->countP += 1;  // Increment the count of this character node
            crawl = crawl->children[idx];       // Move to the next character node
        }
    }

    // Function to get the prefix score for a given word
    int getScore(string word, TrieNode* root) {
        TrieNode* crawl = root;  // Start from the root
        int score = 0;           // Initialize score to 0

        // Traverse each character of the word
        for(char &ch : word) {
            int idx = ch - 'a';           // Calculate index based on character
            score += crawl->children[idx]->countP;  // Add the count of this character node to the score
            crawl = crawl->children[idx]; // Move to the next node
        }

        return score;  // Return the total prefix score
    }

    // Main function to calculate prefix scores for all words
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = getTrieNode();  // Create the root of the Trie

        // Insert all words into the Trie
        for(string word : words) {
            insert(word, root);
        }

        vector<int> ans;  // Vector to store the prefix scores
        // Get the prefix score for each word
        for(string &word : words) {
            int res = getScore(word, root);
            ans.push_back(res);  // Append the score to the result vector
        }

        return ans;  // Return the vector of prefix scores
    }
};
